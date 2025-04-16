#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unordered_map<int, int> um;
	vector<int> ans;
	int n, m;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		um[card]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		ans.push_back(um[num]);
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
}