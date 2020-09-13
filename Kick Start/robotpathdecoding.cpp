#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 1e9;

int t, i;
string s;
vector<ll> temp(2);
stack<char> operand;
stack<vector<ll>> output;

void solve()
{
	cin >> s;
	s = "1(" + s + ')';
	for (char it : s)
	{
		if (it == ')')
		{
			while (operand.top() != '(')
			{
				if (operand.top() == '#')
				{
					temp[0] += output.top()[0];
					temp[1] += output.top()[1];
					output.pop();
				}
				else if (operand.top() == 'N')
					--temp[1];
				else if (operand.top() == 'E')
					++temp[0];
				else if (operand.top() == 'W')
					--temp[0];
				else
					++temp[1];
				operand.pop();
			}
			operand.pop();
			temp[0] = (temp[0] * (operand.top() - '0')) % MAX;
			temp[1] = (temp[1] * (operand.top() - '0')) % MAX;
			operand.pop();
			operand.push('#');
			output.push(temp);
			temp = {0, 0};
		}
		else
			operand.push(it);
	}
	cout << (MAX + output.top()[0]) % MAX + 1 << ' ' << (MAX + output.top()[1]) % MAX + 1 << '\n';
	output.pop();
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (i = 1; i <= t; ++i)
		cout << "Case #" << i << ": ", solve();
	return 0;
}