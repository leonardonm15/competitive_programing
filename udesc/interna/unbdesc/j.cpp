#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, vida; cin >> n >> vida;
    long long magias = 0;
    vector<long long> arr(n);
    long long soma = 0;
    for (long long i=0; i < n; i++) {
        cin >> arr[i];
        soma += arr[i];
    }
    long long rot;
    if (vida > soma) {
        rot = vida / soma; 
        vida -= soma * rot;
        magias += rot * n;
    }
    int i = 0;
    while (vida > 0) {
        vida -= arr[i];
        magias++;
        i++;
    }
    cout << magias << endl;

}
