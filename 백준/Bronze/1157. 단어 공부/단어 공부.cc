#include <iostream>
using namespace std;
#include <string>
int main() {
	string str;
	cin >> str;
	int arr[26] = { 0 };
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			arr[str[i] - 'a']++;
		}
		else {
			arr[str[i] - 'A']++;
		}
	}
	int maxi = 0;
	int ans=0;
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (maxi < arr[i]) {
			maxi = arr[i];
			ans = i;
			flag = 0;
		}
		else if (maxi == arr[i]) {
			flag = 1;
		}
	}
	if (flag == 1) {
		cout << '?';
	}
	else {
		cout << char('A' + ans);
	}
}