//
//  14.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/29.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix=strs[0];
        for(int i=1;i<strs.size();++i){
            int index=0;
            while(index<strs[i].size()&&prefix[index]==strs[i][index])
                ++index;
            prefix=prefix.substr(0,index);
        }
        return prefix;
    }
};
