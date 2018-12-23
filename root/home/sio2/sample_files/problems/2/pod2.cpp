/*  n^2*a  */

#include <stdio.h>
using namespace std;

#define MAXDELTA 200005

#define MAP(delta) (delta+100001)

typedef unsigned long long ull;

int len[1003];

int delta1[MAXDELTA];
int delta2[MAXDELTA];
int* now = delta1;
int* pre = delta2;

void next()
{
    int *tmp = now;
    now = pre;
    pre = tmp;
    for (int i = 0; i < MAXDELTA; i++) now[i] = -1;
}

int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &len[i]);
    
    next(); next();
    pre[MAP(0)] = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int delta = -100*n; delta <= 100*n; delta++)
        {
            if (pre[MAP(delta)] < 0) continue;
            else 
            {
                /* bez checkpointa */
                int d = delta + len[i];
                if (pre[MAP(delta)] < now[MAP(d)] || now[MAP(d)] < 0) 
                {
                    now[MAP(d)] = pre[MAP(delta)];
                }
                
                /* z checkpointem */
                d = len[i] - delta;
                if (pre[MAP(delta)]+1 < now[MAP(d)] || now[MAP(d)] < 0) 
                {
                    now[MAP(d)] = pre[MAP(delta)] + 1;
                }
            }
        }
        next();
    }
    if (pre[MAP(0)] < 0) printf("WOJNA\n");
    else printf("%d\n", pre[MAP(0)]);
}
