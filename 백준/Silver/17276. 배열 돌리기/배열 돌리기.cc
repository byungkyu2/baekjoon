#include <iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	int dy[8] = { -1,-1,-1,0,1,1,1,0 };
	int dx[8] = { -1,0,1,1,1,0,-1,-1 };
	for (int tc = 0; tc < t; tc++) {
		int arr[500][500];
		int ans[500][500] = { 0 };
		int n, deg;
		cin >> n >> deg;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int c = n / 2;
		ans[c][c] = arr[c][c];
		for (int p = 1; p <= c; p++) { //8방 뻗어나가기
			for(int d=0;d<8;d++){//방향벡터돌리기
				int ny = c + p * dy[d];
				int nx = c + p * dx[d];
				int ay = c + p * dy[(8 + d - (deg / 45)) % 8];
				int ax = c + p * dx[(8 + d - (deg / 45)) % 8];
				ans[ny][nx] = arr[ay][ax];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ans[i][j] == 0) {
					ans[i][j] = arr[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
}