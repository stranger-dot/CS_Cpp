#include <iostream>

using namespace std;

struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print (ListNode *head) {
		ListNode *tmp = head;

		while (tmp) {
				cout << tmp->val << "\n";
				tmp = tmp->next;
		}
}

ListNode* reverse (ListNode *head) {
		ListNode *tmp = head;

		ListNode *prev = nullptr;

		while (tmp) {
				ListNode *next = tmp->next;
				tmp->next = prev;
				prev = tmp;
				tmp = next;
		}

		return prev;
}

int main() {
		ListNode *node = new ListNode(1);
		node->next = new ListNode(2);
		node->next->next = new ListNode(3);

		ListNode *rNode = reverse(node);

		print(rNode);

		return 0;
}
