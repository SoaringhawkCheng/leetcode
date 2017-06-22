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
        int index=3;
        for(int i=3;i<nums.size();++i){
            if(nums[i]==nums[index-1]&&nums[i]==nums[index-2]&&nums[i]==nums[index-3])
                continue;
            nums[index++]=nums[i];
        }
        return index;
    }
};

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
    vector<int> nums={1,1,1,1,2,2,2,3,3,3,3,3,4,4,5,5,5,5};
    Solution1 s1;
    int size=s1.removeDuplicates(nums);
    for(int i=0;i<size;++i)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
