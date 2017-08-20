//
//  58.cpp
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
    int lengthOfLastWord(string s) {
        auto iter=s.rbegin();
        int len=0;
        while(iter!=s.rend()&&*iter==' ') ++iter;
        while(iter!=s.rend()&&isalpha(*iter))
            ++len,++iter;
        return len;
    }
};
