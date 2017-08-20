//
//  49.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/29.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for(auto str:strs){
            string key(str);
            sort(key.begin(), key.end());
            group[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto iter=group.begin();iter!=group.end();++iter)
            result.push_back(iter->second);
        return result;
    }
};

class Solution2 {//使用桶排序加速
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        vector<vector<string>> result;
        for(auto str:strs){
            string key=bucketSort(str);
            group[key].push_back(str);
        }
        for(auto iter=group.begin();iter!=group.end();++iter)
            result.push_back(iter->second);
        return result;
    }
private:
    string bucketSort(const string &str){
        string key;
        vector<int> bucket(26,0);
        for(int i=0;i<str.size();++i)
            bucket[str[i]-'a']++;
        for(int i=0;i<26;++i)
            for(int j=0;j<bucket[i];++j)
                key.push_back('a'+i);
        return key;
    }
};

int main(int argc,const char *argv[]){
    Solution1 s;
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result=s.groupAnagrams(strs);
    for(auto res:result){
        for(auto r:res)
            cout<<r<<" ";
        cout<<endl;
    }
    return 0;
}
