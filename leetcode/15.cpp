//
//  15.cpp
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
    int threeSumClosest(vector<int>& nums, int target) {
        int min_gap=INT_MAX;
        int result=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i){
            if(i&&nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int gap=abs(sum-target);
                if(gap<min_gap){
                    result=sum;
                    min_gap=gap;
                }
                if(sum==target) return target;
                else if(sum<target){
                    ++j;
                    while(j<k&&nums[j]==nums[j-1]) ++j;
                }
                else{
                    --k;
                    while(j<k&&nums[k]==nums[k+1]) --k;
                }
            }
        }
        return result;
    }
};
