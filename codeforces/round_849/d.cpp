#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<char, int> freqr;
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i=0; i < n; i++) {
            freqr[s[i]]++;
        }
        // cerr << freqr.size() << endl;
        map<char, int> freql;
        int soma = 0;
        for (int i=0; i < n; i++) {
            char curr_char = s[i];
            freqr[curr_char]--;
            if (freqr[curr_char] == 0) freqr.erase(freqr.find(curr_char));
            freql[curr_char]++;
            int curr_soma = freql.size() + freqr.size();
            if ( curr_soma > soma) soma = curr_soma;
        }
        cout << soma << endl;
    }
} 
