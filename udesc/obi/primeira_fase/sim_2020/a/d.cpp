#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> freq(n + 2, 0);
    vector<int> win(n + 2, 0);
    for (int i=0; i < m; i++) {
        int p, k; cin >> p >> k;
        if (freq[p] == 0) {
            win[p] = 1;
            freq[p] = 1;
        }
        for (int j=1; j < k + 1; j++) { 
            int num; cin >> num;
            if(freq[num] == 0) freq[num] = 1;
            else win[num] = 0;
        }
    }
    for(int i=0; i < n + 2; i++) {
        if (win[i] == 1) {
            cout << i << endl;
        }
    }
}
