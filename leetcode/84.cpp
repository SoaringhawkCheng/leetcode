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
        stack<int> mstack;
        heights.push_back(0);
        int maxarea=0;
        int index=0;
        while(index<heights.size()){
            if(mstack.empty()||heights[index]>heights[mstack.top()])
                mstack.push(index++);
            else{
                int tmp=mstack.top();
                mstack.pop();
                maxarea=max(maxarea,heights[tmp]*(mstack.empty()?index:index-mstack.top()-1));
            }
        }
        return maxarea;
    }
};

int main(int argc,const char *argv[]){
    vector<int> heights={2,1,5,6,2,3};
    Solution s;
    cout<<s.largestRectangleArea(heights)<<endl;
    return 0;
}
