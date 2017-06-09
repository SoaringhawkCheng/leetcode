//
//  414.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/7.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution1 {
public:
    int thirdMax(vector<int>& nums) {
        set<int> mset;
        for(auto num:nums){
            if(find(mset.begin(),mset.end(),num)==mset.end()){//不需要这种判定，见标准答案
                if(mset.size()<3) mset.insert(num);
                else if(num>*mset.begin()){
                    mset.erase(mset.begin());
                    mset.insert(num);
                }
            }
        }
        cout<<endl;
        if(mset.size()<3)
            return *mset.rbegin();
        return *mset.begin();
    }
};

class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for(auto num:nums){
            if(top3.insert(num).second&&top3.size()>3)
                top3.erase(top3.begin());
        }
        if(top3.size()<3) return *top3.rbegin();
        else return *top3.begin();
    }
};
