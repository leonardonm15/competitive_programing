#include <bits/stdc++.h>

using namespace std;
#define int long long


// ### NOTES ###
// ordena os caras
// faz prefix sum de todos os caras 
// faz lower bound pra ver de quantos cara pra tras ele vai comer
// come esses caras e acmula no h
// faz lower bound dnv até o iterador jogar pra um cara maior que ele
// quamdo jogar pra um cara maior que ele poppa um dos blue ou green
// vai acc o poder dele

void solve () {
    int n, h; cin >> n >> h;
    vector<int> arr;
    vector<int> p(n + 1);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    p[0] = 0;
    int acc = 0;
    int i = 1;
    int blue = 1;
    int green = 2;
    for (auto cara: arr) {
        acc = cara / 2;
        p[i] = acc;
        i++;
    }
    // busca binaria no termo <= 
    // soma o termo dps
    // busca binaria dnv até o mid dar um cara maior que ele, ai poppa a pot
    int last_position = 0;
    while (blue + green > 0 && last_position < n) {
        int l = 0;
        int r = n;
        int mid = (l + r) / 2;
        while (arr[mid] != h && l > r) {
            if (arr[mid] < h) {
                l = mid + 1;
            }
            else if (arr[mid] > h) {
                r = mid - 1;
            } else break;
        }
        cout << "mid -> " << mid << endl;
        if (mid > h) {
            // talvez aqui nao tenha cara menor que ele 
            // se isso for vdd poppa os caras azul e verde
            mid--;
            last_position = mid;
            l = mid;
            if (blue > 0) {
                h *= 2;
                blue--;
            } else if (green > 0) {
                h *= 3;
                green--;
            }
        } else {
            cout << "las_position -> " << last_position << endl;
            h += p[mid] - p[last_position];
            last_position = mid;
        }
    }
    cout << last_position << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
