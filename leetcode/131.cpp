//
//  131.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/18.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(s,0,path,result);
        return result;
    }
private:
    bool isPalindrome(const string &s,int left,int right){
        while(left<right){
//            cout<<s.substr(left,right-left+1)<<" ";
//            cout<<"s[left]="<<s[left]<<" s[right]="<<s[right]<<endl;
            if(s[left]!=s[right]) return false;
            ++left,--right;
        }
        return true;
    }
    void dfs(const string &s,int index,vector<string> &path,vector<vector<string>> &result){
        if(index==s.size()){
            result.push_back(path);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(isPalindrome(s, index, i)){
//                cout<<index<<" "<<i<<s.substr(index,i-index+1)<<endl;
                path.push_back(s.substr(index,i-index+1));
                dfs(s,i+1,path,result);
                path.pop_back();
            }
        }
    }
};

class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(s,0,path,result);
        return result;
    }
private:
    void dfs(const string &s,int index,vector<string> &path,vector<vector<string>> &result){
        if(index==s.size()){
            result.push_back(path);
            return;
        }
        for(int i=index,size=s.size();i<size;++i){
            int left=index,right=i;
            while(left<right&&s[left]==s[right]) ++left,--right;
            if(left>=right){
                path.push_back(s.substr(index,i-index+1));
                dfs(s, i+1, path, result);
                path.pop_back();
            }
        }
    }
};

class Solution3 {
public:
    vector<vector<string>> partition(string s) {
        int size=s.size();
        vector<vector<vector<string>>> resultlist(size+1,vector<vector<string>>());
        resultlist[0].push_back(vector<string>());//这个一定要push，否则line84的for循环一直为空
        vector<vector<bool>> pair(size,vector<bool>(size,false));
        for(int right=0;right<size;++right){
            for(int left=0;left<=right;++left){
                if(s[left]==s[right]&&(right-left<=1||pair[left+1][right-1])){
                    pair[left][right]=true;
                    for(vector<string> res:resultlist[left]){
                        vector<string> dup(res);
                        dup.push_back(s.substr(left,right-left+1));
                        resultlist[right+1].push_back(dup);
                    }
                }
            }
        }
        return resultlist[size];
    }
};

int main(int argc,const char *argv[]){
    vector<vector<string>> result;
    Solution3 solution;
    string s="aab";
    result=solution.partition(s);
    for(int i=0;i<result.size();++i){
        for(int j=0;j<result[0].size();++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
