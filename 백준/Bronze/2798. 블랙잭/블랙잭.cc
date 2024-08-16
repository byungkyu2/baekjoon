#include <iostream>
using namespace std;
int arr[100];
int N, M;
int mingap = 21e8;
int sum = 0;
void dfs(int now, int k) {
	if (now == 3) {
		mingap = min(mingap,M-sum );
		return;
	}
	for (int i = k + 1; i < N; i++) {
		if (sum + arr[i] > M)continue;
		sum += arr[i];
		dfs(now + 1, i);
		sum -= arr[i];
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		dfs(1, i);
		sum -= arr[i];
	}
	cout << M - mingap;
}