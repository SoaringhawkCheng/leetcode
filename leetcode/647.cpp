//
//  647.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/31.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int countSubstrings(string s) {
        int result=0;
        int size=s.size();
        for(int i=0;i<size;++i){
            for(int j=0;i-j>=0&&i+j<size&&s[i-j]==s[i+j];++j) ++result;
            for(int j=0;i-j>=0&&i+j+1<size&&s[i-j]==s[i+j+1];++j) ++result;
        }
        return result;
    }
};

class Solution2 {
public:
    int countSubstrings(string s) {
        int count=0;
        int size=s.size();
        vector<vector<bool>> dp(size,vector<bool>(size,false));
        for(int right=0;right<size;++right){
            for(int left=right;left>=0;--left){
                cout<<left<<" "<<right<<" ";
                if(left==right) dp[left][right]=true;
                else if(left+1==right){
                    if(s[left]==s[right]) dp[left][right]=true;
                    else dp[left][right]=false;
                }
                else{
                    if(s[left]==s[right]) dp[left][right]=dp[left+1][right-1]&&s[left]==s[right];
                    else dp[left][right]=false;
                }
                cout<<dp[left][right]<<" ";
                if(dp[left][right]) {count=count+1;cout<<s.substr(left,right-left+1);}
                cout<<endl;
            }
        }
        return count;
    }
};

int main(int argc,const char *argv[]){
    Solution2 solution;
    string s="aaa";
    cout<<solution.countSubstrings(s)<<endl;
    return 0;
}
