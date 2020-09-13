#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, m;
    long long ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> z;
        unordered_map<int, int> a, b;
        unordered_set<int> s;
        m = 1;
        ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            ++a[x];
            s.insert(x);
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            ++b[x];
            s.insert(x);
        }
        for (auto it : s)
        {
            if (a[it] != b[it])
            {
                if (!((a[it] + b[it]) & 1))
                {
                    for (int i = 0; i < abs(a[it] - b[it]) >> 1; ++i)
                    {
                        z.emplace_back(it);
                    }
                }
                else
                {
                    cout << "-1\n";
                    m = 0;
                    break;
                }
            }
        }
        if (m)
        {
            sort(z.begin(), z.end());
            m = *min_element(s.begin(), s.end());
            for (int i = 0; i < z.size() >> 1; ++i)
                ans += min(z[i], m << 1);
            cout << ans << '\n';
        }
    }
    return 0;
}