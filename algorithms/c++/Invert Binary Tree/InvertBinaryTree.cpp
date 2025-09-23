// Source : https://leetcode.com/problems/invert-binary-tree/
// Author : Min Fang
// Date   : 2025-09-23

/**********************************************************************************
*
* Problem: Invert Binary Tree
*
* Given the root of a binary tree, invert the tree, and return its root.
* Inversion means for each node, swap its left and right subtrees.
*
* Example 1:
*   Input:  root = [4,2,7,1,3,6,9]
*   Output: [4,7,2,9,6,3,1]
*   Explanation:
*         4             4
*       /   \         /   \
*      2     7  =>   7     2
*     / \   / \     / \   / \
*    1   3 6   9   9   6 3   1
*
*
* Example 2:
*   Input:  root = [2,1,3]
*   Output: [2,3,1]
*
* Example 3:
*   Input:  root = []
*   Output: []
*
*
* Constraints:
*   - The number of nodes in the tree is in the range [0, 100].
*   - -100 <= Node.val <= 100
*
*
* Approach: Recursive Depth-First Traversal (Post-order)
*
* - At each node, we recursively invert its left and right subtrees.
* - Then we swap the resulting left and right pointers of the current node.
* - This approach ensures that we are processing children before the parent,
*   which is a form of post-order traversal.
*
*
* Steps:
*   1. Base case: if the current node is NULL, return NULL.
*   2. Recursively invert the left and right subtrees.
*   3. Swap the left and right children of the current node.
*   4. Return the current node (now inverted).
*
*
* Time Complexity: O(n)
*   - We visit each node exactly once.
*
* Space Complexity: O(h)
*   - Recursive call stack space.
*   - h is the height of the tree.
*   - Worst case: O(n) if the tree is skewed (like a linked list).
*   - Best case: O(log n) if the tree is balanced.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

/**********************************************************************************
*
* Solution 2
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
