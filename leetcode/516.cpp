//
//  516.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/31.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//当时万革史考过这题
//最长回文子序列
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size()));
        for(int right=0;right<s.size();++right){
            for(int left=right;left>=0;--left){
                if(left==right) dp[left][right]=1;
                else if(left+1==right&&s[left]==s[right]) dp[left][right]=2;
                else{
                    if(s[left]==s[right])
                        dp[left][right]=max(max(dp[left][right-1],dp[left+1][right]),dp[left+1][right-1]+2);
                    else
                        dp[left][right]=max(max(dp[left][right-1],dp[left+1][right]),dp[left+1][right-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
