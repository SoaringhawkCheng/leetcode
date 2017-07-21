//
//  188.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/20.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

//#include <iostream>
//#include <vector>
//#include <stack>
//#include <set>
//using namespace std;
//
//class Solution {
//public:
//    int maxProfit(int k, vector<int>& prices) {
//        int size=prices.size();
//        stack<pair<int,int>> vp_pairs;
//        int minimum;
//        bool start=true;
//        prices.push_back(INT_MIN);
//        for(int index=0;index<size;++index){
//            if(start){
//                minimum=prices[index];
//                start=false;
//            }
//            if(prices[index]>prices[index+1]){
//                start=true;
//                if(prices[index]-minimum>0){
//                    if(vp_pairs.empty()) vp_pairs.push(make_pair(minimum, prices[index]));
//                    else{
//                        
//                    }
//                }
//            }
//        }
//    }
//};
//
//int main(int argc,const char *argv[]){
//    Solution s;
//    vector<int> prices={1,2,4,2,5,7,2,4,9,0};
//    cout<<s.maxProfit(2, prices)<<endl;
//    
//    return 0;
//}
