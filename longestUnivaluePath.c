/************************************************
LeetCode 687: Longest Univalue Path
Author: Johnny Chan
Date:   Dec 09 2017


Given a binary tree, find the length of the longest path where each node in the 
path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of 
edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the 
tree is not more than 1000.
************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    return a > b ? a : b;
}

int longestUnivaluePath_helper(struct TreeNode* root, int* ans) {
    if (root == NULL) return 0;
    int longestUnival_left = longestUnivaluePath_helper(root->left, ans);
    int longestUnival_right = longestUnivaluePath_helper(root->right, ans);
    int pl = 0, pr = 0;
    if (root->left && root->val == root->left->val) pl = longestUnival_left + 1;
    if (root->right && root->val == root->right->val) pr = longestUnival_right + 1;
    *ans = max(*ans, pl + pr);
    return max(pl, pr);
}

int longestUnivaluePath(struct TreeNode* root) {
    // if (root == NULL) return 0;
    int ans = 0;
    longestUnivaluePath_helper(root, &ans);
    return ans;
}