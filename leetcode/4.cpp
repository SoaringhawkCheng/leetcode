//
//  4.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/5/14.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        int size1=nums1.size();
        int size2=nums2.size();
        int total=size1+size2;
        if(total%2)
            return find_kth(nums1.begin(), size1, nums2.begin(), size2, total/2+1);
        else
            return (find_kth(nums1.begin(), size1, nums2.begin(), size2, total/2)+find_kth(nums1.begin(), size1, nums2.begin(), size2, total/2+1))/2.0;
    }
private:
    int find_kth(vector<int>::iterator iter1,int size1,vector<int>::iterator iter2,int size2,int k){
        if(size1==0) return *(iter2+k-1);
        if(size1>size2) return find_kth(iter2, size2, iter1, size1, k);
        if(k==1) return min(*iter1,*iter2);
        
        int left=min(k/2,size1),right=k-left;
        if(*(iter1+left-1)<*(iter2+right-1))
            return find_kth(iter1+left, size1-left, iter2, size2, k-left);
        else if(*(iter1+left-1)>*(iter2+right-1))
            return find_kth(iter1, size1, iter2+right, size2-right, k-right);
        else
            return *(iter1+left-1);
    }
};

int main(int argc,const char *argv[]){
    vector<int> nums1={2};
    vector<int> nums2;
    Solution s;
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
