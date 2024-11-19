#include <string>
#include <vector>
#include <map>
#include <algorithm>  // para std::sort

#include <bits/stdc++.h> 
using namespace std;

using std::map;
using std::string;
using std::vector;

void calc(string curr_word, int index, const string& word, vector<pair<int, string>>& resp, map<string, string>& mtl) {
       if (index == word.size()) {
        int valor = 1;
        for (int i = 0; i < word.size(); i++) {
            if (curr_word[i] == '.') {
                valor *= 2;
            } else {
                valor *= 2;
                valor += 1;
            }
        }
        resp.push_back({valor, mtl[curr_word]});
        return;
    } 

    if (word[index] == '?') {
        string new_word1 = curr_word;
        string new_word2 = curr_word;
        new_word1[index] = '.';
        new_word2[index] = '-';
        calc(new_word1, index + 1, word, resp, mtl);
        calc(new_word2, index + 1, word, resp, mtl);
    } else {
        calc(curr_word, index + 1, word, resp, mtl);
    }
}

vector<string> possibilities(const string& word) {
    map<string, string> mtl = {
        {".-", "A"},    {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"}, 
        {".", "E"},     {"..-.", "F"}, {"--.", "G"},  {"....", "H"},
        {"..", "I"},    {".---", "J"}, {"-.-", "K"},  {".-..", "L"},
        {"--", "M"},    {"-.", "N"},   {"---", "O"},  {".--.", "P"},
        {"--.-", "Q"},  {".-.", "R"},  {"...", "S"},  {"-", "T"},
        {"..-", "U"},   {"...-", "V"}, {".--", "W"},  {"-..-", "X"},
        {"-.--", "Y"},  {"--..", "Z"}
    };
    
    vector<pair<int, string>> s;
    calc(word, 0, word, s, mtl);
    
    sort(s.begin(), s.end());

    vector<string> resp;
    for (auto c: s) resp.push_back(c.second);

    cout << "resp -> ";
    for (auto c: resp) cout << c << " ";
    cout << endl;

    return resp;
}

signed main() {
    possibilities(".");
    possibilities(".-");
    possibilities("?");
    possibilities("?.");
    possibilities(".?");
    possibilities("?-?");

    return 0;
}
