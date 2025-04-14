#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[1000][5];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	int dat[1000] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < 5; k++) {
				if (arr[i][k] == arr[j][k]) {
					dat[i]++;
					dat[j]++;
					break;
				}
			}
		}
	}
	int ans = 0;
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		if (maxi < dat[i]) {
			maxi = dat[i];
			ans = i;
		}
	}
	cout << ans + 1;
}