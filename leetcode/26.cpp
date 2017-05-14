//
//  26.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/3.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int size=nums.size();
        int newsize=1;
        for(int i=1;i<size;++i)
            if(nums[i-1]!=nums[i])
                nums[newsize++]=nums[i];
        nums.resize(newsize);
        for(auto num:nums) cout<<num<<" ";
        cout<<endl;
        return newsize;
    }
};
class Solution2{
public:
    int removeDuplicates(vector<int>& nums){
        int newsize=distance(nums.begin(), unique(nums.begin(), nums.end()));
        nums.resize(newsize);
        for(auto num:nums) cout<<num<<" ";
        cout<<endl;
        return newsize;
    }
};

class Solution3{
public:
    int removeDuplicates(vector<int>& nums){
        auto cur=nums.begin();
        auto pre=nums.begin();
        while(cur!=nums.end()){
            *pre++=*cur;
            cur=upper_bound(cur, nums.end(), *cur);
        }
        nums.erase(pre, nums.end());
        for(auto num:nums) cout<<num<<" ";
        cout<<endl;
        return nums.size();
    }
};

class Solution4{
public:
    int removeDuplicates(vector<int>& nums){
        int count=0;
        int size=nums.size();
        for(int i=1;i<size;++i){
            if(nums[i-1]==nums[i]) ++count;
            else nums[i-count]=nums[i];
        }
        nums.resize(size-count);
        for(auto num:nums) cout<<num<<" ";
        cout<<endl;
        return size-count;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,1,1,2,2,3,4,5,5,5,5,5,6,6,7,7,7,8};
    
    Solution1 s1;
    s1.removeDuplicates(nums);
    
    nums={1,1,1,2,2,3,4,5,5,5,5,5,6,6,7,7,7,8};
    Solution2 s2;
    s2.removeDuplicates(nums);
    
    nums={1,1,1,2,2,3,4,5,5,5,5,5,6,6,7,7,7,8};
    Solution3 s3;
    s3.removeDuplicates(nums);
    
    nums={};
    Solution4 s4;
    s4.removeDuplicates(nums);
    
    return 0;
}
