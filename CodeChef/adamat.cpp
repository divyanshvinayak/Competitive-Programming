#include <bits/stdc++.h>
using namespace std;

int i, j, t, n, a[65][65], flag, ops;

void solve()
{
	cin >> n;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			cin >> a[i][j];
	flag = ops = 0;
	for (i = n; i > 1; --i)
		if (flag && a[1][i] == i)
			++ops, flag = 0;
		else if (!flag && a[1][i] != i)
			++ops, flag = 1;
	cout << ops << '\n';
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