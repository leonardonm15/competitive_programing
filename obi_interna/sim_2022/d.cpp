#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    map<int, int> freq;
    int ps[n + 1];
    ps[0] = 0;
    freq[0]++;
    int l = 0;
    int r = 0;
    int resp = 0;
    int soma = 0;
    for (int i=1; i < n + 1; i++) {
        int num; cin >> num;
        soma += num;
        ps[i] = soma;
        int b = ps[i] - k;
        resp += freq[b];
        freq[soma]++;
    }
    cout << resp << endl;
}
