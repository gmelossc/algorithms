#include <bits/stdc++.h>
using namespace std;

class KMP {
	string pattern;
	vector<int> f;

	public:	
	KMP(string pat) {
		pattern = pat;
		f.assign(pattern.size()+1, -1);
		
		for(int i=0, j=-1; i<(int)pattern.size(); ) {
			while(j >= 0 and pattern[i] != pattern[j]) j = f[j];
			f[++i] = ++j;
		}
	};

	vector<int> match(string text) {
		vector<int> ans;
		for(int i=0, j=0; i<(int)text.size(); ) {
			while(j>=0 and text[i] != pattern[j]) j = f[j];
			i++; j++;

			if(j == pattern.size()) {
				ans.push_back(i-j);
				j = f[j];
			}
		}
		return ans;
	}
};
