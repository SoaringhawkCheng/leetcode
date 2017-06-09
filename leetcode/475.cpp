//
//  475.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/7.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {//暴力法超时
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int size1=houses.size();
        int size2=heaters.size();
        int res=0;
        for(int i=0;i<size1;++i){
            int mindis=INT_MAX;
            for(int j=0;j<size2;++j)
                mindis=min(mindis,abs(heaters[j]-houses[i]));
            res=max(res,mindis);
        }
        return res;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(houses.empty()) return 0;
        if(heaters.empty()) return -1;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int radius=0;
        for(int i=0,index=0;i<houses.size();++i){
            while(index<heaters.size()-1&&abs(houses[i]-heaters[index])>=abs(houses[i]-heaters[index+1]))
                ++index;
            radius=max(radius,abs(houses[i]-heaters[index]));
        }
        return radius;
    }
};
int main(int argc,const char *argv[]){
    cout<<INT_MAX<<endl;
    return 0;
}
