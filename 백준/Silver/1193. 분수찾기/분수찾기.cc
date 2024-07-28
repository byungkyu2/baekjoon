#include<iostream>
using namespace std;
int main() {
	long long int X;
	cin >> X;
	int N = 1;
	while (1) {
		if ((N - 1) * N / 2 < X&& (N + 1) * N / 2 >= X) {
			break;
		}
		N++;
	}
	int i, j;
	int endOfLine = (N + 1) * N / 2;
	if (X == 1) {
		i = 1;
		j = 1;
	}
	else if (N % 2 == 1) {
		j = N - (endOfLine- X);
		i = N + 1 - j;
	}
	else if (N % 2 == 0) {
		i = N - (endOfLine - X);
		j = N + 1 - i;
	}
	cout << i << "/" << j;
	return 0;
}