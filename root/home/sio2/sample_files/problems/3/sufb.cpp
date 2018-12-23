#include <bits/stdc++.h>

using namespace std;

const int N = 1000007;

char s1[N];
char s2[N];
int p[N];
int zl[N];
int g[N];

int main(){
	int n, m;
	scanf("%s%n ", s1+1, &n);
	scanf("%s%n", s2+1, &m);
	reverse( s1+1, s1+n+1 );
	reverse( s2+1, s2+m+1 );

	int k = 0;
	for(int i=2; i<=n; i++){
		while(k && s1[i] != s1[k+1]) k = p[k];
		if(s1[i] == s1[k+1]) k++;
		p[i] = k;
	}

/*	for(int i=1; i<=n; i++){
		printf("%d ", p[i]);
	}
	puts("");*/

	k = 0;

	for(int i=1; i<=m; i++){
		while(k && s2[i] != s1[k+1]) k = p[k];
		if(s2[i] == s1[k+1]) k++;
		g[i-k+1] = max(k, g[i-k+1]);
	}

/*	for(int i=1; i<=n; i++){
		printf("%d ", g[i]);
	}
	puts("");*/

	for(int i=1; i<=m; i++) zl[g[i]]++;

	for(int i=n; i>=1; i--) zl[i] += zl[i+1];

	for(int i=1; i<=n; i++) printf("%d%c", zl[i], " \n"[i==n]);
}
