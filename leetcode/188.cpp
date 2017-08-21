//
//  188.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/20.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int maxProfit(int k, vector<int>& prices) {//二维动态规划，超时
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<i&&j<=k;++j){
                int tmp=0;
                for(int h=1;h<=i;++h)
                    tmp=max(tmp,dp[h][j-1]+prices[i-1]-prices[h-1]);
                dp[i][j]=max(dp[i-1][j],tmp);
            }
        }
        return dp[n][k];
    }
};

class Solution2 {
public:
    int maxProfit(int k, vector<int>& prices) {//一维动态规划，还是超时
        int n=prices.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=k;++i){
//            cout<<"fuck you"<<endl;
            vector<int> next(n+1,0);
            for(int j=i+1;j<=n;++j){
                int tmp=0;
                for(int h=1;h<j;++h)
                    tmp=max(tmp,dp[h]+prices[j-1]-prices[h-1]);
                next[j]=max(next[j-1],tmp);
            }
//            for(auto num:next) cout<<num<<" ";
//            cout<<endl;
            dp=next;
        }
        return dp[n];
    }
};

class Solution3 {
public:
    int maxProfit(int k, vector<int>& prices) {//一维动态规划，加个优化
        int n=prices.size();
        //k次买卖的核心是，存在多于k次的单独上升区间，需要从中选出k个
        //k>n/2时，不可能存在多于k个的单独上升区间，无需选择，全加起来
        if(k>n/2){
            int res=0;
            for(int i=1;i<n;++i)
                res+=max(prices[i]-prices[i-1],0);
            return res;
        }
        vector<int> dp(n+1,0);
        for(int i=1;i<=k;++i){
            vector<int> next(n+1,0);
            for(int j=i+1;j<=n;++j){
                int tmp=0;
                for(int h=1;h<=j;++h)
                    tmp=max(tmp,dp[h]+prices[j-1]-prices[h-1]);
                next[j]=max(next[j-1],tmp);
            }
            dp=next;
        }
        return dp[n];
    }
};

int main(int argc,const char *argv[]){
    vector<int> prices={1,4,2,8,5,7};
    Solution2 solution;
    cout<<solution.maxProfit(3, prices)<<endl;
    return 0;
}
