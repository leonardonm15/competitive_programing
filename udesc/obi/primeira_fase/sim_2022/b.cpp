#include <bits/stdc++.h>

using namespace std;

int get_sum(int numero) {
    int s = numero;
    int s2 = numero;
    int soma = 0;
    while (s2 > 0) {
        s = s2 % 10;
        soma = soma + s;
        s2 = s2/10;
    }
    return soma;
}

int main() {
    int n, m, s; cin >> n >> m >> s;
    int m_num = -1;
    for (int i=n; i <= m; i++) {
        int sdig = get_sum(i);
        if (sdig == s && i > m_num) m_num = i;
    }
    cout << m_num << endl;
}
