#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> matrix;
typedef long long ll;

matrix prod(matrix a, matrix b, int m){
    matrix c(a.size(), vector<int>(b[0].size()));

	for(int i=0; i< a.size(); i++)
		for(int j=0; j< b[0].size(); j++)
			for(int k=0; k< b.size(); k++)
						c[i][j] = mod(mod(c[i][j], m) + mod(a[i][k]*b[k][j], m), m);

    return c;
}

matrix fexp(matrix base, ll exp, int m){
	matrix total = base;

	while(exp > 0){
		if(exp & 1){
			total = mult(total, base);
			exp--;
		}
		base= mult(base, base);
		exp /= 2;
	}
	return total;
}
