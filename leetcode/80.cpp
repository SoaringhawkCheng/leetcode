//
//  80.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/3.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int index=2;
        for(int i=2;i<nums.size();++i){
            if(nums[i]]==nums[index-1]&&nums[i]==nums[index-2])//没有扩展性，允许三个重复值就无法改写
                continue;
            nums[index++]=nums[i];
        }
        return index;
    }
}

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size()<=2) return nums.size();
        int index=2;
        for(int i=2;i<nums.size();++i){
            if(nums[i]!=nums[index-2])
                nums[index++]=nums[i];
        }
        return index;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,1,1,2,2,3};
    Solution1 s1;
    s1.removeDuplicates(nums);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    return 0;
}
