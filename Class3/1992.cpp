#include <iostream>
#include <string>
using namespace std;

int graph[64][64];

int check(int x, int y, int size){
	int result = graph[x][y];
	for (int i = x; i < size + x; i++) {
		for (int j = y; j < size + y; j++) {
			if (result != graph[i][j]) result = -1;
		}
	}
	return result;
}

void divide_and_conquer(int x, int y, int size) {
	int result = check(x, y, size);
	if (result == -1) {
		cout << '(';
		divide_and_conquer(x, y, size / 2);
		divide_and_conquer(x, y + size / 2, size / 2);
		divide_and_conquer(x + size / 2, y, size / 2);
		divide_and_conquer(x + size / 2, y + size / 2, size / 2);
		cout << ')';
	}
	else {
		cout << result;
	}
}

int main()
{
	int N;
	string input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			graph[i][j] = input[j] - 48;
		}
	}

	divide_and_conquer(0, 0, N);

	return 0;
}
