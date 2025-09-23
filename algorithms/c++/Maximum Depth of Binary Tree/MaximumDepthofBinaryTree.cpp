// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : Min Fang
// Date   : 2025-09-23

/**********************************************************************************
*
* Problem: Maximum Depth of Binary Tree
*
* Given the root of a binary tree, return its maximum depth.
*
* A binary tree's maximum depth is the number of nodes along the longest path
* from the root node down to the farthest leaf node.
*
* Example 1:
*   Input: root = [3,9,20,null,null,15,7]
*   Output: 3
*   Explanation:
*     The longest path is either 3->9 or 3->20->15 (or 3->20->7).
*     The maximum depth is 3.
*
* Example 2:
*   Input: root = [1,null,2]
*   Output: 2
*   Explanation:
*     The longest path is 1->2.
*
*
* Constraints:
*   - The number of nodes in the tree is in the range [0, 10^4].
*   - -100 <= Node.val <= 100
*
*
* Approach: Recursive Depth-First Search (DFS)
*
* - The maximum depth of a binary tree can be found by recursively exploring
*   the left and right subtrees.
* - For each node, the max depth is 1 plus the maximum depth of its left and right children.
* - Base case: if the node is null, return 0 (depth is zero).
* - Recursively compute left and right depths, then take their maximum.
*
* Steps:
*   1. Check if the current node is null. If yes, return 0.
*   2. Recursively call maxDepth on the left child to get left depth.
*   3. Recursively call maxDepth on the right child to get right depth.
*   4. Return max(left_depth, right_depth) + 1.
*
*
* Time Complexity: O(n)
*   - Visits each node once.
*
* Space Complexity: O(h)
*   - Recursive call stack, where h is the height of the tree.
*
**********************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int lefts = 0;
        int rights = 0;
        lefts = maxDepth(root->left);
        rights = maxDepth(root->right);
        return max(lefts,rights)+1;
    }
};
