/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node*temp=head;
        while(temp!=NULL)
        {
            Node*copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        Node*dummy=new Node(-1);
        Node*res=dummy;
        temp=head;
        while(temp!=NULL)
        {
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
    return dummy->next;
    }
};
