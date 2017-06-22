//
//  105.cpp
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
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution1 {//递归
//    typedef vector<int>::iterator Iter;
//public:
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        TreeNode *root=buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
//        return root;
//    }
//private:
//    TreeNode *buildTree(Iter pbegin,Iter pend,Iter ibegin,Iter iend){
//        if(pbegin==pend||ibegin==iend) return NULL;
//        int rootval=*pbegin;
//        TreeNode *root=new TreeNode(rootval);
//        Iter pos=find(ibegin,iend,rootval);
//        int leftsize=distance(ibegin,pos);
//        root->left=buildTree(next(pbegin),next(pbegin,leftsize+1),ibegin,pos);
//        root->right=buildTree(next(pbegin,leftsize+1),pend,next(pos),iend);
//        return root;
//    }
//};
//int main(int argc,const char *argv[]){
//    return 0;
//}
