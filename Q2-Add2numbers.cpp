#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int i,n,sum(0);
        ListNode* node, *head = new ListNode;
        node = head;
        
        while(l1 || l2 || sum){

            if(l1!=nullptr)
                i=l1->val;
            else
                i=0;
            if(l2!=nullptr)
                n=l2->val;
            else
                n=0;
            
            sum+=i+n;
            node->val = sum%10; sum/=10;

            if(l1!=nullptr)
                l1 = l1->next;
            if(l2!=nullptr)
                l2 = l2->next;

            if(l1!=nullptr || l2!=nullptr || bool(sum)){
                node->next = new ListNode;
                node = node->next;
            }
            else node->next = nullptr;


            

        }
        
        return head;
    }
};

int main()
{
    // Test listeleri
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Sonucu yazdır
    while (result)
    {
        cout << result->val;
        if (result->next)
            cout << " -> ";
        result = result->next;
    }
    cout << endl;

    return 0;
}