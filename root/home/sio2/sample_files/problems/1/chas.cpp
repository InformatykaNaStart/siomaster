//brut
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b; cin >> a >> b;
    ll res = 0;

    for (ll i = a; i <= b; ++i)
        res += __builtin_popcount(i);

    cout << res << '\n';
}

