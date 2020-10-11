//
// Created by tsuki on 2020/10/4.
//

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <vector>
const int null = INT32_MIN;

template<typename T>
class Utils {
public:

    T *GetTreeNode(std::vector<int> vec) {
        T *head = new T(vec[0]);
        T *node = head;
        std::vector<T*> nodeVec;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] != null) {
                T *leftTmp = new T(vec[i]);
                node->left = leftTmp;
                nodeVec.push_back(leftTmp);
            }
            i++;
            if (i < vec.size()) {
                if (vec[i] != null) {
                    T *rightTmp = new T(vec[i]);
                    node->right = rightTmp;
                    nodeVec.push_back(rightTmp);
                }
            }
            if (nodeVec.size() == 0) {
                break;
            }
            node = nodeVec.front();
            auto iter = nodeVec.begin();
            nodeVec.erase(iter);
        }
        return head;
    }

    // 中序遍历
    void MiddleOrderToString(T *head) {
        if (head->left != NULL) {
            MiddleOrderToString(head->left);
        }
        std::cout << head->val << std::endl;
        if (head->right != NULL) {
            MiddleOrderToString(head->right);
        }
    }
};


#endif //LEETCODE_UTILS_H
