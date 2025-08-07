// Source : https://leetcode.com/problems/min-stack/
// Author : Min Fang
// Date   : 2025-08-07

/**********************************************************************************
*
* Problem:
* Design a stack that supports the following operations in constant time:
* - push(val): Push an integer `val` onto the stack.
* - pop(): Remove the element on top of the stack.
* - top(): Return the top element of the stack.
* - getMin(): Retrieve the minimum element in the stack.
*
* Example:
*   Input:
*     ["MinStack","push","push","push","getMin","pop","top","getMin"]
*     [[],[-2],[0],[-3],[],[],[],[]]
*
*   Output:
*     [null,null,null,null,-3,null,0,-2]
*
*   Explanation:
*     MinStack minStack = new MinStack();
*     minStack.push(-2);
*     minStack.push(0);
*     minStack.push(-3);
*     minStack.getMin(); // return -3
*     minStack.pop();
*     minStack.top();    // return 0
*     minStack.getMin(); // return -2
*
*
* Constraints:
* - -2^31 <= val <= 2^31 - 1
* - All pop(), top(), and getMin() operations will only be called on non-empty stacks.
* - At most 3 * 10^4 calls will be made to all operations.
*
*
* Approach:
*
* - Use two stacks:
*   1. `s`: to store the actual elements.
*   2. `s2`: to keep track of the minimum element at each level of the stack.
*
* - Initialize `s2` with `INT_MAX` to ensure valid comparisons when the first element is pushed.
*
* - For push(val):
*     1. Push `val` to the main stack `s`.
*     2. Push `min(val, s2.top())` to the min stack `s2` to maintain the current minimum.
*
* - For pop():
*     - Pop the top element from both stacks to keep them aligned.
*
* - For top():
*     - Return `s.top()` which represents the current top of the main stack.
*
* - For getMin():
*     - Return `s2.top()` which holds the current minimum of the stack.
*
*
* Time Complexity: O(1)
* - Each operation (push, pop, top, getMin) is done in constant time.
*
* Space Complexity: O(n)
* - In the worst case, both stacks hold `n` elements, where `n` is the total number of push operations.
*
*
* ✅ Notes:
* - By mirroring the stack with a second stack for minimum values,
*   we ensure that getMin() is always a simple and efficient O(1) operation.
* - This is a well-known and optimal method for tracking the minimum element in a stack.
*
**********************************************************************************/
class MinStack {
private:
    stack<int> s;
    stack<int> s2;

public:
    MinStack() {
        s2.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        int t = min(s2.top(), val);
        s2.push(t);
    }
    
    void pop() {
        s.pop();
        s2.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
