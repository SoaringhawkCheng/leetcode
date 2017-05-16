//
//  27.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/15.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {//只改变数组内元素的顺序，不改变数组元素集
        vector<int>::reverse_iterator pre,cur;
        pre=cur=nums.rbegin();
        int size=nums.size();
        int length=0;
        while(cur!=nums.rend()){
            if(*cur==val){
                if(cur!=pre)
                    iter_swap(cur,pre);
                ++pre,++cur;
            }
            else{
                ++cur;
            }
        }
        return cur-pre;
    }
}

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[index++]=nums[i];
            }
        }
        return index;
    }
};

class Solution3 {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};
