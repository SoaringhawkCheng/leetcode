//
//  70.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/18.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution1 {//递归法，超时
public:
    int climbStairs(int n) {
        if(n==0||n==1) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

class Solution2 {//迭代法
public:
    int climbStairs(int n) {
        if(n==0||n==1) return 1;
        int pre=1,cur=1,next;
        for(int i=2;i<=n;++i){
            next=pre+cur;
            pre=cur;
            cur=next;
        }
        return cur;
    }
};

class Solution3 {//公式法
public:
    int climbStairs(int n) {
        double fai1=(1+sqrt(5))/2.0;
        double fai2=(1-sqrt(5))/2.0;
        return (pow(fai1,n+1)-pow(fai2,n+1))/sqrt(5);
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
