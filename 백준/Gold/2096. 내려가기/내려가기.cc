#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int mn[2][6];
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (i == 0) {
			mn[0][0]=a;
			mn[0][1] = b;
			mn[0][2] = c;
			mn[0][3] = a;
			mn[0][4] = b;
			mn[0][5] = c;
		}
		else {
			int temp = min(mn[0][0], mn[0][1]);
			mn[1][0]=(temp + a);
			mn[1][1]=(min(temp, mn[0][2]) + b);
			mn[1][2]=(min(mn[0][1], mn[0][2]) + c);
			temp = max(mn[0][3], mn[0][4]);
			mn[1][3]=(temp + a);
			mn[1][4]=(max(temp, mn[0][5]) + b);
			mn[1][5]=(max(mn[0][4], mn[0][5]) + c);
			for (int i = 0; i < 6; i++) {
				mn[0][i] = mn[1][i];
			}
		}
	}
	int maxans = max(mn[0][3], mn[0][4]);
	maxans = max(maxans, mn[0][5]);
	int minans = min(mn[0][0], mn[0][1]);
	minans = min(minans, mn[0][2]);
	cout << maxans << " " << minans;
}