//
//  125.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/6.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Solution1 {
public:
    bool isPalindrome(string s) {//自己写的版本，又臭又长
        int left=0,right=s.length()-1;
        while(left<right){
            while(left<right&&!(isalpha(s[left])||isdigit(s[left])))
                ++left;
            while(left<right&&!(isalpha(s[right])||isdigit(s[right])))
                --right;
            if(left==right) return true;
            if(compare(s[left],s[right])) ++left,--right;
            else break;
        }
        if(left<right) return false;
        return true;
    }
    bool compare(char left,char right){
        if(left==right) return true;
        if(isalpha(left)&&isalpha(right)&&tolower(left)==tolower(right))
            return true;
        return false;
    }
};

class Solution2 {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.length()-1;
        while(left<right){
            if(!isalnum(s[left])) ++left;
            else if(!isalnum(s[right])) --right;
            else{
                if(tolower(s[left++])!=tolower(s[right--]))
                    return false;
            }
        }
        return true;
    }
};

int main(int argc,const char *argv[]){
//    Solution s;
//    cout<<s.isPalindrome("ab")<<endl;
    cout<<isalpha('a')<<endl;
    return 0;
}
