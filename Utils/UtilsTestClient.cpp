//
// Created by tsuki on 2020/10/11.
//

#include <iostream>
#include <vector>
#include "Utils.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {

    }
};

class UtilsTestClient {
public:
    void run() {
        std::vector<int> nodes = {4, 2, 5, 1, 3, null, 6, 0};
        Utils<TreeNode> utils;
        TreeNode *head = utils.GetTreeNode(nodes);
        utils.MiddleOrderToString(head);

    }
};