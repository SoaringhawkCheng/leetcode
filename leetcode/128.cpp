//
//  128.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/14.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1{
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> used;
        for(auto num:nums) used[num]=false;
        int longest=0;
        for(auto num:nums){
            if(used[num]) continue;
            int length=1;
            used[num]=true;
            for(int i=num+1;used.find(i)!=used.end();++i){
                used[i]=true;
                ++length;
            }
            for(int i=num-1;used.find(i)!=used.end();--i){
                used[i]=true;
                ++length;
            }
            longest=max(longest,length);
        }
        return longest;
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int, int> used;
        int longest=1;
        for(auto num:nums){
            if(used.find(num)!=used.end()) continue;
            used[num]=1;
            if(used.find(num-1)!=used.end())
                longest=max(longest,mergeCluster(used, num-1, num));
            if(used.find(num+1)!=used.end())
                longest=max(longest,mergeCluster(used, num, num+1));
        }
        return longest;
    }
private:
    int mergeCluster(unordered_map<int, int> &used,int left,int right){
        int upper=right+used[right]-1;
        int lower=left-used[left]+1;
        int length=upper-lower+1;
        used[lower]=length;
        used[upper]=length;
        return length;
    }
};
