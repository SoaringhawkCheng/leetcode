//
//  48.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/18.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();++i)
            for(int j=0;j<i;++j)
                swap(matrix[i][j],matrix[j][i]);
        for(int i=0;i<matrix.size();++i)
            for(int j=0;j<matrix[0].size()-1-j;++j)
                swap(matrix[i][j],matrix[i][matrix[0].size()-1-j]);
    }
};
