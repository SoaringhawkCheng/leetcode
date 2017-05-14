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

class Solution {//这种方法是错的，只能用在单个重复，不能用在允许两个重复的问题
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int dup=0;
        for(int i=2;i<size;++i){
            if(nums[i]==nums[i-1]&&nums[i]==nums[i-2]) ++dup;
            else nums[i-dup]=nums[i];
            for(auto num:nums) cout<<num<<" ";
            cout<<endl;
        }
        nums.resize(size-dup);
        return size-dup;
    }
};

//class Solution1 {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        if(nums.size()<2) return nums.size();
//        int newsize=2;
//        for(int i=2;i<nums.size();++i){
//            if(nums[i]!=nums[i-2])
//                nums[newsize++]=nums[i];
//        }
//        return newsize;
//    }
//};
//class Solution3 {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        
//    }
//};
//class Solution4 {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        
//    }
//};

int main(int argc,const char *argv[]){
    vector<int> nums={1,1,1,2,2,3};
    Solution1 s1;
    s1.removeDuplicates(nums);
    for(auto num:nums) cout<<num<<" ";
    cout<<endl;
    return 0;
}
