#include <iostream>
#include <vector>
using namespace std;
int T, N;
int arr[16][16];
int visited[16];
int ans;
vector<int> fA;
vector<int> fB;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}
void dfs(int now,int k) {
	if (now == N / 2) {
		fA.resize(0);
		fB.resize(0);
		for (int i = 0; i < N; i++) {
			if (visited[i] == 0)fA.push_back(i);
			else fB.push_back(i);
		}
		int tA = 0;
		int tB = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				tA += arr[fA[i]][fA[j]];
				tB += arr[fB[i]][fB[j]];
			}
		}
		ans = min(ans, abs(tA - tB));
		return;
	}
	for (int i = k + 1; i < N; i++) {
		visited[i] = 1;
		dfs(now + 1, i);
		visited[i] = 0;
	}
}
int main(){
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 21e8;
		input();
		for (int i = 0; i < N; i++) { 
			visited[i] = 1;
			dfs(1, i);
			visited[i] = 0;
		}
		cout << "#" << tc << " " << ans<<"\n";
	}
}