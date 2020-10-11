//
// Created by tsuki on 2020/10/4.
//
#include <iostream>
#include "Solution.cpp"
#include "../Utils/Utils.h"


class BiNodeClient {
public:

    void ToString(TreeNode *head) {
        if (head->left != NULL) {
            ToString(head->left);
        }
        std::cout << head->val << std::endl;
        if (head->right != NULL) {
            ToString(head->right);
        }
    }

    void run() {
        Solution solution;
        TreeNode *node0 = new TreeNode(0);

        TreeNode *node1 = new TreeNode(1);

        node1->left = node0;

        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(3);
        node2->left = node1;
        node2->right = node3;

        TreeNode *node6 = new TreeNode(6);
        TreeNode *node5 = new TreeNode(5);
        node5->right = node6;

        TreeNode *head = new TreeNode(4);
        head->left = node2;
        head->right = node5;
        ToString(head);
        std::cout << "+++++++++++++++++" << std::endl;
        Utils<TreeNode> utils;
        utils.MiddleOrderToString(head);
//        TreeNode * result = solution.convertBiNode(head);
        std::cout << "success" << std::endl;
//        ToString(result);
    }
};
