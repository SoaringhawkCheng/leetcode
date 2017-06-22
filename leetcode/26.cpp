//
//  26.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/3.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int index=0;
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]!=nums[i+1])
                nums[index++]=nums[i];
        }
        nums[index++]=nums[nums.size()-1];
        return index;
    }
};

class Solution2{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int index=0;
        for(int i=1;i<nums.size();++i){
            if(nums[index]!=nums[i])
                nums[++index]=nums[i];
        }
        return index+1;
    }
};

class Solution3{
public:
    int removeDuplicates(vector<int>& nums){
        return distance(nums.begin(),unique(nums.begin(), nums.end()));
    }
};

class Solution4{
public:
    int removeDuplicates(vector<int>& nums){
        int count=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1]) ++count;
            else nums[i-count]=nums[i];
        }
        return nums.size()-count;
    }
};

class Solution5 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i,index;
        for(i=1,index=1;i<nums.size();++i){
            if(nums[i]!=nums[i-1])
                nums[index++]=nums[i];
            
        }
        return index;
    }
};

class Solution6 {
    typedef vector<int>::iterator Iter;
public:
    int removeDuplicates(vector<int>& nums) {
        Iter unique_end=removeDuplicate(nums.begin(),nums.end());
        return distance(nums.begin(),unique_end);
    }
private:
    Iter removeDuplicate(Iter begin,Iter end){
        Iter input=begin;
        while(begin!=end){
            *input++=*begin;
            begin=upper_bound(begin,end,*begin);
        }
        return input;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,1,1,2,2,3,4,5,5,6,6,7};
    vector<int> nums2={1,2};
    Solution5 s;
    int size=s.removeDuplicates(nums2);
    cout<<size<<endl;
    for(int i=0;i<size;++i)
        cout<<nums2[i]<<" ";
    cout<<endl;
    return 0;
}
