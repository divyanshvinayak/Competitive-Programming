#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 3e3 + 1;
ll t, n, p, k, a, b, x, ans, total, e, mxf, f, c[MAXN], v[MAXN];
vector<ll> q, val, w;
vector<vector<ll>> r, dp;

void solve()
{
    cin >> n >> p >> k;
    fill(c + 1, c + p + 1, 0);
    ans = 0;
    q.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> x;
        ++c[x];
        q[i] = x;
    }
    for (int i = 1; i <= p; ++i)
    {
        cin >> v[i];
        ans += (c[i] * (c[i] - 1) * (c[i] - 2)) / 6;
    }
    sort(q.begin(), q.end());
    x = 0;
    r.assign(n + 1, vector<ll>(0));
    while (x < n)
    {
        e = q[x];
        r[e].push_back(x);
        while (x < n && e == q[x])
            ++x;
        r[e].push_back(x - 1);
    }
    val.assign(n + 1, 0);
    w.assign(n + 1, 0);
    total = 0;
    for (int i = 0; i < n; ++i)
    {
        mxf = r[q[i]][1] - r[q[i]][0] + 1;
        f = i - r[q[i]][0] + 1;
        val[i + 1] = (mxf * (mxf - 1) * (mxf - 2)) / 6 - ((mxf - f) * (mxf - f - 1) * (mxf - f - 2)) / 6;
        w[i + 1] = f * v[q[i]];
    }
    dp.assign(k + 1, vector<ll>(n + 1));
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            f = j - r[q[j - 1]][0];
            if (w[j] <= i)
            {
                dp[i][j] = max(dp[i][j], val[j] + dp[i - w[j]][j - f]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            else
                dp[i][j] = dp[i][j - 1];
            total = max(total, dp[i][j]);
        }
    }
    cout << ans - total << '\n';
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