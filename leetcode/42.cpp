//
//  42.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/8/20.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution1 {//暴力法,居然过了
public:
    int trap(vector<int>& height) {
        int volume=0;
        int size=height.size();
        for(int i=1;i<size-1;++i){
            int lefthigh=0;
            for(int j=i-1;j>=0;--j) lefthigh=max(lefthigh,height[j]);
            int righthigh=0;
            for(int j=i+1;j<size;++j) righthigh=max(righthigh,height[j]);
            int bar=min(lefthigh,righthigh);
            if(bar>height[i])
                volume+=bar-height[i];
        }
        return volume;
    }
};

class Solution2 {//动态规划，暴力法优化,存储每个节点左右两边的高峰值
public:
    int trap(vector<int>& height) {
        int volume=0;
        int size=height.size();
        vector<int> leftmax(size,0);
        vector<int> rightmax(size,0);
        for(int i=1;i<size;++i)
            leftmax[i]=max(leftmax[i-1],height[i-1]);
        for(int i=size-2;i>=0;--i)
            rightmax[i]=max(rightmax[i+1],height[i+1]);
        for(int i=1;i<size-1;++i){
            int bar=min(leftmax[i],rightmax[i]);
            if(bar>height[i]) volume+=bar-height[i];
        }
        return volume;
    }
};

class Solution3 {//使用栈，建立一个值递减的栈
public:
    int trap(vector<int>& height) {
        int volume=0;
        int size=height.size();
        stack<int> stk;
        for(int i=0;i<size;++i){
            while(!stk.empty()&&height[i]>=height[stk.top()]){
                int top=stk.top();
                stk.pop();
                if(stk.empty()) break;
                int distance=i-stk.top()-1;
                volume+=distance*min(height[i]-height[top],height[stk.top()]-height[top]);
            }
            stk.push(i);
        }
        return volume;
    }
};

class Solution4 {//使用两个指针从左右两边往中间逼近
public:
    int trap(vector<int> &height){
        int volume=0;
        int size=height.size();
        int left=0,right=height.size()-1;
        int left_max=0,right_max=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=left_max) left_max=height[left];
                else volume+=left_max-height[left];
                ++left;
            }
            else{//height[left]>=height[right]
                if(height[right]>=right_max) right_max=height[right];
                else volume+=right_max-height[right];
                --right;
            }
        }
        return volume;
    }
};

int main(int argc,const char *argv[]){
    vector<int> height={2,0,2};
    Solution4 s;
    cout<<s.trap(height)<<endl;
    return 0;
}
