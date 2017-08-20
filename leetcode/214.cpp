//
//  214.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/31.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {//我的kmp算法
public:
    string shortestPalindrome(string s) {
        string text(s);
        reverse(text.begin(), text.end());
        if(text==s) return s;
        int len=text.size();
        vector<int> match(len,-1);
        kmpSearch(text,s,match);
        return text+s.substr(match[len-1]+1);
    }
private:
    void kmpSearch(string text,string pattern,vector<int> &match){
        vector<int> next(pattern.size(),-1);
        getNext(pattern, next);
        int len=text.size();
        for(int i=0;i<len-1;++i){
            int k=match[i];
            while(k!=-1&&text[i+1]!=pattern[k+1])
                k=next[k];
            if(text[i+1]==pattern[k+1]) match[i+1]=k+1;
            else match[i+1]=-1;
        }
    }
    void getNext(string pattern,vector<int> &next){
        int len=pattern.size();
        for(int i=0;i<len-1;++i){
            int k=next[i];
            while(k!=-1&&pattern[i+1]!=pattern[k+1])
                k=next[k];
            if(pattern[i+1]==pattern[k+1]) next[i+1]=k+1;
            else next[i+1]=-1;
        }
    }
};

class Solution2 {
public:
    string shortestPalindrome(string s) {
        
    }
};

int main(int argc,const char *argv[]){
    Solution2 s;
    cout<<s.shortestPalindrome("babbbabbaba")<<endl;
    return 0;
}
