//
//  605.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;n>0&&i<flowerbed.size();++i){
            if(flowerbed[i]==0&&(i==0||flowerbed[i-1]==0)&&(i==flowerbed.size()-1||flowerbed[i+1]==0)){
                flowerbed[i]=1;
                --n;
            }
        }
        return n==0;
    }
}

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i=1;i<flowerbed.size()-1;++i){
            if(flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0)
                --n,++i;
        }
        return n<=0;
    }
};
