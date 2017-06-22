//
//  154.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/15.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {//我的复杂且容易理解的方法
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int minimum=INT_MAX;
        while(left<=right){
            if(nums[left]<nums[right]){//必是个递增区间，取得最小值
                minimum=min(minimum,nums[left]);
                break;
            }
            if(nums[left]==nums[right]){//区间两边相同，去重
                int tmp=nums[left];
                minimum=min(minimum,tmp);
                while(left<=right&&nums[left]==tmp) ++left;
                while(left<=right&&nums[right]==tmp) --right;
            }
            else{//区间内必包含gap
                int mid=left+(right-left)/2;
                if(nums[left]<=nums[mid]) left=mid+1;//左边不包含gap
                else right=mid;//左边包含gap
            }
        }
        return minimum;
    }
};
