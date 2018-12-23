#include <bits/stdc++.h>

using namespace std;

string s1, s2;

int count(string s, string p){
	int st = 0;
	int wy = 0;
	while((st = p.find(s, st))!= string::npos){
		st ++;
		wy ++;
	}
	return wy;
}

int main(){
	cin >> s1 >>s2;
	reverse( s1.begin(), s1.end() );
	reverse( s2.begin(), s2.end() );
	for(int i=0; i<s1.size(); i++){
		if(i) putchar(' ');
		printf("%d", count(s1.substr(0, i+1), s2));
	}
	puts("");
}
