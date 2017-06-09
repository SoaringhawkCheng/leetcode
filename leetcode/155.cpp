//
//  155.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/7.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack1 {//方法1，双栈法
public:
    /** initialize your data structure here. */
    MinStack1() {
    }
    
    void push(int x) {
        stk.push(x);
        if(mstk.empty()||x<=getMin())//考虑空栈情况，<=使用line28重复pop相同的最小值成为可能
            mstk.push(x);
    }
    
    void pop() {
        if(stk.empty()) return;
        if(stk.top()==getMin()) mstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
private:
    stack<int> stk;
    stack<int> mstk;//存放当前最小值
};

class MinStack2 {//使用链表
private:
    class ListNode{
    public:
        ListNode(int val,int minval,ListNode *next=NULL):val(val),minval(minval),next(next){}
    public:
        int val;
        int minval;
        ListNode *next;
    };
public:
    /** initialize your data structure here. */
    MinStack2():head(NULL) {
        
    }
    
    void push(int x) {
        if(head==NULL) head=new ListNode(x,x);
        else head=new ListNode(x,min(x,head->minval),head);
    }
    
    void pop() {
        if(head==NULL) return;
        ListNode *tmp=head;
        head=head->next;
        delete tmp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minval;
    }
private:
    ListNode *head;
};

class MinStack3 {
public:
    /** initialize your data structure here. */
    MinStack3():minimum(INT_MAX) {
        
    }
    
    void push(int x) {
        if(x<=minimum){
            stk.push(minimum);
            minimum=x;
        }
        stk.push(x);
    }
    
    void pop() {
        if(minimum==stk.top()){
            stk.pop();
            minimum=stk.top();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minimum;
    }
private:
    stack<int> stk;
    int minimum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(int argc,const char *argv[]){
    vector<int> nums={8,5,7,1,4,2};
    MinStack mstk;
    for(auto num:nums) mstk.push(num);
    for(int i=0;i<nums.size();++i){
        cout<<"min="<<mstk.getMin()<<endl;
        cout<<"top="<<mstk.top()<<endl;
        mstk.pop();
    }
    return 0;
}
