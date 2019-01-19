//절대값이 같은 음수, 양수가 있으면 음수가 더 위에 있어야 한다. 

#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
#define abs(a) (a>0 ? a : -a)

using namespace std;

vector<int> heap;

void push_heap(vector<int>& heap, int newValue) {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while (idx > 0 && (abs(heap[(idx - 1) / 2]) > abs(heap[idx]) || ((abs(heap[(idx - 1) / 2]) == abs(heap[idx]) && heap[(idx - 1) / 2] > heap[idx])))) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = ((idx - 1) / 2);
	}
}

void pop_heap(vector<int>& heap) {
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size()) {
			break;
		}
		int next = here;
		if (abs(heap[next]) > abs(heap[left])) {
			next = left;
		}
		else if (abs(heap[next]) == abs(heap[left]) && heap[next] > heap[left]) {
			next = left;
		}

		if (right < heap.size() && abs(heap[next]) > abs(heap[right]))
			next = right;
		else if (right < heap.size() && abs(heap[next]) == abs(heap[right]) && heap[next] > heap[right]) {
			next = right;
		}
		if (next == here)
			break;
		swap(heap[here], heap[next]);
		here = next;
	}
	
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if(k!=0)
			push_heap(heap,k);
		else {
			if (!heap.empty()) {
				cout << heap[0] << endl;
				pop_heap(heap);
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	
	return 0;
}