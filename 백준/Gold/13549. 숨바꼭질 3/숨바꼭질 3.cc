#include <iostream>
#include <queue>
using namespace std;

int main() {
	int visited[100001] = { 0 };
	int n, k;
	cin >> n >> k;
	queue<int> q;
	visited[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == k)break;
		int temp = now;
		while (temp <= 100000) {
			temp *= 2;
			if (temp == 0||temp>100000)break;
			if (visited[temp] != 0)continue;
			visited[temp] = visited[now];
			q.push(temp);
		}
		if (now - 1 >= 0 && visited[now - 1] == 0) {
			visited[now - 1] = visited[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 <= 100000 && visited[now + 1] == 0) {
			visited[now + 1] = visited[now] + 1;
			q.push(now + 1);
		}
		
	}
	cout << visited[k] - 1;
}