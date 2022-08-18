/* Author:  Vincent Tam
 * CS5008 Summer 2022
 * LeetCode 701 Insert into a Binary Search Tree
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    /* create new node */
	struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
	/* if root is null, new node is root */
    if(root == NULL) {
        return new_node;
    }
	/* keep same root, recursively call left and right subtrees and compare values */
    if(val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    else if ( val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}
