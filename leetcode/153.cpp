//
//  153.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/15.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {//自己的蠢方法，继承了之前rotated sorted array
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int minimum=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[left]<nums[mid]){
                minimum=min(minimum,nums[left]);
                left=mid+1;
            }
            else if(nums[left]>nums[mid]){
                minimum=min(minimum,nums[mid]);
                right=mid-1;
            }
            else{
                minimum=min(minimum,nums[mid]);
                left=mid+1;
            }
        }
        return minimum;
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            if(nums[left]<=nums[right])//区间内不含降序序列
                return nums[left];
            int mid=left+(right-left)/2;
            if(nums[left]<=nums[mid])//左<中||左=中，降序序列在右边
                left=mid+1;//最小值不可能是mid
            else//降序序列在左边，最小值可能是mid
                right=mid;
        }
        return nums[left];
    }
};
