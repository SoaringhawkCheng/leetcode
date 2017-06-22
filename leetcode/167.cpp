//
//  167.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/13.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left=0,right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                result={left+1,right+1};
                return result;
            }
            else if(numbers[left]+numbers[right]<target)
                ++left;
            else
                --right;
        }
        return result;
    }
};
