//
//  16.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/13.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=0;
        int minimum=INT_MAX;
        sort(nums.begin(),nums.end());
        for(auto left=nums.begin();left!=prev(nums.end(),2);advance(left,1)){
            auto mid=next(left);
            auto right=prev(nums.end());
            while(mid<right){
                int sum=*left+*mid+*right;
                int distance=abs(sum-target);
                if(distance<minimum){
                    result=sum;
                    minimum=distance;
                }
                if(sum<target) ++mid;
                else --right;
            }
        }
        return result;
    }
};
