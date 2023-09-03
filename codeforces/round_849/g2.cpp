#include <bits/stdc++.h>
 
using namespace std;
 
int solve(int q_moedas, deque<int>&vec) {
    sort(vec.begin(), vec.end());
    int teleports = 0;
    while (vec.size() > 0 && q_moedas >= vec[0]) {
        q_moedas -=  vec[0];
        vec.pop_front();
        teleports++;
    }
    return teleports;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, c; cin >> n >> c;
        deque<int> arr(n);
        deque<int> prec_l_r(n); // valores vindo da esquerda
        deque<int> prec_r_l(n); // valores vindo da direita
        deque<int> prec_diff(n); // valores vindo da direita
        deque<int> clone1_dq = arr;
        deque<int> clone2_dq = arr;
        deque<int> clone3_dq = arr;
        int i_menor;
        int menor;
        int resp;
        for (int i=0; i < n; i++) {
            int num1; cin >> num1;
            int num2 = num1;
            num1 += i + 1;
            num2 = n - (i + 1);
            if (i == 0) menor = num1;
            if (num1 < menor) {
                i_menor = i;
                menor = num1;
            }
            prec_l_r[i] = num1;
            prec_r_l[n - (i+1)] = num2;
            prec_diff[i] = num1 - num2;
        }
        if (i_menor < n/2) {
            clone1_dq = prec_l_r;
            c -= prec_l_r[i_menor];
            clone1_dq.erase(clone1_dq.begin() + i_menor);
            resp = solve(c, clone1_dq);
            cout << solve << endl;
        } else {
            int c1 = c;
            int c2 = c;
            menor = clone3_dq[n/2];
            for (int i=n/2; i < n; i++) {
                if (clone3_dq[i] < menor) {
                    menor = clone3_dq[i];
                    i_menor = i;
                }
            }
            c1 -= prec_l_r[i_menor];
            clone3_dq.erase(c1, clone3.begin() + i_menor);
            solve(c1, clone3_dq)
            // 1 2 3 4 5 6
            // 2 4 6 8 10 12 efeito colateral seria o cara cara eu pego
            // 7 7 7 7 7 7

        }
    }
}
