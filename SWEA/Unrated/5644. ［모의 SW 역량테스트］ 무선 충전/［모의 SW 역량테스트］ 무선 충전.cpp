#include <iostream>
#include <vector>
using namespace std;
int T, M, Ccnt, ans;//M : 이동 시간 , Ccnt : 충전소 개수
int dy[5] = { 0,-1,0,1,0 };
int dx[5] = { 0,0,1,0,-1 };
int Amove[101];//이동 정보
int Bmove[101];
struct Charger{
	int x, y,dis, power;
};
struct Coord {
	int x, y;
};
Coord Apos, Bpos; //A,B 위치
Charger ch[8];//충전소 정보
vector<int> canA;//A가 충전할수 있는 곳
vector<int> canB;//B가 충전할수 있는 곳

void input() {
	cin >> M >> Ccnt;
	for (int i = 1; i <= M; i++) {
		cin >> Amove[i];
	}
	Amove[0] = 0;
	for (int i = 1; i <= M; i++) {
		cin >> Bmove[i];
	}
	Bmove[0] = 0;
	for (int i = 0; i < Ccnt; i++) {
		cin >> ch[i].x >> ch[i].y >> ch[i].dis >> ch[i].power;
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		Apos = { 1,1 };
		Bpos = { 10,10 };
		input();
		for (int m = 0; m <= M; m++) {
			//위치이동
			Apos.x = Apos.x + dx[Amove[m]];
			Apos.y = Apos.y + dy[Amove[m]];
			Bpos.x = Bpos.x + dx[Bmove[m]];
			Bpos.y = Bpos.y + dy[Bmove[m]];
			//충전가능한곳 검사
			canA.resize(0);
			canB.resize(0);
			for (int i = 0; i < Ccnt; i++) {
				if (abs(Apos.x - ch[i].x) + abs(Apos.y - ch[i].y) <= ch[i].dis)canA.push_back(i);
				if (abs(Bpos.x - ch[i].x) + abs(Bpos.y - ch[i].y) <= ch[i].dis)canB.push_back(i);
			}
			//충전 경우의수 돌리기, 돌리면서 maxi초기화
			int maxi = 0;
			int amount;
			if (canA.size() == 0 && canB.size() == 0)amount = 0;
			else if (canA.size() == 0) {
				for (int b = 0; b < canB.size(); b++) {
					amount = ch[canB[b]].power;
					maxi = max(maxi,amount);
				}
			}
			else if (canB.size() == 0) {
				for (int a = 0; a < canA.size(); a++) {
					amount = ch[canA[a]].power;
					maxi = max(maxi, amount);
				}
			}
			for (int a = 0; a < canA.size(); a++) {
				for (int b = 0; b < canB.size(); b++) {
					if (canA[a] == canB[b])amount = ch[canA[a]].power / 2 + ch[canB[b]].power / 2;
					else amount = ch[canA[a]].power + ch[canB[b]].power;
					maxi = max(maxi, amount);
				}
			}
			//정답에 maxi더하기
			ans += maxi;
		}//이동시간 for문 끝
		cout << "#" << tc << " " << ans << "\n";
	}//tc for 문 끝
}