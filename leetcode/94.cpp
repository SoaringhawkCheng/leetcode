//
//  94.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/9.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        stack<TreeNode *> stk;
        while(root){
            stk.push(root);
            root=root->left;
        }
        while(!stk.empty()){
            root=stk.top();
            stk.pop();
            result.push_back(root->val);
            if(root->right){
                root=root->right;
                while(root){
                    stk.push(root);
                    root=root->left;
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        stack<TreeNode *> stk;
        while(!stk.empty()||root){
            if(root){
                stk.push(root);
                root=root->left;
            }
            else{
                root=stk.top();
                stk.pop();
                result.push_back(root->val);
                root=root->right;
            }
        }
        return result;
    }
};

class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        while(root){
            if(!root->left){
                result.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode *node=root->left;
                while(node->right&&node->right!=root) node=node->right;
                if(!node->right) {
                    node->right=root;
                    root=root->left;
                }
                else{
                    node->right=NULL;
                    result.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return result;
    }
};

class Solution4 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        _inorderTraversal(root);
        return result;
    }
private:
    vector<int> result;
    void _inorderTraversal(TreeNode *root){
        if(!root) return;
        _inorderTraversal(root->left);
        result.push_back(root->val);
        _inorderTraversal(root->right);
    }
};

int main(int argc,const char *argv[]){
    vector<TreeNode> tree={0,1,2,3,4,5,6,7,8,9};
    tree[1].left=&tree[2];
    tree[1].right=&tree[7];
    tree[2].left=&tree[3];
    tree[2].right=&tree[4];
    tree[4].left=&tree[5];
    tree[4].right=&tree[6];
    tree[7].right=&tree[8];
    tree[8].left=&tree[9];
    Solution3 s;
    vector<int> result=s.inorderTraversal(&tree[1]);
    for(auto res:result) cout<<res<<" ";
    cout<<endl;
}
