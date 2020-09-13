#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 2e5 + 1;
int t, n, i, u, v, p[mxN], a[mxN], b[mxN];
vector<int> q, adj[mxN], ans(mxN, -1), temp;
vector<bool> vis(mxN), vis2;

void solve()
{
    cin >> n;
    for (i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (i = 1; i <= n; i++)
        cin >> p[i];
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        cin >> b[i];
    for (i = 1; i <= n; i++)
    {
        vis2.assign(n + 1, false);
        q.assign(1, p[i]);
        vis[p[i]] = true;
        vis2[p[i]] = true;
        while (!q.empty())
        {
            for (int it: q)
            {
                if (b[it])
                {
                    b[it] -= min(b[it], a[p[i]]);
                    if (!b[it])
                        ans[it] = i;
                }
                for (int jt: adj[it])
                {
                    if (!(vis[jt] || vis2[jt]))
                    {
                        temp.push_back(jt);
                        vis2[jt] = true;
                    }
                }
            }
            q.assign(temp.begin(), temp.end());
            temp.clear();
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
        adj[i].clear();
        ans[i] = -1;
        vis[i] = false;
    }
    cout << '\n';
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