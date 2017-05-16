//
//  60.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/16.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    string getPermutation(int n, int k) {
        string result;
        if(n>9) return result;
        for(int i=0;i<n;++i)
            result.push_back('1'+i);
        for(int i=1;i<k;++i)
            next_permutation(result);
        return result;
    }
private:
    void next_permutation(string &result){
        if(result.size()<2) return;
        auto pos=next(result.rbegin());
        while(pos!=result.rend()&&*pos>=*prev(pos)) advance(pos,1);
        if(pos!=result.rend()){
            auto exchange=find_if(result.rbegin(),pos,bind1st(less<int>(),*pos));
            iter_swap(exchange,pos);
        }
        reverse(result.rbegin(),pos);
        return;
    }
};

class Solution2 {
public:
    string getPermutation(int n, int k) {
        string result;
        if(n>9) return result;
        for(int i=0;i<n;++i)
            result.push_back('1'+i);
        for(int i=1;i<k;++i)
            next_permutation(result.begin(),result.end());
        return result;
    }
};

class Solution3 {//康托编码
public:
    string getPermutation(int n, int k) {
        string res,seq;
        for(int i=0;i<n;++i)
            seq.push_back('1'+i);
        
        int base=1;
        for(int i=2;i<=n;++i)
            base*=i;
        
        --k;
        k%=base;
        for(int i=0;i<n;++i){
            base/=(n-i);
            res.push_back(seq[k/base]);
            seq.erase(next(seq.begin(),k/base));
            k%=base;
        }
        return res;
    }
};
