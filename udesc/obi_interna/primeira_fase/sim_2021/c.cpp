#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << endl;
    map<char, vector<int>> mapa;
    vector<int> freq(13, 0);
    char arr[5] = {'C', 'E', 'U', 'P'};
    mapa['C'] = freq;
    mapa['E'] = freq;
    mapa['U'] = freq;
    mapa['P'] = freq;
    
    string in; cin >> in;
    for (int i=2; i < in.size(); i += 3) {
        char np = in[i];
        string carta; 
        carta.push_back(in[i - 2]);
        carta.push_back(in[i - 1]);
        int num = stoi(carta);
        num--;
        mapa[np][num]++;
    }
    for (int i=0; i < 4; i++) {
        int saida = 13;
        string erro = "erro";
        bool flag_erro = false;
        for (int j=0; j < 13; j++) {
            if (mapa[arr[i]][j] > 1) {
                flag_erro = true;
                break;
            } else if (mapa[arr[i]][j] == 1) {
                saida--;
            }
        }
        if (flag_erro) cout << erro << endl;
        else cout << saida << endl;
    }
}
