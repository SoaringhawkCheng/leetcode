//
//  84.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/19.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> stk;
        heights.push_back(0);
        int maxvol=0;
        for(int i=0;i<heights.size();++i){
            while(!stk.empty()&&heights[i]<=heights[stk.top()]){
                int top=stk.top();
                stk.pop();
                maxvol=max(maxvol,heights[top]*(stk.empty()?i:i-stk.top()-1));
            }
            stk.push(i);
        }
        return maxvol;
    }
};

int main(int argc,const char *argv[]){
    vector<int> heights={2,1,5,6,2,3};
    Solution s;
    cout<<s.largestRectangleArea(heights)<<endl;
    return 0;
}
