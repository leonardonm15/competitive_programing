#include <bits/stdc++.h>

using namespace std;

pair<int, int> get_ms(string mv) {
    if (mv == "DL") return {+1, -1};
    if (mv == "DR") return {+1, +1};
    if (mv == "UR") return {-1, +1};
    if (mv == "UL") return {-1, -1};
};

pair<int, int> update_pos(pair<int, int> pos_atual, pair<int, int> operation) {
    return {pos_atual.first + operation.first, pos_atual.second + operation.second};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        bool flag_loop = false;
        bool flag_find = false;
        int n, m, i, j, k, l;
        cin >> n >> m >> i >> j >> k >> l;
        i--;j--;k--;l--;
        // cerr << n << " " << m << " " << i << " " << j << " " << k << " " << l << endl;
        string dir;
        cin >> dir;
        string dir_inicial = dir;
        pair<int, int> pnt = {i, j}; 
        int counter = -1;
        int bounce = 0;
        int pff_me_mata = 0;
        while(flag_loop == false && flag_find == false) {
               string ultima_dir = dir;
               // cerr << "first - " << pnt.first + 1 << " second - " << pnt.second + 1 << endl;
               counter++;
               if (pnt.first == i && pnt.second == j && counter != 0){
                   cerr << "dir_inicial - dir_atual " << dir_inicial << " " << dir << endl;
                   if (dir == dir_inicial || pff_me_mata == 3) {
                       cerr << "caiu aqui" << endl;
                       flag_loop = true;
                       continue;
                   } else pff_me_mata++;
               }
               if (pnt.first == k && pnt.second == l){
                   flag_find = true; 
                   continue;
               }
               if (pnt.first == n-1 && dir == "DL") dir = "UL";// hit parede baixo
               if (pnt.first == n-1 && dir == "DR") dir = "UR"; // hit parede baixo
               if (pnt.first == 0 && dir == "UL") dir = "DL"; // hit parede cima
               if (pnt.first == 0 && dir == "UR") dir = "DR"; // hit parede cima
               if (pnt.second == 0 && dir == "DL") dir = "DR"; // hit parede esquerda 
               if (pnt.second == 0 && dir == "UL") dir = "UR"; // hit parede esquerda 
               if (pnt.second == m - 1 && dir == "UR") dir = "UL"; // hit parede direita 
               if (pnt.second == m - 1 && dir == "DR") dir = "DL"; // hit parede direita 
               if (ultima_dir != dir) {
                   bounce++;
                   // cerr << "posicao do bounce - " << pnt.first + 1 << " - " << pnt.second  + 1<< endl;
               }
               if (counter == n * m * 4) flag_loop = true;
               pair<int, int>  operation = get_ms(dir); 
               pnt = update_pos(pnt, operation);
        }
        if (flag_loop) cout << -1 << endl;
        if (flag_find) cout << bounce << endl; 
    }
}
