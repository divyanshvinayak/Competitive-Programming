#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef unsigned int ull;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vll;
typedef vector<pii> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
typedef unordered_map<int, int> um;
typedef unordered_set<int> us;

#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ts int t; in(t) while (t--) solve();
#define ks int t; in(t) f0r(j, 1, t + 1) cout << "Case #" << j << ": ", solve();
#define endl '\n'
#define ln cout << endl;
#define in(x) cin >> x;
#define out(x) cout << x << endl;
#define flush cout << flush;
#define reset(a, b) memset(a, b, sizeof(a));
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define f0r(j, a, b) for (int j = a; j < b; ++j)
#define f0ri(j, a, b, c) for (int j = a; j < b; j += c)
#define f0rd(j, a, b) for (int j = a; j > b; --j)
#define f0rr(it, v, r) for (auto it = v.begin() + r; it != v.end(); it++)
#define f0ra(it, v) for (auto it : v)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define vin(v, x) vll v(n); f0r(j, 0, x) in(v[j])
#define all(v) v.begin(), v.end()
#define allr(v, r) v.begin(), v.begin() + r
#define showv(v) f0ra(it, v) cout << it << ' '; ln
#define prllv(v) f0ra(it, v) out(it)
#define show2d(v) f0ra(it, v) { f0ra(i, it) cout << i << ' '; ln }
#define showm(v) f0ra(it, v) cout << it.F << ": " << it.S << ", "; ln
#define sortv(v) sort(all(v));
#define revv(v) reverse(all(v));
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define maxvr(v, a, b) *max_element(v.begin() + a, v.begin() + b)
#define minvr(v, a, b) *min_element(v.begin() + a, v.begin() + b)
#define gcd __gcd
#define sz(s) s.size()
#define checkbit(n, j) (n >> j) & 1
#define bitcount __builtin_popcount
#define firstbitindex __builtin_ctz
#define lastbitindex __builtin_clz
#define bitparity __builtin_parity
#define findv(v, x) (find(all(v), x) != v.end())
#define findsm(u, x) (u.find(x) != u.end())
#define findstr(s, x) (s.find(x) != string::npos)
#define precise(x) cout << fixed << setprecision(x);

const int N = 1e5 + 1, MAX = 2e5, MOD = 1e9 + 7, INF = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Global Variables Here----->>//

//<<-----Implement Functions Here---->>//
void solve() {
	int r, c;
	in(r >> c)
	vector<string> s(r), t;
	f0r(i,0,r) {
		in(s[i])
	}
	t = s;
	vvll v(r, vll(c, -1));
	bool notrees = true;
	f0r(i,0,r) {
		f0r(j,0,c) {
			if (s[i][j] == '^') {
				notrees = false;
			} else if (s[i][j] != '#') {
				s[i][j] = '^';
			}
		}
	}
	if (notrees) {
		out("Possible")
		f0r(i,0,r) {
			f0r(j,0,c) {
				cout << t[i][j];
			}
			cout << '\n';
		}
		return;
	}
	queue<pii> q;
	f0r(i,0,r) {
		f0r(j,0,c) {
			if (s[i][j] == '^') {
				int x = 0;
				if (i > 0 && s[i-1][j] == '^') {
					++x;
				}
				if (j > 0 && s[i][j-1] == '^') {
					++x;
				}
				if (i < r - 1 && s[i+1][j] == '^') {
					++x;
				}
				if (j < c - 1 && s[i][j + 1] == '^') {
					++x;
				}
				v[i][j] = x;
				if (x < 2) {
					q.push({i, j});
				}
			}
		}
	}
	bool ans = true;
	while (!q.empty()) {
		queue<pii> z;
		while (!q.empty()) {
			auto [i, j] = q.front();
			q.pop();
			if (t[i][j] == '^') {
				ans = false;
				break;
			} else {
				if (i > 0 && s[i - 1][j] == '^') {
					--v[i - 1][j];
					if (v[i - 1][j] < 2) {
						z.push({i - 1, j});
					}
				}
				if (j > 0 && s[i][j - 1] == '^') {
					--v[i][j - 1];
					if (v[i][j - 1] < 2) {
						z.push({i, j - 1});
					}
				}
				if (i < r - 1 && s[i + 1][j] == '^') {
					--v[i + 1][j];
					if (v[i + 1][j] < 2) {
						z.push({i + 1, j});
					}
				}
				if (j < c - 1 && s[i][j + 1] == '^') {
					--v[i][j + 1];
					if (v[i][j + 1] < 2) {
						z.push({i, j + 1});
					}
				}
				s[i][j] = '.';
				v[i][j] = -1;
			}
		}
		if (ans == false) {
			break;
		}
		q = z;
	}
	if (ans) {
		out("Possible")
		f0r(i,0,r) {
			f0r(j,0,c) {
				cout << s[i][j];
			}
			cout << '\n';
		}
	} else {
		out("Impossible")
	}
}

//<<----------Start of Main---------->>//
signed main()
{
	fastio
	// precompute();
    // ts
	// solve();
	ks
}
