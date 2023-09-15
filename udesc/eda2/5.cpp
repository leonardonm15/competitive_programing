#include <bits/stdc++.h>

using namespace std;

int min9(int a, int b, int c) {
    int d = min(a, b);
    d = min(d, c);
    return d;
}

signed main() {
	string a, b; cin >> a >> b;
	int m = a.size();
	int n = b.size();
	int leven[m + 1][n + 1];
	for (int i=0; i < m; i++) leven[i][0] = i;
	for (int i=0; i < n; i++) leven[0][i] = i;
	for (int i=1; i <= m; i++) {
		for (int j=1; j <= n; j++) {
            int custo = 0;
			if (a[i] != b[j]) custo++;
			leven[i][j] = min9(leven[i - 1][j] + 1,
                              leven[i - 1][j - 1] + custo,
                              leven[i][j - 1] + 1);
		}
	}
	cout << "resp --- " << leven[m - 1][n - 1] << endl;
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            cout << leven[i][j] << " ";
        }
        cout << endl;
    }
}

