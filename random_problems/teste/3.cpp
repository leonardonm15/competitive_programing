#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void build(vector<string>& clock, int j, int msk) {
    if (msk & (1 << 6)) clock[0][j + 1] = '_';
    if (msk & (1 << 5)) clock[1][j] = '|';
    if (msk & (1 << 4)) clock[1][j + 1] = '_';
    if (msk & (1 << 3)) clock[1][j + 2] = '|';
    if (msk & (1 << 2)) clock[2][j] = '|';
    if (msk & (1 << 1)) clock[2][j + 1] = '_';
    if (msk & (1 << 0)) clock[2][j + 2] = '|';
}

void solve () {

    string time = "04:25";
    std::string vazio = "               ";
    std::vector<std::string> clock(3, vazio);
    clock[1][7] = '.';
    clock[2][7] = '.';
    // cada "tracinho" que um número pode ter pode ser representado por um 0 caso nao tenho o traço e um 1 caso tenha
    std::vector<int> conversor(10);
    conversor[0] = 0b1101111;
    conversor[1] = 0b0001001; // apenas os 2 que representam o 1
    conversor[2] = 0b1011110;
    conversor[3] = 0b1011011;
    conversor[4] = 0b0111001;
    conversor[5] = 0b1110011;
    conversor[6] = 0b1110111;
    conversor[7] = 0b1001001;
    conversor[8] = 0b1111111;
    conversor[9] = 0b1111011;
  
    if (time[0] != '0') build(clock, 1, conversor[time[0] - '0']);
    build(clock, 4, conversor[time[1] - '0']);
    build(clock, 9, conversor[time[3] - '0']);
    build(clock, 12, conversor[time[4] - '0']);
  
    std::string resposta;
    for (auto linha: clock) {
      resposta += linha;
      resposta += '\n';
    }
  
    cout << resposta << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
