#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
		
	if (n == 1) {
		cout << "? " << 0 << endl;
		int resp; cin >> resp;
		if (resp) cout << "! " << 0 << endl;
		else cout << "! " << 1 << endl;
		return;
	}


	bool flag = true;
	string sufixo;
	string prefixo;
	while (sufixo.size() + prefixo.size() < n) {
		while (flag && sufixo.size() < n) {
			sufixo.push_back('0');
			cout << "? " << sufixo << endl;
			int resp; cin >> resp;
			if (resp == 1) continue;
			else {
				sufixo.pop_back();
				sufixo.push_back('1');
				cout << "? " << sufixo << endl;
				cin >> resp;
				if (resp == 0) {
					flag = false;
					sufixo.pop_back();
				}
			}
		}

		// cout << "sufixo -> " << sufixo << endl;

		if ((int) sufixo.size() == n) break;

		while (!flag && prefixo.size() + sufixo.size() < n) {
			string aux = "0";
			aux += prefixo;
			aux += sufixo;
			cout << "? " << aux << endl;
			int resp; cin >> resp;

			if (!resp) aux = "1";
			else aux = "0";
			
			string aux2 = aux;
			aux2 += prefixo;
			prefixo = aux2;
		}
	}

	string r = prefixo;
	r += sufixo;

	cout << "! " << r << endl;
}

signed main() {
	int tc; cin >> tc;
	while (tc--) solve();
}
