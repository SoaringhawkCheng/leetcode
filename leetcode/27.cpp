//
//  27.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/15.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val) nums[index++]=nums[i];
        }
        return index;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
