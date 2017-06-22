//
//  69.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/7.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution1 {
public:
    int mySqrt(int x) {
        long long res=x;
        while(res*res>x)
            res=(res+x/res)/2;
        return res;
    }
};

class Solution2 {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int left=1,right=x/2;
        int last_mid;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(x/mid>mid){
                left=mid+1;
                last_mid=mid;
            }
            else if(x/mid<mid)
                right=mid-1;
            else
                return mid;
        }
        return last_mid;
    }
};

int main(int argc,const char *argv[]){
    
}
