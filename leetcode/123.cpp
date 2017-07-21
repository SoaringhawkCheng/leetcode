//
//  123.cpp
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
        int size=prices.size();
        vector<int> firsttrade(size,0);
        vector<int> secondtrade(size,0);
        for(int i=1,valley=prices[0];i<size;++i){
            valley=min(valley, prices[i]);
            firsttrade[i]=max(firsttrade[i-1],prices[i]-valley);
        }
        for(int i=size-2,peak=size-1;i>=0;--i){
            peak=max(peak, prices[i]);
            secondtrade[i]=max(secondtrade[i+1],peak-prices[i]);
        }
        int maxprofit=0;
        for(int i=0;i<size;++i)
            maxprofit=max(maxprofit,firsttrade[i]+secondtrade[i]);
        return maxprofit;
    }
};

int main(int argc,const char *argv[]){
    
    return 0;
}
