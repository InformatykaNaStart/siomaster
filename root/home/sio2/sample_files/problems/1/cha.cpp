#include <iostream>
using namespace std;

inline long long countOnes ( int n )
{
  ++n;
  long long res = 0;
  for ( int pt = 1; pt <= n; pt *= 2 )
    res += ( ( n / pt ) / 2 ) * pt + max( n % ( pt * 2 ) - pt, 0 );
  return res;
}

inline long long countOnes ( int left, int right )
{
  return countOnes( right ) - countOnes( left - 1 );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b; cin >> a >> b;
    cout << countOnes(a, b) << '\n';
}
