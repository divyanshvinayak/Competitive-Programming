#include <bits/stdc++.h>
using namespace std;

int i, n, t, x, y, a, pow2[21] = {1};

void precompute()
{
	for (i = 1; i <= 20; ++i)
		pow2[i] = pow2[i - 1] << 1;
}

void solve()
{
	cin >> n;
	cout << "1 " << pow2[20] << '\n';
	cout << flush;
	cin >> x;
	x -= n * pow2[20];
	a = x & 1;
	for (i = 1; i <= 19; ++i)
	{
		cout << "1 " << pow2[i] << '\n';
		cout << flush;
		cin >> y;
		if (((n + ((x - y) / pow2[i])) / 2) & 1)
			a |= pow2[i];
	}
	cout << "2 " << a << '\n';
	cout << flush;
	cin >> x;
	if (x == -1)
		exit(0);
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	precompute();
    cin >> t;
	while (t--)
        solve();
    return 0;
}