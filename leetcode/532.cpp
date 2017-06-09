//
//  532.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/7.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        unordered_map<int,int> mmap;
        for(int i=0;i<nums.size();++i)
            ++mmap[nums[i]];
        int res=0;
        if(k!=0){
            for(auto it=mmap.begin();it!=mmap.end();++it){
                if(mmap.find(it->first+k)!=mmap.end()) ++res;
            }
        }
        else{
            for(auto it=mmap.begin();it!=mmap.end();++it)
                if(it->second>1) ++res;
        }
        return res;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={3,1,4,1,5};
    Solution s;
    cout<<s.findPairs(nums, 2)<<endl;
    return 0;
}
