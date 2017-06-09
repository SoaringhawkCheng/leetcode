//
//  58.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution1 {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        auto start=find_if(s.begin(),s.end(),::isalpha);
        auto end=find(start,s.end(),' ');
        return end-start;
    }
};

class Solution2 {
public:
    int lengthOfLastWord(string s) {
        int len=0,last_len=0;
        for(auto it=s.begin();it!=s.end();++it){
            if(*it!=' ') ++len;
            else {
                if(len) last_len=len;
                len=0;
            }
        }
        return len==0?last_len:len;
    }
};

class Solution3 {
public:
    int lengthOfLastWord(string s) {
        int len=0,tail=s.length()-1;
        while(tail>=0&&s[tail]==' ') --tail;
        while(tail>=0&&s[tail]!=' '){
            ++len;
            --tail;
        }
        return len;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
