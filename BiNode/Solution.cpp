//
// Created by tsuki on 2020/10/3.
//


// https://leetcode-cn.com/problems/binode-lcci/

#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {

    }
};

class Solution {
public:
    void GetMax(TreeNode *root, TreeNode **head, TreeNode **end) {
        if (root->left == NULL) {
            *head = root;
            if (root->right == NULL) {
                *end = root;
                return;
            } else {
                TreeNode *rightHead;
                TreeNode *rightEnd;
                GetMax(root->right, &rightHead, &rightEnd);
                root->right = rightHead;
                *end = rightEnd;
                return;
            }
        } else {
            GetMax(root->left, head, end);
        }
        (*end)->right = root;
        root->left = NULL;

        if (root->right == NULL) {
            *end = root;
            return;
        }
        TreeNode *rightHead;
        TreeNode *rightEnd;
        GetMax(root->right, &rightHead, &rightEnd);
        root->right = rightHead;
        *end = rightEnd;
    }

    TreeNode* convertBiNode(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        TreeNode *head;
        TreeNode *end;
        GetMax(root, &head, &end);
        return head;
    }
};