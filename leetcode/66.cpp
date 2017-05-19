//
//  66.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/18.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        add(digits,1);
        return digits;
    }
private:
    void add(vector<int> &digits,int num){
        int carrybit=num;
        for(int i=digits.size()-1;i>=0;--i){
            int temp=carrybit+digits[i];
            digits[i]=temp%10;
            carrybit=temp/10;
        }
        if(carrybit)
            digits.insert(digits.begin(),carrybit);
    }
};
