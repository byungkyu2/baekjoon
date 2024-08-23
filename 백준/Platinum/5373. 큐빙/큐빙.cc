#include <iostream>
#include <string>
using namespace std;
string cube1[9] = {
//12345678901
"xxxoooxxxxxx",//0
"xxxoooxxxxxx",//1
"xxxoooxxxxxx",//2
"gggwwwbbbyyy",//3
"gggwwwbbbyyy",//4
"gggwwwbbbyyy",//5
"xxxrrrxxxxxx",//6
"xxxrrrxxxxxx",//7
"xxxrrrxxxxxx",//8
};
string cube[9];

void up() {
	char tempf1 = cube[3][3];
	char tempf2 = cube[3][4];
	cube[3][3] = cube[5][3];
	cube[3][4] = cube[4][3];
	cube[5][3] = cube[5][5];
	cube[4][3] = cube[5][4];
	cube[5][5] = cube[3][5];
	cube[5][4] = cube[4][5];
	cube[3][5] = tempf1;
	cube[4][5] = tempf2;
	char side1 = cube[2][3];
	char side2 = cube[2][4];
	char side3 = cube[2][5];
	cube[2][3] = cube[5][2];
	cube[2][4] = cube[4][2];
	cube[2][5] = cube[3][2];
	cube[5][2] = cube[6][5];
	cube[4][2] = cube[6][4];
	cube[3][2] = cube[6][3];
	cube[6][5] = cube[3][6];
	cube[6][4] = cube[4][6];
	cube[6][3] = cube[5][6];
	cube[3][6] = side1;
	cube[4][6] = side2;
	cube[5][6] = side3;

}
void um() {
	char tempf1 = cube[3][3];
	char tempf2 = cube[3][4];
	cube[3][3] = cube[3][5];
	cube[3][4] = cube[4][5];
	cube[3][5] = cube[5][5];
	cube[4][5] = cube[5][4];
	cube[5][5] = cube[5][3];
	cube[5][4] = cube[4][3];
	cube[5][3] = tempf1;
	cube[4][3] = tempf2;
	char side1 = cube[2][3];
	char side2 = cube[2][4];
	char side3 = cube[2][5];
	cube[2][3] = cube[3][6];
	cube[2][4] = cube[4][6];
	cube[2][5] = cube[5][6];
	cube[3][6] = cube[6][5];
	cube[4][6] = cube[6][4];
	cube[5][6] = cube[6][3];
	cube[6][5] = cube[5][2];
	cube[6][4] = cube[4][2];
	cube[6][3] = cube[3][2];
	cube[5][2] = side1;
	cube[4][2] = side2;
	cube[3][2] = side3;
}
void dm() {
	char tempf1 = cube[3][9];
	char tempf2 = cube[3][10];
	cube[3][9] = cube[3][11];
	cube[3][10] = cube[4][11];
	cube[3][11] = cube[5][11];
	cube[4][11] = cube[5][10];
	cube[5][11] = cube[5][9];
	cube[5][10] = cube[4][9];
	cube[5][9] = tempf1;
	cube[4][9] = tempf2;
	char side1 = cube[0][5];
	char side2 = cube[0][4];
	char side3 = cube[0][3];
	cube[0][5] = cube[3][0];
	cube[0][4] = cube[4][0];
	cube[0][3] = cube[5][0];
	cube[3][0] = cube[8][3];
	cube[4][0] = cube[8][4];
	cube[5][0] = cube[8][5];
	cube[8][3] = cube[5][8];
	cube[8][4] = cube[4][8];
	cube[8][5] = cube[3][8];
	cube[5][8] = side1;
	cube[4][8] = side2;
	cube[3][8] = side3;
}
void dp() {
	char tempf1 = cube[3][9];
	char tempf2 = cube[3][10];
	cube[3][9] = cube[5][9];
	cube[3][10] = cube[4][9];
	cube[5][9] = cube[5][11];
	cube[4][9] = cube[5][10];
	cube[5][11] = cube[3][11];
	cube[5][10] = cube[4][11];
	cube[3][11] = tempf1;
	cube[4][11] = tempf2;
	char side1 = cube[0][5];
	char side2 = cube[0][4];
	char side3 = cube[0][3];
	cube[0][5] = cube[5][8];
	cube[0][4] = cube[4][8];
	cube[0][3] = cube[3][8];
	cube[5][8] = cube[8][3];
	cube[4][8] = cube[8][4];
	cube[3][8] = cube[8][5];
	cube[8][3] = cube[3][0];
	cube[8][4] = cube[4][0];
	cube[8][5] = cube[5][0];
	cube[3][0] = side1;
	cube[4][0] = side2;
	cube[5][0] = side3;
}
void fp() {
	char tempf1 = cube[6][3];
	char tempf2 = cube[6][4];
	cube[6][3] = cube[8][3];
	cube[6][4] = cube[7][3];
	cube[7][3] = cube[8][4];
	cube[8][3] = cube[8][5];
	cube[8][4] = cube[7][5];
	cube[8][5] = cube[6][5];
	cube[6][5] = tempf1;
	cube[7][5] = tempf2;
	char side1 = cube[5][3];
	char side2 = cube[5][4];
	char side3 = cube[5][5];
	cube[5][3] = cube[5][0];
	cube[5][4] = cube[5][1];
	cube[5][5] = cube[5][2];
	cube[5][2] = cube[5][11];
	cube[5][1] = cube[5][10];
	cube[5][0] = cube[5][9];
	cube[5][11] = cube[5][8];
	cube[5][10] = cube[5][7];
	cube[5][9] = cube[5][6];
	cube[5][6] = side1;
	cube[5][7] = side2;
	cube[5][8] = side3;
}
void fm() {
	char tempf1 = cube[6][3];
	char tempf2 = cube[6][4];
	cube[6][3] = cube[6][5];
	cube[6][4] = cube[7][5];
	cube[6][5] = cube[8][5];
	cube[7][5] = cube[8][4];
	cube[8][5] = cube[8][3];
	cube[8][4] = cube[7][3];
	cube[8][3] = tempf1;
	cube[7][3] = tempf2;
	char side1 = cube[5][3];
	char side2 = cube[5][4];
	char side3 = cube[5][5];
	cube[5][3] = cube[5][6];
	cube[5][4] = cube[5][7];
	cube[5][5] = cube[5][8];
	cube[5][6] = cube[5][9];
	cube[5][7] = cube[5][10];
	cube[5][8] = cube[5][11];
	cube[5][9] = cube[5][0];
	cube[5][10] = cube[5][1];
	cube[5][11] = cube[5][2];
	cube[5][0] = side1;
	cube[5][1] = side2;
	cube[5][2] = side3;

}
void bp() {
	char tempf1 = cube[0][3];
	char tempf2 = cube[0][4];
	cube[0][3] = cube[2][3];
	cube[0][4] = cube[1][3];
	cube[1][3] = cube[2][4];
	cube[2][3] = cube[2][5];
	cube[2][4] = cube[1][5];
	cube[2][5] = cube[0][5];
	cube[0][5] = tempf1;
	cube[1][5] = tempf2;
	char side1 = cube[3][3];
	char side2 = cube[3][4];
	char side3 = cube[3][5];
	cube[3][3] = cube[3][6];
	cube[3][4] = cube[3][7];
	cube[3][5] = cube[3][8];
	cube[3][6] = cube[3][9];
	cube[3][7] = cube[3][10];
	cube[3][8] = cube[3][11];
	cube[3][9] = cube[3][0];
	cube[3][10] = cube[3][1];
	cube[3][11] = cube[3][2];
	cube[3][0] = side1;
	cube[3][1] = side2;
	cube[3][2] = side3;
}
void bm() {
	char tempf1 = cube[0][3];
	char tempf2 = cube[0][4];
	cube[0][3] = cube[0][5];
	cube[0][4] = cube[1][5];
	cube[0][5] = cube[2][5];
	cube[1][5] = cube[2][4];
	cube[2][5] = cube[2][3];
	cube[2][4] = cube[1][3];
	cube[2][3] = tempf1;
	cube[1][3] = tempf2;
	char side1 = cube[3][3];
	char side2 = cube[3][4];
	char side3 = cube[3][5];
	cube[3][3] = cube[3][0];
	cube[3][4] = cube[3][1];
	cube[3][5] = cube[3][2];
	cube[3][0] = cube[3][9];
	cube[3][1] = cube[3][10];
	cube[3][2] = cube[3][11];
	cube[3][9] = cube[3][6];
	cube[3][10] = cube[3][7];
	cube[3][11] = cube[3][8];
	cube[3][6] = side1;
	cube[3][7] = side2;
	cube[3][8] = side3;
}
void lp() {
	char tempf1 = cube[3][0];
	char tempf2 = cube[3][1];
	cube[3][1] = cube[4][0];
	cube[3][0] = cube[5][0];
	cube[4][0] = cube[5][1];
	cube[5][0] = cube[5][2];
	cube[5][1] = cube[4][2];
	cube[5][2] = cube[3][2];
	cube[3][2] = tempf1;
	cube[4][2] = tempf2;
	char side1 = cube[0][3];
	char side2 = cube[1][3];
	char side3 = cube[2][3];
	cube[0][3] = cube[5][11];
	cube[1][3] = cube[4][11];
	cube[2][3] = cube[3][11];
	cube[5][11] = cube[6][3];
	cube[4][11] = cube[7][3];
	cube[3][11] = cube[8][3];
	cube[8][3] = cube[5][3];
	cube[7][3] = cube[4][3];
	cube[6][3] = cube[3][3];
	cube[3][3] = side1;
	cube[4][3] = side2;
	cube[5][3] = side3;
}
void lm() {
	char tempf1 = cube[3][0];
	char tempf2 = cube[3][1];
	cube[3][0] = cube[3][2];
	cube[3][1] = cube[4][2];
	cube[3][2] = cube[5][2];
	cube[4][2] = cube[5][1];
	cube[5][2] = cube[5][0];
	cube[5][1] = cube[4][0];
	cube[5][0] = tempf1;
	cube[4][0] = tempf2;
	char side1 = cube[0][3];
	char side2 = cube[1][3];
	char side3 = cube[2][3];
	cube[0][3] = cube[3][3];
	cube[1][3] = cube[4][3];
	cube[2][3] = cube[5][3];
	cube[3][3] = cube[6][3];
	cube[4][3] = cube[7][3];
	cube[5][3] = cube[8][3];
	cube[6][3] = cube[5][11];
	cube[7][3] = cube[4][11];
	cube[8][3] = cube[3][11];
	cube[5][11] = side1;
	cube[4][11] = side2;
	cube[3][11] = side3;
}
void rp() {
	char tempf1 = cube[3][7];
	char tempf2 = cube[3][6];
	cube[3][7] = cube[4][6];
	cube[3][6] = cube[5][6];
	cube[4][6] = cube[5][7];
	cube[5][6] = cube[5][8];
	cube[5][7] = cube[4][8];
	cube[5][8] = cube[3][8];
	cube[4][8] = tempf1;
	cube[3][8] = tempf2;
	char side1 = cube[2][5];
	char side2 = cube[1][5];
	char side3 = cube[0][5];
	cube[2][5] = cube[5][5];
	cube[1][5] = cube[4][5];
	cube[0][5] = cube[3][5];
	cube[5][5] = cube[8][5];
	cube[4][5] = cube[7][5];
	cube[3][5] = cube[6][5];
	cube[8][5] = cube[3][9];
	cube[7][5] = cube[4][9];
	cube[6][5] = cube[5][9];
	cube[3][9] = side1;
	cube[4][9] = side2;
	cube[5][9] = side3;

}
void rm() {
	char tempf1 = cube[3][6];
	char tempf2 = cube[3][7];
	cube[3][6] = cube[3][8];
	cube[3][7] = cube[4][8];
	cube[3][8] = cube[5][8];
	cube[4][8] = cube[5][7];
	cube[5][8] = cube[5][6];
	cube[5][7] = cube[4][6];
	cube[5][6] = tempf1;
	cube[4][6] = tempf2;
	char side1 = cube[2][5];
	char side2 = cube[1][5];
	char side3 = cube[0][5];
	cube[2][5] = cube[3][9];
	cube[1][5] = cube[4][9];
	cube[0][5] = cube[5][9];
	cube[3][9] = cube[8][5];
	cube[4][9] = cube[7][5];
	cube[5][9] = cube[6][5];
	cube[8][5] = cube[5][5];
	cube[7][5] = cube[4][5];
	cube[6][5] = cube[3][5];
	cube[5][5] = side1;
	cube[4][5] = side2;
	cube[3][5] = side3;

}
void turn(string str) {
	if (str == "U+")up();
	if (str == "U-")um();
	if (str == "D+")dp();
	if (str == "D-")dm();
	if (str == "F+")fp();
	if (str == "F-")fm();
	if (str == "B+")bp();
	if (str == "B-")bm();
	if (str == "L+")lp();
	if (str == "L-")lm();
	if (str == "R+")rp();
	if (str == "R-")rm();
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		for (int i = 0; i < 9; i++) {
			cube[i] = cube1[i];
		}
		for (int nc = 0; nc < n; nc++) {
			string str;
			cin >> str;
			turn(str);
		}
		for (int i = 3; i < 6; i++) {
			for (int j = 3; j < 6; j++) {
				cout<<cube[i][j];
			}
			cout << "\n";
		}
	}
}