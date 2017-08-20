//
//  44.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/28.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {//递归法，超时
public:
    bool isMatch(string text, string pattern) {
        //pattern为空
        if(pattern.empty()) return text.empty();
        //pattern不为空，text为空
        if(text.empty()) return pattern[0]=='*'&&isMatch(text, pattern.substr(1));
        //text不为空，pattern遇到特殊字符
        if(pattern[0]=='?') return isMatch(text.substr(1), pattern.substr(1));
        if(pattern[0]=='*') return isMatch(text.substr(1), pattern)||isMatch(text, pattern.substr(1));
        //pattern是普通字符
        return pattern[0]==text[0]&&isMatch(text.substr(1), pattern.substr(1));
    }
};

class Solution2 {//迭代法
public:
    bool isMatch(string text, string pattern) {
        if(pattern.empty()) return text.empty();
        int tsize=text.size();
        int psize=pattern.size();
        vector<bool> curr(tsize+1,false);
        vector<bool> next(tsize+1,false);
        curr[0]=true;
        for(int i=0;i<psize;++i){
            next[0]=curr[0]&&pattern[i]=='*';
            for(int j=0;j<tsize;++j){
                /* 忽略'*' next[j+1]=curr[j+1]
                 * 不忽略'*'，则'*'至少匹配一个字符
                 * 删去text[j],pattern还是会匹配
                 * 有递推公式 next[j+1]=next[j]
                 */
                if(pattern[i]=='*')
                    next[j+1]=curr[j+1]||next[j];
                else
                    next[j+1]=((pattern[i]=='?'||pattern[i]==text[j])&&curr[j]);
            }
            for(auto num:curr) cout<<num<<" ";
            cout<<endl;
            swap(curr,next);
        }
        for(auto num:curr) cout<<num<<" ";
        cout<<endl;
        return curr[tsize];
    }
};

class Solution3 {
public:
    bool isMatch(string s, string p) {
        
    }
};

int main(int argc,const char *argv[]){
    Solution2 s;
    cout<<s.isMatch("aa", "*")<<endl;
    return 0;
}
