/*
Add Two Numbers - LeetCode

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        
        ListNode* t = l1;
        while(t){
            len1++;
            t = t->next;
        }

        t = l2;
        while(t){
            len2++;
            t = t->next;
        }

        if(len2>len1){
            t = l1;
            l1 = l2;
            l2 = l1;
        }

        t = l1;

        int sum = 0, carry = 0;
        while(t){
            if(l2){
                sum = t->val + l2->val;
                sum = sum%10;
                carry = sum/10;

                l2 = l2->next;
            }
            else{
                sum = t->val + carry;
                sum = sum%10;
                carry = sum/10;
            }

            if(!(t->next)) break;
            t = t->next;
        }

        if(carry) t->next = new ListNode(carry);

        return l1;
    }
};