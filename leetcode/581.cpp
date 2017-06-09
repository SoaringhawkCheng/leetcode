//
//  581.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<nums.size()-1&&nums[left]<=nums[left+1])
            left=left+1;
        while(right>0&&nums[right]>=nums[right-1])
            right=right-1;
        if(right==0) return 0;
        int maximum=INT_MIN,minimum=INT_MAX;
        for(int i=left;i<=right;++i){
            if(nums[i]>maximum) maximum=nums[i];
            if(nums[i]<minimum) minimum=nums[i];
        }
        int leftborder=-1,rightborder=nums.size();
        for(int i=left;i>=0;--i)
            if(nums[i]<=minimum){
                leftborder=i;
                break;
            }
        for(int j=right;j<nums.size();++j)
            if(nums[j]>=maximum){
                rightborder=j;
                break;
            }
        return rightborder-leftborder-1;
    }
}

class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(nums.begin(),nums.end());
        int leftborder=0,rightborder=nums.size()-1;
        while(leftborder<nums.size()&&nums[leftborder]==sorted[leftborder])
            ++leftborder;
        while(rightborder>=0&&nums[rightborder]==sorted[rightborder])
            --rightborder;
        if(leftborder==nums.size()) return 0;
        return rightborder-leftborder+1;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
