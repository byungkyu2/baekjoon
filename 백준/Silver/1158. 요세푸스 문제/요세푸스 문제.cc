#include <iostream>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	int arr[5001];
	int temp[5001];
	int ans[5001];
	for (int i = 1; i <= N; i++) {
		arr[i]=i;
		temp[i] = i;
	}
	for (int i = 0; i < N; i++) {
		int ppl = 0;
		ppl = (ppl + K) % (N - i);
		if (ppl == 0)ppl = N - i;
		ans[i] = arr[ppl];
		for (int j = 1; j < N - i; j++) {
			int t = (ppl + j) % (N - i);
			if (t == 0)t = N - i;
			temp[j] = arr[t];
		}
		for (int j = 1; j < N - i; j++) {
			arr[j] = temp[j];
		}
	}
	cout << "<";
	for (int i = 0; i < N-1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[N-1]<<">";
}