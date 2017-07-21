//
//  121.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/19.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minnum=INT_MAX;
        int promax=INT_MIN;
        for(int i=0;i<prices.size();++i){
            minnum=min(minnum,prices[i]);
            promax=max(promax,prices[i]-minnum);
        }
        return promax;
    }
};
