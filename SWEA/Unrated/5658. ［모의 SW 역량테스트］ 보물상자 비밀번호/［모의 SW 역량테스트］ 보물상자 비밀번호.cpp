#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;
		string s;
		cin >> s;
		s += s;
		vector<string> v;
		vector<string> v_parse;
		for (int i = 0; i < N; i++) {
			v.push_back(s.substr(i,N/4));
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			if (i == 0 || v[i] != v[i - 1])
				v_parse.push_back(v[i]);
		}
		string ansstr = v_parse[v_parse.size() - K];
		int ans = 0;
		int temp = 1;
		for (int i = ansstr.size() - 1; i >= 0; i--) {
			if (ansstr[i] >= '0'&&ansstr[i] <= '9') {
				ans +=temp* int(ansstr[i] - '0');
			}
			else {
				ans +=temp* int(ansstr[i] - 'A' + 10);
			}
			temp *= 16;
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}