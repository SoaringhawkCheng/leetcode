//
//  32.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/31.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution1 {//DP方法，时间复杂度O(n)，空间复杂度O(n)
public:
    int longestValidParentheses(string s) {
        int len=s.length();
        int maxlen=0;
        vector<int> dp(len,0);
        for(int i=1;i<=len;++i){
            if(s[i]==')'){
                if(s[i-1]=='(') dp[i]=(i>=2?dp[i-2]+2:2);
                else if(s[i-1-dp[i-1]]=='('&&i-1-dp[i-1]>=0)
                    dp[i]=dp[i-1]+2+(i-2-dp[i-1]>=0?dp[i-2-dp[i-1]]:0);
                maxlen=max(maxlen,dp[i]);
            }
        }
        return maxlen;
    }
};

class Solution2 {//stack方法，时间复杂度O(n)，空间复杂度O(n)
public:
    int longestValidParentheses(string s) {
        int len=s.length();
        int maxlen=0;
        stack<int> stk;
        stk.push(-1);
        for(int i=0;i<len;++i){
            cout<<"i="<<i<<endl;
            if(s[i]=='(') stk.push(i);
            else{
                stk.pop();
                if(stk.empty()) stk.push(i);
                else maxlen=max(maxlen,i-stk.top());
            }
        }
        return maxlen;
    }
};

class Solution3 {//两遍扫描方法，时间复杂度O(n)，空间复杂度O(1)？这个方法不太理解
public:
    int longestValidParentheses(string s) {
        int size=s.size();
        int left=0,right=0,maxlen=0;
        for(int i=0;i<size;++i){
            if(s[i]=='(') ++left;
            else ++right;
            if(left==right) maxlen=max(maxlen,2*right);
            else if(right>=left) left=right=0;
        }
        left=right=0;
        for(int i=size-1;i>=0;--i){
            if(s[i]==')') ++right;
            else ++left;
            if(left==right) maxlen=max(maxlen,2*left);
            else if(left>=right) left=right=0;
        }
        return maxlen;
    }
};

int main(){
    Solution2 s;
    cout<<s.longestValidParentheses("()))())((()()())")<<endl;
}
