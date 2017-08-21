//
//  120.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/22.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        for(int i=size-2;i>=0;--i){
            for(int j=0;j<=i;++j)
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
        }
        return triangle[0][0];
    }
};
