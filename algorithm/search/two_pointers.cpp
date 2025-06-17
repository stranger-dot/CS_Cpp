#include <iostream>
#include <vector>

using namespace std;

//Ex.1

bool twoSum(vector<int> &v, int target) {
		int i = 0, j = v.size() - 1;
		
		while (i < j) {
				int sum = v[i] + v[j];

				if (sum == target) 
						return true;
				else if (sum < target) 
						i++;
				else 
						j--;
		}

		return false;
}

//Ex.2

long long countSubarr(vector<int> &v, int k) {
		int sz = v.size();
		int j = 0;

		long long answer = 0, sum = 0;

		for (int i = 0; i < sz; i++) {
				sum += v[i];

				while (j <= i && sum >= k) {
						sum -= v[j];
						j++;
				}

				answer += (i - j + 1);
		}

		return answer;
}

//Ex.3
/* Fast runner moves 2 steps at a time
 * Slow runner moves 1 step at a time
 * When the fast runner reaches the end of the list, 
 * the slow runner will be at the middle of the list
 */

struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* runner (ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
		}

		return slow;
}


int main() {
		vector<int> v {1, 2, 4, 7, 11, 18 ,27};
		int target = 9;

		//Ex.1
		cout << twoSum(v, target) << "\n";

		//Ex.2
		cout << countSubarr(v, 11) << "\n";

		//Ex.3
		ListNode* head = new ListNode(1);
		head->next = new ListNode(3);
		head->next->next = new ListNode(5);
		head->next->next->next = new ListNode(7);
		head->next->next->next->next = new ListNode(9);

		cout << runner(head)->val << "\n";

		while (head) {
				ListNode* temp = head;
				head = head->next;
				delete temp;
		}

		return 0;
}
