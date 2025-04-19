#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
int arr[1000000];
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	int mn = 1;
	sort(arr, arr + N);
	int mx = arr[N - 1];
	while (mn<=mx) {
		int mid = (mn + mx) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cnt += arr[i] / mid;	
		}
		if (cnt >= M) {
			ans = mid;
			mn = mid + 1;
		}
		else {
			mx = mid - 1;
		}
	}
	cout << ans;
}