//
//  5.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/24.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {//二维动态规划
public:
    string longestPalindrome(string s) {
        int size=s.size();
        vector<vector<bool>> dp(size,vector<bool>(size,false));
        int start=0,maxlen=0;
        for(int right=0;right<size;++right){
            for(int left=0;left<=right;++left){
                if(left==right) dp[left][right]=true;
                else if(right==left+1) dp[left][right]=(s[left]==s[right]);
                else dp[left][right]=((s[left]==s[right])&&dp[left+1][right-1]);
                if(dp[left][right]&&right-left+1>maxlen){
                    maxlen=right-left+1;
                    start=left;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};

int main(int argc,const char *argv[]){
    string s="";
    cout<<s.substr(0,0)<<endl;
    return 0;
}
