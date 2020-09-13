#include <bits/stdc++.h>
using namespace std;

int i, t, flag, flag2, alphabets[26];
string str, pattern, a;

void solve()
{
    cin >> str >> pattern;
	a.clear();
	flag = 1;
	flag2 = 1;
	fill(alphabets, alphabets + 26, 0);
	for (char c : str)
		++alphabets[c - 'a'];
	for (char c : pattern)
    {
		--alphabets[c - 'a'];
        if (flag2 && c != pattern[0])
        {
            if (c < pattern[0])
                flag = 0;
            flag2 = 0;
        }
    }
	for (i = 0; i < pattern[0] - 'a' + flag; ++i)
		a += string(alphabets[i], 'a' + i);
	a += pattern;
	for (; i < 26; ++i)
		a += string(alphabets[i], 'a' + i);
	cout << a << '\n';
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