#include <iostream>
using namespace std;
int red[5];
int mag[5][8];
int spins[20][2]; //자석 번호 , 회전 방향
int spinnow[5];
int T, K;
void input() {
	cin >> K;
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> mag[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> spins[i][0] >> spins[i][1];
	}
}
void init() {
	for (int i = 1; i <=4; i++) {
		red[i] = 0;
		spinnow[i] = 0;
	}
}
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		int score = 0;
		for (int i = 0; i < K; i++) {
			for (int s = 1; s <= 4; s++) {
				spinnow[s] = 0;
			}
			spinnow[spins[i][0]] = spins[i][1];

			for (int d = spins[i][0] + 1; d <= 4; d++) {//오른쪽 자석 확인
				if (mag[d - 1][(red[d - 1] + 2) % 8] != mag[d][(red[d] + 6) % 8])spinnow[d] = spinnow[d - 1] * (-1);
			}
			for (int d = spins[i][0] - 1; d>0; d--) {//왼쪽 자석 확인
				if (mag[d + 1][(red[d + 1] + 6) % 8] != mag[d][(red[d] + 2) % 8])spinnow[d] = spinnow[d + 1] * (-1);
			}
			for (int j = 1; j <= 4; j++) {
				if (spinnow[j] == 1)red[j] = (red[j] + 7) % 8;//시계방향
				if (spinnow[j] == -1)red[j] = (red[j] + 1) % 8;
			}
		}//K for문 끝
		if (mag[1][red[1]] == 1)score+=1;
		if (mag[2][red[2]] == 1)score+=2;
		if (mag[3][red[3]] == 1)score+=4;
		if (mag[4][red[4]] == 1)score+=8;
		cout << "#" << tc << " " << score<<"\n";
	}//tc for문 끝
}
/*1
2
0 0 1 0 0 1 0 0
1 0 0 1 1 1 0 1
0 0 1 0 1 1 0 0
0 0 1 0 1 1 0 1
1 1
3 -1*/