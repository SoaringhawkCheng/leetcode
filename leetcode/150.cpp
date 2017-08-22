//
//  150.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/8/22.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution1 {//自己使用栈的方法
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();++i){
            pair<bool,int> symbol=parse(tokens[i]);
            if(symbol.first) stk.push(symbol.second);
            else{
                int rhs=stk.top();
                stk.pop();
                int lhs=stk.top();
                stk.pop();
                int tmp;
                switch(symbol.second){
                    case 1:tmp=lhs+rhs;break;
                    case 2:tmp=lhs-rhs;break;
                    case 3:tmp=lhs*rhs;break;
                    case 4:tmp=lhs/rhs;break;
                    default:break;
                }
                stk.push(tmp);
            }
        }
        return stk.top();
    }
private:
    pair<bool,int> parse(string token){
        pair<bool,int> res;
        if(token=="+") res={false,1};
        else if(token=="-") res={false,2};
        else if(token=="*") res={false,3};
        else if(token=="/") res={false,4};
        else res={true,atoi(token.c_str())};
        return res;
    }
};

class Solution2 {//递归很难理解啊
public:
    int evalRPN(vector<string>& tokens) {
        string symbol=tokens.back();
        tokens.pop_back();
        if(symbol!="+"&&symbol!="-"&&symbol!="*"&&symbol!="/") return stoi(symbol);
        int rhs=evalRPN(tokens);
        int lhs=evalRPN(tokens);
        if(symbol=="+") return lhs+rhs;
        if(symbol=="-") return lhs-rhs;
        if(symbol=="*") return lhs*rhs;
        if(symbol=="/") return lhs/rhs;
        return 0;
    }
};

int main(int argc,const char *argv[]){
    vector<string> tokens={"4","13","5","/","+"};
    Solution2 s;
    cout<<s.evalRPN(tokens)<<endl;
}
