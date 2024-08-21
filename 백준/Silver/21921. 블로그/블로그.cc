#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int X, N;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int left = 0;
	int right = X - 1;
	int SUM = 0;
	for (int i = 0; i < X ; i++) {
		SUM += v[i];
	}
	int maxi = 0;
	int maxicnt = 0;
	while (right < N) {
		if (SUM > maxi) {
			maxicnt = 1;
			maxi = SUM;
		}
		else if (SUM == maxi) {
			maxicnt++;
		}
		right++;
		if (right >= N)break;
		SUM += v[right];
		SUM -= v[left];
		left++;
	}
	if (maxi == 0)cout << "SAD";
	else {
		cout << maxi << "\n" << maxicnt;
	}
}