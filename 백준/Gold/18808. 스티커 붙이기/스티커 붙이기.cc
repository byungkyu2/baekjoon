#include <iostream>
using namespace std;
int main() {
	int note[40][40] = { 0 };
	int n, m, k;
	int ans = 0;
	cin >> n >> m >> k;
	for (int stk = 0; stk < k; stk++) {
		int sticker[4][10][10];
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[0][i][j];
				sticker[1][j][r - 1 - i] = sticker[0][i][j];
				sticker[2][r - 1 - i][c - 1 - j] = sticker[0][i][j];
				sticker[3][c - 1 - j][i] = sticker[0][i][j];
			}
		}
		int pasted = 0;
		for (int rot = 0; rot < 4; rot++) {
			if (pasted == 1)break;
			int nr, nc;
			if (rot % 2 == 0) {
				nr = r;
				nc = c;
			}
			else {
				nr = c;
				nc = r;
			}
			for (int y = 0; y < n - nr + 1; y++) {
				for (int x = 0; x < m - nc + 1; x++) {
					if (pasted == 1)break;
					int canpaste = 1;
					for (int i = 0; i < nr; i++) {
						for (int j = 0; j < nc; j++) {
							if (sticker[rot][i][j] == 0)continue;//스티커가 0
							if (note[y + i][x + j] == 0)continue;//노트가 빈칸
							canpaste = 0;//붙일 수 없음
						}
					}
					if (canpaste == 1) {
						for (int i = 0; i < nr; i++) {
							for (int j = 0; j < nc; j++) {
								if (sticker[rot][i][j] == 1) { 
									note[y + i][x + j] = 1;
									ans++;
								}
							}
						}
						pasted = 1;
					}
				}
			}
		}
	}
	cout << ans;
}