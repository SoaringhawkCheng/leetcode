//
//  14.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        if(strs.empty()) return prefix;
        int minlen=INT_MAX;
        for(int i=0;i<strs.size();++i)
            if(strs[i].length()<minlen)
                minlen=strs[i].length();
        for(int idx=0;idx<minlen;++idx){
            for(int i=1;i<strs.size();++i){
                if(strs[i][idx]!=strs[i-1][idx])
                    return prefix;
            }
            prefix.push_back(strs[0][idx]);
        }
        return prefix;
    }
};

int main(int argc,const char *argv[]){
    vector<string> strs={"abcde","abcdefg","abcdefghij","abcdefghijkl","abcdefghijklmn"};
    Solution s;
    cout<<s.longestCommonPrefix(strs)<<endl;
    return 0;
}
