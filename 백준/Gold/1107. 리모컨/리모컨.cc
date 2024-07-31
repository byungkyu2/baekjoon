#include <iostream>
using namespace std;
int main() {
	int n, m;
	int btn[10] = { -1 };
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> btn[i];
	}
	int min=abs(n-100);
	int i = 0;
	while (i < 1000000) {
		int temp = i;
		int counts = 1;

		int gojang = 0;
		while (temp >= 10) {//고장난버튼의 번호가 있는지 검사
			for (int b = 0; b < m; b++) {
				if (temp % 10 == btn[b]) {
					gojang = 1;
					break;
				}
			}
			if (gojang == 1) {
				break;
			}
			temp = temp / 10;
			counts++;
		}

		for (int b = 0; b < m; b++) {
			if (temp== btn[b]) {
				gojang = 1;
			}
		}
		if (gojang == 0) {
			if (i >= n) {
				counts += (i - n);

			}
			else {
				counts = counts + (n - i);
			}
		}
		if (counts <= min && gojang == 0) {
			min = counts;
		}
		
		i++;
	}
	cout << min;
	return 0;
}