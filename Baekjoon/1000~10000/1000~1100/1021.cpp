#include <cstdio>
#include <queue>

std::deque<int> deque;

void rotate_left() {
	int value = deque.front();
	deque.pop_front();
	deque.push_back(value);
}

void rotate_right() {
	int value = deque.back();
	deque.pop_back();
	deque.push_front(value);
}

int find_index(int idx) {
	int index = 0;
	std::deque<int>::iterator iter;
	for (iter = deque.begin(); iter < deque.end(); iter++, index++) {
		if (*iter == idx) return index;
	}
}

int main() {
	int size, n;
	scanf("%d %d", &size, &n);
	for (int i = 1; i <= size; i++) {
		deque.push_back(i);
	}

	int rotate_balance = 0;
	while (n--) {
		int idx;
		scanf("%d", &idx);
		if (idx == deque.front()) {
			deque.pop_front();
			continue;
		}
		else {
			int index = find_index(idx);
			if (index < deque.size() - index) {
				while (deque.front() != idx) {
					rotate_left();
					rotate_balance++;
				}
				deque.pop_front();
			}
			else {
				while (deque.front() != idx) {
					rotate_right();
					rotate_balance++;
				}
				deque.pop_front();
			}
		}
	}
	printf("%d\n", rotate_balance);
}