//
//  71.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/29.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        auto iter=path.begin();
        while(iter!=path.end()){
            ++iter;
            auto iter2=find(iter, path.end(), '/');
            auto dir=string(iter,iter2);
            if(!dir.empty()&&dir!="."){
                if(dir==".."){
                    if(!dirs.empty()) dirs.pop_back();
                }
                else dirs.push_back(dir);
                iter=iter2;
            }
        }
        string res;
        if(dirs.empty()) res="/";
        for(auto dir:dirs) res=res+"/"+dir;
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.simplifyPath("/..")<<endl;
}
