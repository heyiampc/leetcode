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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        ListNode* temp=head;
        while(temp)
        {
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p1=dummy;
        for(auto &x:mp)
        {
            if(x.second==1)
            {
                ListNode* newnode= new ListNode(x.first);
                dummy->next=newnode;
                dummy=dummy->next;
            }
        }
        return p1->next;
    }
};