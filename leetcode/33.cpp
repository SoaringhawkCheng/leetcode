//
//  33.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/14.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[left]>nums[mid]){
                if(nums[mid]<target&&nums[right]>=target) left=mid+1;
                else right=mid-1;
            }
            else{
                if(nums[mid]>target&&nums[left]<=target) right=mid-1;
                else left=mid+1;
            }
        }
        return -1;
    }
};
