
//
//  168.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/6.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    string convertToTitle(int n) {
        string title;
        if(n<=0) return title;
        while(n){
            title+='A'+(n-1)%26;
            n=(n-1)/26;
        }
        reverse(title.begin(),title.end());
        return title;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
         return n==0?"":convertToTitle((n-1)/26)+(char)('A'+(n-1)%26);
    }
};
