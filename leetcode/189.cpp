//
//  189.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/6.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        if(size<2) return;
        k=k%size;
        k=size-k;
        for(int i=0;i<k;++i)
            nums.push_back(nums[i]);
        for(int i=0;i<size;++i)
            nums[i]=nums[i+k];
        nums.erase(next(nums.begin(),size),nums.end());
    }
};
