#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
int t, n, k, f, a[MAXN], dp[MAXN][MAXN], dp2[MAXN], counter[101], ans, i, j;

void solve()
{
    cin >> n >> k;
	for (i = 0; i < n; ++i)
        cin >> a[i];
    memset(dp, 0, sizeof dp);
    for (i = 0; i < n; ++i)
    {
        memset(counter, 0, sizeof counter);
        f = 0;
        for (j = i; j < n; ++j)
        {
            ++counter[a[j]];
            if (counter[a[j]] == 2)
                f += 2;
            else if (counter[a[j]] > 2)
                ++f;
            dp[i][j] = f + k;
        }
    }
    memset(dp2, 0, sizeof dp2);
    for (i = 0; i < n; ++i)
    {
        dp2[i] = dp[0][i];
        for (j = 0; j < i; ++j)
            dp2[i] = min(dp2[i], dp2[j] + dp[j + 1][i]);
    }
    cout << dp2[n-1] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}