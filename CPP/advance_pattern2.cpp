#include <bits/stdc++.h>
using namespace std;

int main() {




	int n;
	cin >> n;



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			//cout << ans << " ";

			if ((i + j) % 2 == 0) {
				cout << "1 ";
			} else {
				cout << "0 ";
			}
			//(ans == 0) ? ans = 1 : ans = 0;
		}
		cout << endl;
	}


	return 0;
}