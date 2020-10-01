#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int t, n, x;
pair<int, int> a[MAXN];

void solve()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].first = a[i].first / x + (a[i].first % x ? 1 : 0);
        a[i].second = i + 1;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        cout << a[i].second << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i)
        cout << "Case #" << i << ": ", solve();
    return 0;
}