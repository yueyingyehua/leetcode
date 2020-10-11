//
// Created by tsuki on 2020/10/3.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        cout << "merge" << endl;
        vector<vector<int>> result;
        vector<vector<int>> tmp;
        if (intervals.size() == 0 ) {
            return result;
        }
        sort(intervals.begin(), intervals.end());
        int front = intervals[0][0];
        vector<int> Tmpvec;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] != front) {
                Tmpvec.clear();
                Tmpvec.push_back(front);
                Tmpvec.push_back(intervals[i-1][1]);
                tmp.push_back(Tmpvec);
                front = intervals[i][0];
            }
        }
        tmp.push_back(intervals[intervals.size() - 1]);
        if (tmp.size() == 0) {
            return result;
        }
        result.push_back(tmp[0]);
        vector<int> tmpVec;
        for (int j = 0; j < tmp.size() - 1; j++) {
            if (result.back()[1] < tmp[j + 1][0]) {
                result.push_back(tmp[j+ 1]);
            } else if (result.back()[1] >= tmp[j + 1][0] && result.back()[1] <= tmp[j + 1][1]) {
                tmpVec.clear();
                tmpVec.push_back(result.back()[0]);
                tmpVec.push_back(tmp[j + 1][1]);
                result.pop_back();
                result.push_back(tmpVec);
            } else if (result.back()[1] > tmp[j + 1][1]) {
                continue;
            }
        }
        return result;
    }
};