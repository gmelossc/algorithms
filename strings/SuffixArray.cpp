#include <bits/stdc++.h>

using namespace std;

struct SuffixArray{
	string s;
	vector<int> p;
	vector<int> c;

	SuffixArray(string &t){
		s = t;
		s += '$';
		int n = s.size();

		c.assign(n, 0);
		p.assign(n, 0);

		{
			vector<pair<char,int>> a(n);

			for(int i = 0; i < n; ++i) a[i] = make_pair(s[i], i);
			sort(a.begin(), a.end());
			
			for(int i = 0; i < n; ++i) p[i] = a[i].second;
			c[p[0]] = 0, p[0] = a[0].second;
			
			for(int i = 1; i < n; ++i) c[p[i]] = a[i].first == a[i - 1].first ? c[p[i-1]] : c[p[i-1]]+1;
		}
		{
			for(int k = 1; k < n; k <<= 1){

				for(int i = 0; i < n; ++i) p[i] = (p[i] - k + n) % n;

				count_sort();
				vector<int> c_new(n);
				c_new[p[0]] = 0;

				for(int i = 1; i < n; ++i){
					pair<int ,int> cur = make_pair(c[p[i]], c[(p[i] + k)%n]);
					pair<int, int> prev = make_pair(c[p[i-1]], c[(p[i-1] + k)%n]);
					c_new[p[i]] = (cur == prev? c_new[p[i-1]] : c_new[p[i-1]] + 1);
				}	
				c = c_new;
			}
		}
	}
		
private:
	void count_sort(){
		int n = p.size();
	
		vector<int> cnt(n);
 
		for(int i: c) cnt[i]++;
 
		vector<int> p_new(n), pos(n);
	
		pos[0] = 0;
		for(int i = 1; i < n; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
 
		for(int x: p){
			int i = c[x];
			p_new[pos[i]++] = x;
		}
		p = p_new;
	}
};

int main(){
	string t; cin >> t;
	SuffixArray suffix = SuffixArray(t);

	for(int x: suffix.p) cout << x << ' ';
	cout << endl;
}





