#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, int> a, b;
        for (int i = 1; i < n << 2; ++i)
            cin >> x >> y, ++a[x], ++b[y];
        for (auto it : a)
        {
            if (it.second & 1)
            {
                for (auto jt : b)
                {
                    if (jt.second & 1)
                    {
                        cout << it.first << ' ' << jt.first << '\n';
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}