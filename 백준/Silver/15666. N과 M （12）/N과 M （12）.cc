#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int arr[10001];
vector<int> inp;
vector<int> v;
void func(int now, int k) {
	if (now == M) {
		for (int i = 0; i < M; i++) {
			cout << inp[v[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = k; i < inp.size(); i++) {
		v.push_back(i);
		func(now + 1, i);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 1)inp.push_back(i);
	}
	for (int i = 0; i < inp.size(); i++) {
		v.push_back(i);
		func(1,i);
		v.pop_back();
	}
}