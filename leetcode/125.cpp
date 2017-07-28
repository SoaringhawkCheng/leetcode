//
//  125.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/24.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int size=s.size();
        int left=0,right=size-1;
        while(left<right){
            if(!isalnum(s[left])) ++left;
            else if(!isalnum(s[right])) --right;
            else if(toupper(s[left])!=toupper(s[right])) return false;
            else ++left,--right;
        }
        return true;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
