#include <bits/stdc++.h>
     
using namespace std;
     
int main() {
       long r, l, mid, resp;
       l = 1;
       r = 1000000;
       int c = 1;
       while (l <= r) {
            mid = (r + l) / 2;
            cout << mid << endl;
            string op;
            cin >> op;
            if (op == "<") r = mid - 1;
            if (op == ">=") {
		    l = mid + 1;
		    resp = mid;
	    }
       }
	cout << "! " << resp << endl;
}
