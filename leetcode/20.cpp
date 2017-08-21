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
        stack<char> stk;
        string left="([{";
        string right=")]}";
        for(int i=0;i<s.size();++i){
            int index;
            if((index=left.find(s[i]))!=string::npos) stk.push(s[i]);
            else{
                index=right.find(s[i]);
                if(!stk.empty()&&stk.top()==left[index]) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};

int main(int argc,const char *argv[]){
    Solution s;
    cout<<(s.isValid("()")?"true":"false")<<endl;
    return 0;
}
