//
//  303.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/7.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum=0;
        partialsum.push_back(0);
        for(auto num:nums){
            sum+=num;
            partialsum.push_back(sum);
        }
    }
    int sumRange(int i, int j) {
        return partialsum[j+1]-partialsum[i];
    }
private:
    vector<int> partialsum;
};

int main(int argc,const char *argv[]){
    return 0;
}
