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
    int pairSum(ListNode* head) {
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        int maxi=0;
        
        for(int i=0;i<nums.size()/2;i++)
        {
            int calc=nums[i]+nums[nums.size()-i-1];
            maxi=max(maxi,calc);
        }
        return maxi;
    }
};