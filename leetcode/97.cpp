//
//  97.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/20.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1=s1.size(),size2=s2.size();
        if(size1+size2!=s3.size()) return false;
        vector<vector<bool>> match(size1+1,vector<bool>(size2+1,false));
        match[0][0]=true;
        for(int i=1;i<=size1;++i)
            match[i][0]=match[i-1][0]&&s1[i-1]==s3[i-1];
        for(int j=1;j<=size2;++j)
            match[0][j]=match[0][j-1]&&s2[j-1]==s3[j-1];
        for(int i=1;i<=size1;++i)
            for(int j=1;j<=size2;++j)
                match[i][j]=(match[i-1][j]&&s1[i-1]==s3[i+j-1])||(match[i][j-1]&&s2[j-1]==s3[i+j-1]);
        return match[size1][size2];
};

class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1=s1.size(),size2=s2.size();
        if(size1+size2!=s3.size()) return false;
        if(size1>size2) return isInterleave(s2, s1, s3);
        vector<bool> match(size2+1,false);
        match[0]=true;
        for(int i=1;i<=size2;++i)
            match[i]=match[i-1]&&s2[i-1]==s3[i-1];
        for(int i=1;i<=size1;++i){
            match[0]=match[0]&&s1[i-1]==s3[i-1];
            for(int j=1;j<=size2;++j){
                match[j]=(match[j]&&s1[i-1]==s3[i+j-1])||(match[j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return match[size2];
    }
};
    
int main(int argc,const char *argv[]){
    return 0;
}
