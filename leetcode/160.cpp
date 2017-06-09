//
//  160.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution1 {//我的蠢方法
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *positionA,*positionB;
        positionA=headA;
        positionB=headB;
        while(positionA&&positionB){
            positionA=positionA->next;
            positionB=positionB->next;
        }
        int distance=0;
        if(positionA){
            while(positionA){
                ++distance;
                positionA=positionA->next;
            }
            for(int i=0;i<distance;++i)
                headA=headA->next;
        }
        else{
            while(positionB){
                ++distance;
                positionB=positionB->next;
            }
            for(int i=0;i<distance;++i)
                headB=headB->next;
        }
        while(headA&&headB&&headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        if (p1 == NULL || p2 == NULL) return NULL;
        
        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            
            //
            // Any time they collide or reach end together without colliding
            // then return any one of the pointers.
            //
            if (p1 == p2) return p1;
            
            //
            // If one of them reaches the end earlier then reuse it
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning,
            // they will be equidistant from the collision point.
            //
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }
        
        return p1;
    }
};

class Solution3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1?cur1->next:headB;
            cur2 = cur2?cur2->next:headA;
        }
        return cur1;
    }
};

int main(int argc,const char *argv[]){
    ListNode list1[2]={1,2};
    ListNode list2[3]={3,4,5};
    list1[0].next=&list1[1];
    list2[0].next=&list2[1];
    list2[1].next=&list2[2];
    Solution2 s;
    ListNode *inter=s.getIntersectionNode(&list1[0], &list2[0]);
    cout<<(inter==NULL?0:inter->val)<<endl;
    
    return 0;
}
