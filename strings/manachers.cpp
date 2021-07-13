#include <bits/stdc++.h>
using namespace std;

/*
Given string s with length n. Find the Longest Palindromic Substring, LPS. O(N)

LPS[i] stores the one side length of the longest palindromic substring centered at i
*/

int manachers(string s) {
    string str = "";
    for(char c : s) str += "#", str += c;
    str += "#";
    int N = int(str.size());
    vector<int> LPS(N);
    for(int i = 0, l = 0, r = -1; i < N; i++) {
        int k = (i > r) ? 1 : min(LPS[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < N && str[i - k] == str[i + k]) {
            k++;
        }
        LPS[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    int answer = 1;
    for(int i=0; i<N; ++i) {
        if(str[i] != '#') answer = max(answer, LPS[i]/2*2 - 1);
        else answer = max(answer, LPS[i]/2*2);
    }

    return answer;
}

int main() {

    string s;
    cin >> s;
    cout << manachers(s);

    return 0;
}