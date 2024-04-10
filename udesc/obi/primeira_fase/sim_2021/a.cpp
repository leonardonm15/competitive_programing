#include <bits/stdc++.h>

using namespace std;

int main() {
    int pontos = 0;
    for (int i=0; i < 6; i++) {
        char ponto;
        cin >> ponto;
        if (ponto == 'V') pontos++;
    }
    cout << pontos << endl;
    if (pontos == 5 || pontos == 6) cout << 1 << endl;
    if (pontos == 3 || pontos == 4) cout << 2 << endl;
    if (pontos == 1 || pontos == 2) cout << 3 << endl;
    if (pontos == 0) cout << -1 << endl;
}
