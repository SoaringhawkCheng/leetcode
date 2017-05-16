//
//  31.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/15.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        vector<int>::reverse_iterator cur=nums.rbegin();
        while(next(cur)!=nums.rend()&&*next(cur)>=*cur) advance(cur,1);
        if(next(cur)==nums.rend()){
            reverse(nums.begin(),nums.end());
        }
        else{
            vector<int>::reverse_iterator pos=find_if(nums.rbegin(),next(cur),bind1st(less<int>(),*next(cur)));
            iter_swap(next(cur),pos);
            reverse(nums.rbegin(),next(cur));
        }
    }
};
