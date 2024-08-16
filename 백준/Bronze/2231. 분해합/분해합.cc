#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int flag = 0;
	for (int i = 1; i < n; i++) {
		int temp = i;
		int hap = i;
		while (temp > 0) {
			hap += temp % 10;
			temp = temp / 10;
		}
		if (hap == n) {
			ans = i;
			break;
		}
	}
	cout << ans;
}