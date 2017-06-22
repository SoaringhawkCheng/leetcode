//
//  106.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/9.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <vector>
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x):val(x),left(NULL),right(NULL){}
//};
//
//class Solution1 {//递归
//    typedef vector<int>::iterator Iter;
//public:
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        TreeNode *head=buildTree(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
//        return head;
//    }
//private:
//    TreeNode *buildTree(Iter ibegin,Iter iend,Iter pbegin,Iter pend){
//        if(ibegin==iend||pbegin==pend) return NULL;
//        int rootval=*prev(pend);
//        TreeNode *root=new TreeNode(rootval);
//        Iter rootpos=find(ibegin,iend,rootval);
//        int leftsize=distance(ibegin,rootpos);
//        root->left=buildTree(ibegin,rootpos,pbegin,next(pbegin,leftsize));
//        root->right=buildTree(next(rootpos),iend,next(pbegin,leftsize),prev(pend));
//        return root;
//    }
//};
