//
//  89.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/18.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size=1<<n;
        result.reserve(size);
        for(int i=0;i<size;++i)
            result.push_back(i^(i>>1));
        return result;
    }
};

class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1<<n);
        result.push_back(0);
        for(int i=0;i<n;++i){
            int highest_bit=1<<i;
            for(int j=result.size()-1;j>=0;--j)
                result.push_back(highest_bit|result[j]);
        }
    }
};
