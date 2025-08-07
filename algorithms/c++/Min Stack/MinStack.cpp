// Source : https://leetcode.com/problems/min-stack/
// Author : Min Fang
// Date   : 2025-08-07

/**********************************************************************************
 *
 * Problem:
 * --------
 * Design a stack that supports the following operations in constant time:
 * - push(val): Pushes the element onto the stack.
 * - pop(): Removes the top element of the stack.
 * - top(): Returns the top element.
 * - getMin(): Returns the minimum element in the stack.
 *
 *
 * Goal:
 * -----
 * Implement all four methods with O(1) time complexity.
 *
 *
 * Approach:
 * ---------
 * Use two stacks:
 * - `s`: the main stack to store all values.
 * - `s2`: an auxiliary stack to store the current minimum at each level of the main stack.
 *
 *
 * Step-by-step Logic:
 * -------------------
 * - On initialization:
 *     - Push `INT_MAX` into `s2` to serve as a sentinel for comparisons.
 *
 * - When calling `push(val)`:
 *     - Push `val` into the main stack `s`.
 *     - Push the smaller value between `val` and `s2.top()` into `s2`.
 *       This ensures `s2.top()` always reflects the current minimum.
 *
 * - When calling `pop()`:
 *     - Pop the top elements from both `s` and `s2` to maintain their alignment.
 *
 * - When calling `top()`:
 *     - Return `s.top()`, the most recently pushed value.
 *
 * - When calling `getMin()`:
 *     - Return `s2.top()`, which always holds the minimum element in the current stack state.
 *
 *
 * Time Complexity:
 * ----------------
 * - O(1) for all operations: push, pop, top, and getMin.
 *
 * Space Complexity:
 * -----------------
 * - O(n), where n is the number of elements in the stack.
 *   Both stacks grow linearly with the number of pushes.
 *
 *
 * Notes:
 * ------
 * - By mirroring the main stack with a min-tracking stack,
 *   we avoid the need to scan the entire stack to find the minimum.
 * - This approach is efficient and commonly used for implementing a min-stack.
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
