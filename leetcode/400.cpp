//
//  400.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digits=1;
        long base=9;
        while(n-base*digits>0){
            n-=base*digits;
            ++digits;
            base*=10;
        }
        int index=n%digits;
        if(index==0) index=digits;
        long num=1;
        for(int i=1;i<digits;++i)
            num*=10;
        num+=(index==digits)?n/digits-1:n/digits;
        for(int i=index;i<digits;++i)
            num/=10;
        return num%10;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
