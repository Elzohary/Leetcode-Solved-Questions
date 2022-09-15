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
    void reorderList(ListNode* head) {
	
	if (head->next == nullptr)
		return;

	// At first, I need to know where is the middle of the list!
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* prev = nullptr;

	while (fast != nullptr && fast->next != nullptr)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	prev->next = nullptr;

	ListNode* list1 = head;
	ListNode* list2 = reverse(slow);

	Merge(list1, list2);

}

// reverse
ListNode* reverse(ListNode* head)
{
	ListNode* current = head;
	ListNode* next = current->next;
	ListNode* prev = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

// Merge
void Merge(ListNode* l1, ListNode* l2)
{
	while (l1 != nullptr)
	{
		ListNode* p1 = l1->next;
		ListNode* p2 = l2->next;

		l1->next = l2;
		if (p1 == nullptr)
			break;

		l2->next = p1;

		l1 = p1;
		l2 = p2;
	}
}
};