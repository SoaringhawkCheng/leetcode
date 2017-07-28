//
//  67.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/24.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        auto iter1=a.rbegin();
        auto iter2=b.rbegin();
        string res;
        bool carrybit=false;
        while(iter1!=a.rend()||iter2!=b.rend()||carrybit){
            int lhs=0;
            int rhs=0;
            if(iter1!=a.rend()){
                lhs=*iter1-'0';
                ++iter1;
            }
            if(iter2!=b.rend()){
                rhs=*iter2-'0';
                ++iter2;
            }
            int sum=lhs+rhs+carrybit;
            carrybit=sum/2;
            sum=sum%2;
            res.push_back('0'+sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc,const char *argv[]){
    string a="746";
    string b="1385";
    Solution s;
    cout<<s.addBinary(a, b)<<endl;
    return 0;
}
