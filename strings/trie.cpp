#include <bits/stdc++.h>
using namespace std;

struct Trie {
    const int ALPHA = 26;
    const char START = 'A';
    vector<vector<int>> trie;
    vector<int> end;

    Trie() {
        trie.assign(1, vector<int>(ALPHA, -1));
        end.assign(1, 0);
    }

    void add_word(const string &s) {
        int curr = 0;
        const int N = (int) s.size();
        for(int i=0; i<N; ++i) {
            const char c = s[i] - START;
            if(trie[curr][c] == -1) {
                trie[curr][c] = (int) trie.size();
                trie.push_back(vector<int>(ALPHA, -1));
                end.push_back(0);
            }
            curr = trie[curr][c];
        }
        end[curr]++;
    }

    int match(const string &s) {
        int curr = 0;
        int N = (int) s.size();
        for(int i=0; i<N; ++i) {
            char c = s[i] - START;
            curr = trie[curr][c];
            if(curr == -1) return 0;
        }
        return end[curr];
    }
};

// int main() {

//     Trie t;

//     t.add_word("A");
//     t.add_word("AA");
//     t.add_word("AAA");
//     t.add_word("AA");

//     cout << t.match("A") << " " << t.match("AA") << " " << t.match("AAAA") << endl;


//     return 0;
// }