//
//  10.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/25.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    bool isMatch(string text, string pattern) {
        if(pattern.empty()) return text.empty();
        if(pattern.size()==1) return text.size()==1&&(pattern[0]=='.'||pattern[0]==text[0]);
        if(pattern[1]=='*')
            return isMatch(text, pattern.substr(2))||(!text.empty()&&(pattern[0]=='.'||pattern[0]==text[0])&&isMatch(text.substr(1), pattern));
        else
            return !text.empty()&&(pattern[0]=='.'||pattern[0]==text[0])&&isMatch(text.substr(1), pattern.substr(1));
    }
};

class Solution2{
public:
    bool isMatch(string text,string pattern){
        int tsize=text.size();
        int psize=pattern.size();
        vector<vector<bool>> dp(tsize+1,vector<bool>(psize+1));
        dp[0][0]=true;
        for(int i=1;i<=tsize;++i) dp[i][0]=false;
        for(int j=1;j<=psize;++j) dp[0][j]=(j>1&&pattern[j-1]=='*'&&dp[0][j-2]);
        for(int i=1;i<=tsize;++i)
            for(int j=1;j<=psize;++j)
                if(pattern[j-1]=='*')
                    dp[i][j]=(dp[i][j-2]||(dp[i-1][j]&&(pattern[j-2]=='.'||text[i-1]==pattern[j-2])));
                else
                    dp[i][j]=dp[i-1][j-1]&&(pattern[j-1]=='.'||text[i-1]==pattern[j-1]);
        return dp[tsize][psize];
    }
};

int main(int argc,const char *argv[]){
    Solution1 s;
    cout<<s.isMatch("ab", ".*c")<<endl;
    return 0;
}
