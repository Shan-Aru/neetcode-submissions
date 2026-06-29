/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode(-1);
        ListNode*t1=l1;
        ListNode*t2=l2;
        ListNode*temp=dummy;
        int carry=0;
        while(t1!=NULL || t2!=NULL)
        {
            int sum=carry;
            if(t1!=NULL)
            {
                sum+=t1->val;
                t1=t1->next;
            }
            if(t2!=NULL)
            {
                sum+=t2->val;
                t2=t2->next;
            }
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
        }
        if(carry!=0)
        {
            temp->next=new ListNode(carry);
            temp=temp->next;
        }
        return dummy->next;
    }
};
