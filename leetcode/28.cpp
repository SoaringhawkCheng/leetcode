
//
//  28.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/7.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int size1=haystack.size();
        int size2=needle.size();
        cout<<size1<<" "<<size2<<endl;
        for(int i=0;i<=size1-size2;++i){
            int ismatch=true;
            for(int j=0;j<size2;++j){
                if(haystack[i+j]!=needle[j]){
                    ismatch=false;
                    break;
                }
            }
            if(ismatch) return i;
        }
        return -1;
    }
};

class Solution{
public:
    int kmpSearch(string text,string pattern){
        int tsize=text.size();
        int psize=pattern.size();
        if(psize==0) return 0;
        if(tsize==0) return -1;
        vector<int> next(psize,-1);
        getNext(pattern, next);
        for(int pos=0,k=-1;pos<tsize;++pos){
            while(k>=0&&text[pos]!=pattern[k+1])
                k=next[k];
            if(text[pos]==pattern[k+1]) k=k+1;
            if(k==psize-1) return pos-k;
        }
        return -1;
    }
private:
    void getNext(string pattern,vector<int> &next){
        int size=pattern.size();
        for(int pos=1,k=-1;pos<size;++pos){
            /*只有k>=0才能进行next索引*/
            while(k>=0&&pattern[pos]!=pattern[k+1])
                k=next[k];
            if(pattern[pos]==pattern[k+1]) k=k+1;
            pattern[pos]=k;
        }
    }
};

int main(int argc,const char *argv[]){
    string text1="abacabacdavabacdabaae";
    string text2="aawwwwwwwwwww";
    string pattern="abacdaba";
    Solution s;
    cout<<s.kmpSearch(text1, pattern)<<endl;
    cout<<s.kmpSearch(text2, pattern)<<endl;
    return 0;
}
