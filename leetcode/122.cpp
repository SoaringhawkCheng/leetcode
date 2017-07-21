//
//  122.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/19.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int maximum;
        int minimum;
        int profit=0;
        bool start=true;
        prices.push_back(INT_MIN);
        for(int i=0;i<prices.size()-1;++i){
            if(start){
                minimum=maximum=prices[i];
                start=false;
            }
            if(prices[i]<=prices[i+1]){
                maximum=max(maximum,prices[i+1]);
            }
            else{
                profit=profit+(maximum-minimum);
                start=true;
            }
        }
        return profit;
    }
};

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();++i)
            profit+=max(prices[i]-prices[i-1],0);
        return profit;
    }
};

int main(){
    vector<int> prices={1,2};
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
}
