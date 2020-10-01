#include <bits/stdc++.h>
using namespace std;

int t, s, ra, pa, rb, pb, c, x, y, a, b, f, vis[4][5];

void solve()
{
    cin >> s >> ra >> pa >> rb >> pb >> c;
    memset(vis, 1, sizeof vis);
    for (int i = 1; i <= s; ++i)
        for (int j = 1; j < i << 1; ++j)
            vis[i][j] = 0;
    for (int i = 0; i < c; ++i)
    {
        cin >> x >> y;
        vis[x][y] = 1;
    }
    vis[ra][pa] = vis[rb][pb] = a = b = f = 1;
    for (int i = 0; i <= 10; ++i)
    {
        if (f)
        {
            if (!vis[ra - 1][pa - 1])
                vis[ra - 1][pa - 1] = 1, ++a, --ra, --pa;
            else if (!vis[ra + 1][pa + 1])
                vis[ra + 1][pa + 1] = 1, ++a, ++ra, ++pa;
            else if (!vis[ra][pa - 1])
                vis[ra][pa - 1] = 1, ++a, --pa;
            else if (!vis[ra][pa + 1])
                vis[ra][pa + 1] = 1, ++a, ++pa;
        }
        else
        {
            if (!vis[rb - 1][pb - 1])
                vis[rb - 1][pb] = 1, ++b, --rb, --pb;
            else if (!vis[ra + 1][pb + 1])
                vis[ra + 1][pb] = 1, ++b, ++rb, ++pb;
            else if (!vis[rb][pb - 1])
                vis[rb][pb - 1] = 1, ++b, --pb;
            else if (!vis[rb][pb + 1])
                vis[rb][pb + 1] = 1, ++b, ++pb;
        }
        f ^= 1;
    }
    cout << a - b << '\n';
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