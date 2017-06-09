//
//  7.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/6.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int reverse(int x) {
        long long res=0;
        while(x){
            res=res*10+x%10;
            x/=10;
        }
        return (res<INT_MIN||res>INT_MAX)?0:res;
    }
};

class Solution2 {
public:
    int reverse(int x) {
        int ans;
        while(x){
            int temp=ans*10+x%10;
            if(temp/10!=ans) return 0;
            ans=temp;
            x/=10;
        }
        return ans;
    }
};

int main(){
    int num=(-6)%5;
    cout<<num<<endl;
}


