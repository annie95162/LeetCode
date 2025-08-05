// Source : https://leetcode.com/problems/implement-queue-using-stacks/
// Author : Min Fang
// Date   : 2025-08-05

/**********************************************************************************
 *
 * Problem:
 * Implement a queue using two stacks.
 * The queue should support standard operations: push, pop, peek, and empty.
 *
 * Constraints:
 * - Only standard stack operations allowed: push, pop, top, size, empty
 * - Must simulate FIFO behavior (First-In-First-Out)
 * - All peek/pop calls are valid
 *
 * Example:
 *   Input:
 *     ["MyQueue", "push", "push", "peek", "pop", "empty"]
 *     [[],        [1],    [2],    [],      [],    []]
 *   Output:
 *     [null,      null,   null,   1,       1,     false]
 *
 *
 * Approach (Two-Stack Queue Simulation):
 * --------------------------------------
 * Use two stacks:
 * - `instack`: stores newly pushed elements
 * - `outstack`: used for popping and peeking elements in queue order
 *
 * Core idea:
 * - Elements are always added to `instack`.
 * - Before any pop/peek/empty, move elements from `instack` to `outstack`
 *   (only if `outstack` is empty) to reverse their order.
 *   This ensures that the oldest element is always at the top of `outstack`,
 *   simulating queue front.
 *
 * push(x):
 * - Before pushing, call `reverse()` to keep queue order consistent.
 * - Then push x into `instack`.
 *
 * pop():
 * - Ensure `outstack` is up-to-date by calling `reverse()`.
 * - Return and remove top element of `outstack`.
 *
 * peek():
 * - Ensure `outstack` is up-to-date by calling `reverse()`.
 * - Return top element of `outstack`.
 *
 * empty():
 * - Call `reverse()` to make sure all elements are in `outstack`.
 * - Check whether `outstack` is empty.
 *
 *
 * Time Complexity:
 * - push(x): O(n) worst-case (due to reverse), but not amortized optimal. Average O(1).
 * - pop(): Amortized O(1)
 * - peek(): Amortized O(1)
 * - empty(): Amortized O(1)
 *
 * Note:
 * - In this implementation, `push` calls `reverse()` each time,
 *   which may cause unnecessary stack transfers and degrade performance.
 * - Optimal approach: Only call `reverse()` during pop/peek/empty,
 *   and allow `push()` to always push directly to `instack`.
 *
 **********************************************************************************/

class MyQueue {

private:
    stack<int> instack;
    stack<int> outstack;

    void reverse(){
        if(outstack.empty()){
            while(!instack.empty()){
                int temp = instack.top();
                outstack.push(temp);
                instack.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        reverse();
        instack.push(x);
    }
    
    int pop() {
        reverse();
        int p = outstack.top();
        outstack.pop();
        return p;
    }
    
    int peek() {
        reverse();
        return outstack.top();
    }
    
    bool empty() {
        reverse();
        return outstack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
