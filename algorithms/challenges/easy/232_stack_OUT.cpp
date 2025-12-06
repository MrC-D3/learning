// Time 20m. OUT.
// Implement a FIFO (push, peek, pop, empty) using only 2 stacks (push, peek, 
//  pop, size, empty) and ensuring each operation has O(1) amortized cost.
// Constraints: all pop/peek calls are valid; at most 100 calls overall.

#include <stack>

using namespace std;

// Only 2 stacks: IN and OUT.
// Better because once an element is in OUT, stay there.
// Works because new elements in IN aren't touch until elements in OUT.
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        auto x = peek();
        out_stack.pop();
        
        return x;
    }
    
    int peek() {
        if (out_stack.empty())
        {
            while (!in_stack.empty())
            {
                out_stack.push( in_stack.top() );
                in_stack.pop();
            }
        }
        return out_stack.top();
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }

private:
    stack<int> in_stack;
    stack<int> out_stack;
};

class MyQueue_v0 {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (use_1)
        {
            stack1.push(x);
        }
        else
        {
            while (!stack2.empty())
            {
                stack1.push( stack2.top() );
                stack2.pop();
            }
            stack1.push(x);
            use_1 = true;
        }
    }
    
    int pop() {
        auto x = peek();
        stack2.pop();
        
        return x;
    }
    
    int peek() {
        if (use_1)
        {
            int first;
            while( !stack1.empty() )
            {
                first = stack1.top();
                stack2.push( first );
                stack1.pop();
            }
            use_1 = false;
            return first;
        }
        return stack2.top();
    }
    
    bool empty() {
        if (use_1)
        {
            return stack1.empty();
        }
        return stack2.empty();
    }

private:
    stack<int> stack1; // Last element is the first.
    stack<int> stack2; // First element is the first.
    bool use_1{true};
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */