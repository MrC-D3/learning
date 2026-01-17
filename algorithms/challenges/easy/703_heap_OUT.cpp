// Time: (estimated) 15. OUT.
// Write a class that always the return the kth greatest value.
// Constraints: nums.size in [0, 10^4]; k in [1, nums.size + 1]; val in 
//  [-10^4, 10^4]; at most 10^4 calls to add().

#include <vector>
#include <queue>

using namespace std;


// The canonical solution (with STL).
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) 
      : m_k{k}{
        for (auto n : nums)
            (void) add(n);
    }
    
    int add(int val) {
        if (m_min_heap.size() < m_k)
            m_min_heap.push(val);
        else
        {
            // Here if size == m_k.
            if (val > m_min_heap.top())
            {
                m_min_heap.push(val);
                m_min_heap.pop();
            }
        }

        return m_min_heap.top();
    }

private:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> m_min_heap;
};

// K + Nlog(k).
class KthLargest_v0 {
public:
    KthLargest(int k, vector<int>& nums) 
      : m_k{k}, m_max_heap{nullptr}, m_counter_till_k{0}{
        for (int i = 0; i < nums.size(); i++)
            (void) add(nums[i]);
    }
    
    int add(int val) {
        if (!m_max_heap)
        {
            m_max_heap = new TreeNode(val);
            m_counter_till_k++;
            return val;
        }

        // Here if at least a value already in the heap.
        if (val < m_max_heap->val)
        {
            // If val<root and not already k values, new root and old one will
            //  be inserted on right subtree.
            if (m_counter_till_k < m_k)
                swap(val, m_max_heap->val);
            // Otherwise, you can forget it.
            else
                return m_max_heap->val;
        }
        
        // Here to insert the old root or a val>=root.
        insert_to_heap(val, &(m_max_heap->right));

        if (m_counter_till_k < m_k)
            m_counter_till_k++;
        else // Here only when also val>=root, so at least 2 values in the heap.
            heapify();

        return m_max_heap->val;
    }

//private:
    void insert_to_heap(int n, TreeNode** root)
    {
        if (!(*root))
        {
            *root = new TreeNode(n);
            return;
        }

        TreeNode* it = *root;
        if (n < it->val)
            insert_to_heap(n, &(it->left));
        else
            insert_to_heap(n, &(it->right));
    }

    void heapify()
    {
        // Called only when at least 2 elements, so when m_max_heap not nullptr.
        if (!(m_max_heap->right))
            throw runtime_error("Call heapify() only if at least 2 elements.");

        // Find the parent of the smallest value in ->right.
        auto it = m_max_heap->right;
        if (it->left)
        {
            while (it->left->left)
                it = it->left;
        }
        else // Corner case: m_max_heap->right stores the smallest value.
        {
            // Make m_max_heap->left point to m_max_heap->right.
            m_max_heap->left = m_max_heap->right;
            it = m_max_heap;
        }

        // Swap the smallest value with the root value.
        swap(m_max_heap->val, it->left->val);

        // Promote the right child of the node to delete.
        auto to_delete = it->left;
        // If in the corner case.
        if (it->left == it->right)
        {
            it->right = it->right->right;
        }
        it->left = it->left->right;

        // Delete the node.
        delete to_delete;
    }

    int m_k;
    TreeNode* m_max_heap;
    int m_counter_till_k;
};