#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	unordered_map<string,int> um;
	vector<string> v;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		um.insert({ str,i });
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string bo;
		cin >> bo;
		if (um.find(bo) == um.end())continue;
		cnt++;
		v.push_back(bo);
	}
	sort(v.begin(), v.end());
	cout << cnt<<"\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}