//
//  18.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/16.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {//使用sort对结果排序和erase unique去重
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;++i){
            for(int j=i+1;j<nums.size()-2;++j){
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                        result.push_back({nums[i],nums[j],nums[k],nums[l]});
                        ++k,--l;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]<target) ++k;
                    else --l;
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {//每一层循环进行剪枝，删除循环
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;++i){
            if(i&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[nums.size()-3]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            for(int j=i+1;j<nums.size()-2;++j){
                if(j!=i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    int sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        result.push_back({nums[i],nums[j],nums[k],nums[l]});
                        do{++k;}while(k<l&&nums[k]==nums[k-1]);
                        do{--l;}while(k<l&&nums[l]==nums[l+1]);
                    }
                    else if(sum<target) ++k;
                    else --l;
                }
            }
        }
        return result;
    }
};

class Solution3 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        
        unordered_map<int,vector<pair<int,int>>> cache;
        for(int a=0;a<nums.size();++a)
            for(int b=a+1;b<nums.size();++b)
                cache[nums[a]+nums[b]].push_back(pair<int,int>(a,b));
        for(int c=0;c<nums.size();++c) {
            for(int d=c+1;d<nums.size();++d) {
                int key=target-nums[c]-nums[d];
                if(cache.find(key)==cache.end()) continue;
                auto &vec=cache[key];
                for(int k=0;k<vec.size();++k){
                    if(c<=vec[k].second) continue;
                    result.push_back({nums[vec[k].first],nums[vec[k].second],nums[c],nums[d]});
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

class Solution4 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        for(auto num:nums) cout<<num<<" ";
        cout<<endl;
        unordered_multimap<int,pair<int,int>> cache;
        for(int i=0;i<nums.size();++i)
            for(int j=i+1;j<nums.size();++j)
                cache.insert(make_pair(nums[i]+nums[j],make_pair(i,j)));
        
        for(auto i=cache.begin();i!=cache.end();++i){
            int partialsum=target-i->first;
            auto range=cache.equal_range(partialsum);
            for(auto j=range.first;j!=range.second;++j){
                auto a=i->second.first;
                auto b=i->second.second;
                auto c=j->second.first;
                auto d=j->second.second;
                if(a!=c&&a!=d&&b!=c&&b!=d){
                    vector<int> vec={nums[a],nums[b],nums[c],nums[d]};
                    sort(vec.begin(),vec.end());
                    result.push_back(vec);
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={1,0,-1,0,-2,2,4,-2,3,-5,1,-1};
    vector<vector<int>> result;
    Solution s;
    result=s.fourSum(nums, 0);
    for(auto res:result){
        cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<" "<<res[3]<<endl;
    }
    return 0;
}
