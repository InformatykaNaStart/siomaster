#include <bits/stdc++.h>

using namespace std;

const int N = 2000007;

char s[N];
int p[N];
int zl[N];

int main(){
	int n, m;
	scanf("%s%n ", s+1, &n);
	s[n+1] = '$';
	scanf("%s%n", s+n+2, &m);
	int l = n+m+1;
	reverse( s+1, s+n+1 );
	reverse( s+n+2, s+n+2+m );

	int k = 2;
	int ma = 0;
	for(int i=2; i<=l; i++){
		if(p[k]+i <= ma){
			p[i] = p[k];
		} else {
			p[i] = max(0, ma - i + 1);
			while(p[i] <= l-i && s[p[i]+1] == s[p[i] + i]){
				p[i] ++;
			}
			k = 1;
			ma = p[i]+i-1;
		}
		k ++;
	}

	for(int i=n+2; i<=l; i++) zl[p[i]] ++;
	for(int i=n; i>=1; i--) zl[i] += zl[i+1];

	for(int i=1; i<=n; i++) printf("%d%c", zl[i], " \n"[i==n]);
}
