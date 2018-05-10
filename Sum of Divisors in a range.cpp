#include<bits/stdc++.h>
using namespace std ;

ll triangle(ll a, ll b)
{
        return (a + b + 1) * (b - a) / 2 ;
}

ll divSum(ll a, ll b) // Sum of divisors between a to b
{
        ll n = sqrt(b);
        ll sum = 0;

        for (ll i = 1; i <= n; i++)
                sum += i * (b / i - a / i) + triangle(max(n, a / i), max(n, b / i));
        return sum;
}

int main()
{
        ll a, b;
        cin >> a >> b;
        ll ans = divSum(a - 1, b);
        cout << ans << endl;

        return 0;
}
