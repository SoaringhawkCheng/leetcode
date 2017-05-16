//
//  81.cpp
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
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            cout<<"nums["<<left<<"]="<<nums[left]<<",nums["<<right<<"]="<<nums[right]<<endl;
            cout<<"nums["<<mid<<"]="<<nums[mid]<<endl;
            if(nums[mid]==target) return true;
            else if(nums[left]<nums[mid]){
                if(nums[left]<=target&&target<nums[mid]) right=mid-1;
                else left=mid+1;
            }
            else if(nums[left]>nums[mid]){
                if(nums[mid]<target&&target<=nums[right]) left=mid+1;
                else right=mid-1;
            }
            else
            {
                ++left;
            }
        }
        return false;
    }
};
