/**********************************************************************************
 *
 * Problem:
 * Implement a stack (LIFO) using only two queues (FIFO).
 * Must support standard stack operations: push, pop, top, and empty.
 * Only standard queue operations are allowed: push to back, pop/peek from front, size, and empty.
 *
 * Constraints:
 * - At most 100 calls will be made to push, pop, top, and empty.
 * - All calls to pop and top are valid (stack is non-empty when called).
 *
 *
 * Approach (Two-Queue with Costly Push):
 * --------------------------------------
 * Use two queues: `q1` (main stack) and `q2` (temporary buffer).
 *
 * Core idea:
 * - To simulate LIFO, ensure the newest element is always at the **front** of q1.
 * - When pushing a new element `x`:
 *     - Insert `x` into empty q2.
 *     - Move all elements from q1 into q2 (preserving insertion order).
 *     - Swap q1 and q2 so that q1 has the correct stack order (newest at front).
 *
 *   After each `push`, q1.front() is always the top of the stack.
 *
 *
 * Function Breakdown:
 * -------------------
 * reverse(int t):
 *   - Helper function called by `push()`.
 *   - Pushes t into q2, then moves all of q1 into q2.
 *   - Swaps q1 and q2 so q1 becomes the new stack.
 *
 * push(x):
 *   - Calls `reverse(x)` to simulate LIFO ordering.
 *
 * pop():
 *   - Returns and removes the front element of q1 (the stack's top).
 *
 * top():
 *   - Returns the front element of q1 without removing it.
 *
 * empty():
 *   - Returns whether q1 is empty.
 *
 *
 * Time Complexity:
 * ----------------
 * - push(x): O(n), due to transferring all elements from q1 to q2
 * - pop():  O(1)
 * - top():  O(1)
 * - empty(): O(1)
 *
 * Space Complexity:
 * - O(n), for storing n elements across two queues
 *
 *
 * Summary:
 * - This is a classic simulation of a stack using two queues.
 * - Chooses to make `push` expensive in order to keep `pop` and `top` O(1).
 * - Guarantees correct LIFO behavior by rotating elements after each push.
 *
 **********************************************************************************/

