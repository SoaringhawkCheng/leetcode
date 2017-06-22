//
//  15.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/15.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
//        int min_gap=INT_MAX;
//        int result=0;
//        sort(nums.begin(),nums.end());
//        for(int i=0;i<nums.size()-2;++i){
//            if(i&&nums[i]==nums[i-1]) continue;
//            int j=i+1,k=nums.size()-1;
//            while(j<k){
//                int sum=nums[i]+nums[j]+nums[k];
//                int gap=abs(sum-target);
//                if(gap<min_gap){
//                    result=sum;
//                    min_gap=gap;
//                }
//                if(sum==target) return target;
//                else if(sum<target){
//                    ++j;
//                    while(j<k&&nums[j]==nums[j-1]) ++j;
//                }
//                else{
//                    --k;
//                    while(j<k&&nums[k]==nums[k+1]) --k;
//                }
//            }
//        }
//        return result;
//    }
//};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int target=0) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(),nums.end());
        for(auto left=nums.begin();left<nums.end()-2;++left){
            if(left!=nums.begin()&&*left==*(left-1)) continue;
            auto mid=left+1;
            auto right=nums.end()-1;
            while(mid<right){
                int sum=*left+*mid+*right;
                if(sum<target){
                    mid=mid+1;
                    while(mid<right&&*mid==*(mid-1)) ++mid;
                }
                else if(sum>target){
                    right=right-1;
                    while(mid<right&&*right==*(right+1)) --right;
                }
                else{
                    result.push_back({*left,*mid,*right});
                    ++mid,--right;
                    while(mid<right&&*mid==*(mid-1)) ++mid;
                    while(mid<right&&*right==*(right+1)) --right;
                }
            }
        }
        return result;
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums={-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> result=s.threeSum(nums);
    for(auto res:result){
        for(auto r:res) cout<<r<<" ";
        cout<<endl;
    }
    return 0;
}
