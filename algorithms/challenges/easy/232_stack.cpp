// Time 20m.
// Implement a FIFO (push, peek, pop, empty) using only 2 stacks (push, peek, 
//  pop, size, empty) and ensuring each operation has O(1) amortized cost.
// Constraints: all pop/peek calls are valid; at most 100 calls overall.

#include <stack>

using namespace std;

// Only 2 stacks: IN and OUT: once an element is in OUT, stay there.
// Works because new elements in IN moves only if OUT is empty.
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
        return out_stack.top(); // Done anyway: if IN initially empty or not.
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }

private:
    stack<int> in_stack;
    stack<int> out_stack;
};
