//
//  20.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/31.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string left="([{";
        string right=")]}";
        stack<char> mstack;
        for(auto ch:s){
            if(left.find(ch)!=string::npos)
                mstack.push(ch);
            else{
                if(mstack.empty()||mstack.top()!=left[right.find(ch)])
                    return false;
                else
                    mstack.pop();
            }
        }
        return mstack.empty();
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
