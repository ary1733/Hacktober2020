#include <bits/stdc++.h>
using namespace std;

int main() {




	int n;

	cin >> n;

	int count = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 0; j--) {
			if (j >= i)
			{
				cout << count << " ";
				count++;
			}

		}
		cout << endl;
		count = 1;
	}

	return 0;
}