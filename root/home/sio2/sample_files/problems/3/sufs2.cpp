#include <bits/stdc++.h>

using namespace std;

const int N = 1000007;

char s1[N];
char s2[N];
int p[N];

int ans(int n, int m){
	int k = 0, wy = 0;
	for(int i=1; i<=m; i++){
		while(k && s1[k+1] != s2[i]) k = p[k];
		if(s1[k+1] == s2[i]) k++;
		if(k == n){
			wy ++;
			k = p[k];
		}
	}
	return wy;
}

int main(){
	int n, m;
	scanf("%s%n ", s1+1, &n);
	scanf("%s%n", s2+1, &m);
	reverse( s1+1, s1+n+1 );
	reverse( s2+1, s2+m+1 );

	int k = 0;
	for(int i=2; i<=n; i++){
		while( k && s1[i] != s1[k+1]) k = p[k];
		if(s1[i] == s1[k+1]) k++;
		p[i] = k;
	}

	for(int i=1; i<=n; i++) printf("%d%c", ans(i, m), " \n"[i==n]);
}
