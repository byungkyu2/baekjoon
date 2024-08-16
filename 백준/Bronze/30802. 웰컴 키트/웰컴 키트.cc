#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int arr[6];
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	int T, P;
	cin >> T >> P;
	int t = 0;
	for (int i = 0; i < 6; i++) {
		if (arr[i] % T == 0)t += arr[i] / T;
		else t += arr[i] / T + 1;
	}
	cout << t << "\n";
	cout << N / P << " " << N % P;
}