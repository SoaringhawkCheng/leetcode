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
            int mid=left+(right-left)/2;//这样划分，右边使用不断于左边，当左边为空是，右边长度为1
            if(nums[mid]==target) return mid;
            if(nums[left]<nums[mid]){//左边不为空，且为升序
                if(nums[left]<=target&&target<nums[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
            else if(nums[left]>nums[mid]){//左边不为空，且为降序，则右边不为空，为升序
                if(nums[mid]<target&&target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
            else//mid在最左边，左边为空，转到右边
                left=mid+1;
        }
        return -1;
    }
};

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[left]>nums[mid]){//左右必有一个递减区间，否则left==right
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

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<nums[right]){
                if(nums[mid]<target&&target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
            else{
                if(nums[left]<=target&&target<nums[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
        }
        return -1;
    }
};
