#include <iostream>
#include <vector>
#include <queue>
// BOJ - 1655 Say Middle
using namespace std;

priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

int main(void) {
	int n, num;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (i == 0)
			maxheap.push(num);
		else if (i == 1) {
			if (num > maxheap.top())
				minheap.push(num);
			else {
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(num);
			}
		}
		else {
			maxheap.push(num);

			if (maxheap.top() > minheap.top()) {
				maxheap.pop();
				minheap.push(num);
				if (minheap.size() > maxheap.size()) {
					maxheap.push(minheap.top());
					minheap.pop();
				}
			}
			if (maxheap.size() - minheap.size() > 1) {
				minheap.push(maxheap.top());
				maxheap.pop();
			}
		}

		cout << maxheap.top() << '\n';
	}

	return 0;
}