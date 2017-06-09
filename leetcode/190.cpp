
//
//  190.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;++i){
            res<<=1;
            res|=n&1;
            n>>=1;
        }
        return res;
    }
};
