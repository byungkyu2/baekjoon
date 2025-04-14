#include <iostream>
using namespace std;
#include <string>
int main() {
	int n, m;
	cin >> n >> m;
	string str[50];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'X') {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			ans1++;
		}
	}
	for (int j = 0; j < m; j++) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (str[i][j] == 'X') {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			ans2++;
		}
	}

	cout << max(ans1,ans2);
}