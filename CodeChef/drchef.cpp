#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, d, p, it;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        vector<int> a(n);
        d = n, p = 0, it = 0;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        while (it < n)
        {
            if (x >= a.back())
                break;
            while(x >= a[it] && it < n)
                ++it;
            if (it && it <= n)
            {
                if(x < a[it-1] << 1)
                    ++d, ++p, x = a[it-1] << 1;
                else if (x << 1 < a.back())
                    ++d, x <<= 1;
                else
                {
                    ++d, x <<= 1;
                    break;
                }
            }
            else if (x << 1 < a.back())
                ++d, x <<= 1;
            else
            {
                ++d, x <<= 1;
                break;
            }
        }
        cout << d - p << '\n';
    }
    return 0;
}