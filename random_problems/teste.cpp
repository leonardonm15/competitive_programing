#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'findCapableWinners' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY power_type_a
 *  2. INTEGER_ARRAY power_type_b
 *  3. INTEGER_ARRAY power_type_c
 */

void bb(int l, int r, int k, vector<pair<int, int>>& arr, vector<int>& freq) {
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (arr[mid].first > k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    for (int i = ans; i < (int) arr.size(); i++) {
        freq[arr[i].second]++;
    }
}

int solve(vector<int> power_type_a, vector<int> power_type_b, vector<int> power_type_c) {
    int n = power_type_a.size();

    vector<pair<int, int>> a(n);
    vector<pair<int, int>> b(n);
    vector<pair<int, int>> c(n);

    for (int i = 0; i < n; i++) {
        a[i].first = power_type_a[i];
        a[i].second = i;

        b[i].first = power_type_b[i];
        b[i].second = i;

        c[i].first = power_type_c[i];
        c[i].second = i;    
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    // pra eu vencer uma linha eu preciso ter uma carta maior doq a maior
    vector<int> win(n);
    int counter = 0;
    int va = 0;
    int vb = 0;
    int vc = 0;
    for (int i = 0; i < n; i++) {
        if (win[a[i].second] == 1) {
            va = a[i].first;
            counter++;
        }
        if (win[b[i].second] == 1) {
            vb = b[i].first;
            counter++;
        }
        if (win[c[i].second] == 1) {
            vc = c[i].first;
            counter++;
        }
        win[a[i].second]++;
        win[b[i].second]++;
        win[c[i].second]++;
        if (counter == n) break;
    }

    vector<int> freq(n);

    bb(0, n - 1, va, a, freq);
    bb(0, n - 1, vb, b, freq);
    bb(0, n - 1, vc, c, freq);

    int resp = 0;
    for (int i = 0; i < n; i++) {
        if (freq[i] > 1) resp++;
    }

    return resp;
}

int main() {
    
    solve(a, b, c);
}
