#include <bits/stdc++.h>

using namespace std;
// algo de prefix sum
int main() {
    int t;
    cin >> t;
    while(t--) {
            int n, q;
            cin >> n >> q;
            long long arr[n + 1];
            int soma = 0;
            for (int i=0; i<n + 1; i++) {
		    if (i == 0) {
			    arr[i] = 0;
			    continue;
		    }
                    int numero;
                    cin >> numero;
    		    soma += numero;
                    arr[i] = soma;
            }
            for (int i=0; i<q; i++) {
		    int nova_soma = soma;
                    int rangei, rangef, ns;
                    cin >> rangei >> rangef >> ns;
		    int sum = arr[rangef] - arr[rangei - 1];
		    int compare = ns * ((rangef - rangei) + 1) - sum;
		    nova_soma += compare;
		    if (nova_soma % 2 != 0) cout << "YES" << endl;
		    else cout << "NO" << endl;
            }
    }
}


