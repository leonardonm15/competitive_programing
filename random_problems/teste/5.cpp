#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 2 1 1 1
    std::string tf1, vqr1, tf2, vqr2; cin >> tf1 >> vqr1 >> tf2 >> vqr2;
    long long taxa1 = stod(tf1) * 1e5;
    long long valor1 = stod(vqr1) * 1e5; // valor por km rodado

    long long taxa2 = stod(tf2) * 1e5;
    long long valor2 = stod(vqr2) * 1e5;


    if (taxa1 == taxa2 && valor1 == valor2) {
        cout << "Tanto Faz" << endl;
        return 0;
    }

    if (taxa1 == taxa2) {
        cout << (valor1 > valor2 ? "Empresa 2" : "Empresa 1") << endl;
        return 0;
    }

    if (valor1 == valor2) {
        cout << ( taxa1 < taxa2 ? "Empresa 1" : "Empresa 2") << endl;
        return 0;
    }

    if (taxa1 > taxa2 && valor1 > valor2) {
        cout <<  "Empresa 2" << endl;
        return 0;
    }

    if (taxa2 > taxa1 && valor2 > valor1) {
        cout <<  "Empresa 1" << endl;
        return 0;
    }

    /* cout << "taxa1 -> " << taxa1 << endl; */
    /* cout << "taxa2 -> " << taxa2 << endl; */

    /* cout << "valor1 -> " << valor1 << endl; */
    /* cout << "valor2 -> " << valor2 << endl; */
    double igual_em = (taxa2 - taxa1) / (valor1 - valor2);

    cout << "igual_em _> " << igual_em << endl;

    std::string menor = (taxa2 - taxa1 > 0 ? "1" : "2");
    std::string maior = (menor == "1" ? "2" : "1");

    std::string num_text = std::to_string(igual_em);
    std::string resp = num_text.substr(0, num_text.find(".")+2);


    cout << ( "Empresa " + menor + " quando a distância é " + resp + ", Tanto faz quando a distância é = " + resp + ", Empresa " + " quando a distância é > " + resp ) << endl;
}
