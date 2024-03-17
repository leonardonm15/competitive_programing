#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

#define _GLIBCXX_DEBUG
 
 
string to_string(const string& s);
string to_string(const char* s);
string to_string(const char c);
string to_string(bool b);
string to_string(__int128_t i);
template<size_t TAM> string to_string(bitset<TAM> v);
string bin(long long number, int bits);
template<typename A> string to_string(A v);
template<typename T> string to_string(queue<T> q);
template<typename T> string to_string(priority_queue<T> pq);
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
template <typename A, typename B, typename C, typename D, typename E> string to_string(tuple<A, B, C, D, E> p);
template <typename A, typename B, typename C, typename D, typename E, typename F> string to_string(tuple<A, B, C, D, E, F> p);
 
// basics
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(const char c) { string u; u += c; return '\'' + u + '\''; }
string to_string(bool b) { return (b ? "True" : "False"); }
string to_string(__int128_t i){ return to_string((long long)(i)); }
 
//bitset
template<size_t TAM> string to_string(bitset<TAM> v) { string res = ""; for (size_t i = 0; i < TAM; i++) res += int('0' + v[i]); reverse(begin(res), end(res)); return res; }
 
// binario
string bin(long long number, int bits = 16){ string binary = ""; while(bits--){ binary.push_back((number & 1)+'0'); number >>= 1; } reverse(begin(binary), end(binary)); return binary; }
 
// iteravel
template<typename A> string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
 
// queue
template<typename T> string to_string(queue<T> q){ string res = "{"; while(!q.empty()){ res += to_string(q.front()); q.pop(); if(!q.empty()) res += ", "; } res += "}"; return res; }
 
// priority_queue
template<typename T> string to_string(priority_queue<T> pq){ string res = "{"; while(!pq.empty()){ res += to_string(pq.top()); pq.pop(); if(!pq.empty()) res += ", "; } res += "}"; return res; }
 
// array
template<typename T> vector<T> vec(T* arr, int n = 10){ vector<T> temp; for(int it = 0; it < n; it++){ temp.emplace_back(arr[it]); } return temp; }
 
//pair
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
 
// tuplas
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
template <typename A, typename B, typename C, typename D, typename E> string to_string(tuple<A, B, C, D, E> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ", " + to_string(get<4>(p)) + ")"; }
template <typename A, typename B, typename C, typename D, typename E, typename F> string to_string(tuple<A, B, C, D, E, F> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ", " + to_string(get<4>(p)) + ", " + to_string(get<5>(p)) + ")"; }
 
 
void _debug() { }
template <typename X, typename... Y>
void _debug(X head, Y... tail) {
    if(sizeof...(tail)) {
        cerr << to_string(head); cerr << ", "; _debug(tail...);
    } else {
        cerr << to_string(head);
    }
}
 
#define debug(x...) cerr << "[" << #x << "] = [", _debug(x), cerr << "]" << endl

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> arr(n + 1);
    vector<int> freq(n + 1);
    vector<int> vis(n + 1);
    for (int i=0; i < n; i++) {
        arr[i].second = i;
        int num; cin >> num;
        arr[num].first++;
        arr[num].second = num;
    }

    arr[n].second = n;


    sort(arr.begin(), arr.end());
    /* debug(arr); */

    int k = -1;
    int resp = 1e9 + 5;
    while (arr[++k].first == 0) {
        resp = min(resp, arr[k].second);
    }
    /* cout << "k -> " << k << endl; */
    /* k++; */
    for (int i=k; i <= n; i++) {
        if (arr[i].first <= arr[i].second) {
            resp = min(resp, arr[i].second + 1);
            /* return; */
        }
    }
    
    if (resp == 1e9 + 5) cout << arr[n].second << endl;
    else cout << resp << endl;


    /* cout << "resp -> "; */
    /* for (int i=0; i < n; i++) { */
    /*     if (freq[resp[i]] == 0) continue; */
    /*     else { */
    /*         cout << resp[i] << " "; */
    /*     } */
    /* } */

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
