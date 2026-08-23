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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr!=NULL)
        {
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        if(n==1){
            ListNode*deleted=prev;
            prev=prev->next;
            delete deleted;
        }
        else{
            ListNode*temp=prev;
            for(int i=1;i<n-1;i++)
            {
                temp=temp->next;
            }
            ListNode*deleted=temp->next;
            temp->next=temp->next->next;
            delete deleted;
        }
        curr=prev;
        prev=NULL;
        while(curr!=NULL)
        {
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};
