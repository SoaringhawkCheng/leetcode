//
//  1.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/15.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> mapping;
        for(int i=0;i<nums.size();++i){
            if(mapping.find(target-nums[i])!=mapping.end()){
                int mini=min(i,mapping[target-nums[i]]);
                int maxi=max(i,mapping[target-nums[i]]);
                result={mini,maxi};
                break;
            }
            mapping[nums[i]]=i;
        }
        return result;
    }
};
