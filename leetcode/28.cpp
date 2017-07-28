//
//  28.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/24.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {//看毛片
public:
    int kmpSearch(string text,string pattern){
        if(pattern==""||text==pattern) return 0;
        int psize=pattern.size();
        int tsize=text.size();
        vector<int> prefix=getPrefix(pattern);
        for(int i=0,match=-1;i<tsize;++i){
            while(match>=0&&pattern[match+1]!=text[i])
                match=prefix[match];
            if(pattern[match+1]==text[i]) match=match+1;
            if(match==psize-1) return i-match;
        }
        return -1;
    }
private:
    vector<int> getPrefix(string pattern){
        int size=pattern.size();
        vector<int> prefix(size,-1);
        for(int i=1,match=-1;i<size;++i){
            while(match>=0&&pattern[match+1]!=pattern[i])
                match=prefix[match];
            if(pattern[match+1]==pattern[i]) match=match+1;
            prefix[i]=match;
        }
        return prefix;
    }
};

class Solution2 {
public:
    int bruteForce(string text, string pattern) {
        if(pattern==""||text==pattern) return 0;
        for(int i=0;i<text.size();++i){
            bool match=true;
            for(int j=0;j<pattern.size();++j){
                if(text[i+j]!=pattern[j]){
                    match=false;
                    break;
                }
            }
            if(match) return i;
        }
        return -1;
    }
};

int main(int argc,const char *argv[]){
//    string text1="abacabacdavabacdabaae";
//    string text2="aawwwwwwwwwww";
//    string pattern="abacdaba";
    string text="aaba";
    string pattern="aba";
    Solution2 s;
    cout<<s.kmpSearch(text, pattern)<<endl;
//    cout<<s.kmpSearch(text2, pattern)<<endl;
    return 0;
}
