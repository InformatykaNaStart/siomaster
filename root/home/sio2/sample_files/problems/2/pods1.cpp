/* n*2^n */

#include <stdio.h>
using namespace std;

typedef unsigned long long ull;

int len[1003];

int n;

int check(ull pattern)
{
    int checkpoints = 0;
    int a = len[0], b = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (pattern&(1<<i)) {a^=b; b^=a; a^=b; checkpoints++;}
        a += len[i+1];
    }
    if (a == b) return checkpoints;
    else return 1003;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &len[i]);
    
    int best = 1003;
    for (ull pattern = 0; pattern < (1<<(n-1)); pattern++)
    {
        int r = check(pattern);
        if (r < best)
        {
            best = r;
        }
    }
    if (best < 1000) printf("%d\n", best);
    else printf("WOJNA\n");
}
