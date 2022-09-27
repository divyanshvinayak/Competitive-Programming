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
typedef pair<int, int> pll;
typedef pair<string, string> pss;
typedef vector<int> vll;
typedef vector<bool> vb;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
typedef unordered_map<pll, int> um;
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
#define checkbit(n, j) (n >> j) & 1
#define bitcount __builtin_popcount
#define firstbitindex __builtin_ctz
#define lastbitindex __builtin_clz
#define bitparity __builtin_parity
#define findv(v, x) (find(all(v), x) != v.end())
#define findsm(u, x) (u.find(x) != u.end())
#define findstr(s, x) (s.find(x) != string::npos)
#define sz(a) a.size()
#define precise(x) cout << fixed << setprecision(x);

const int N = 1e5, MAX = 2e5, MOD = 1e9 + 7, INF = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Global Variables Here----->>//

//<<-----Implement Functions Here---->>//
void solve() {
	int n;
	int q;
	string s;
	in(s >> q)
	n = s.length();
	vvll p(n + 1, vll(26));
	f0r(i,0,n) {
		f0r(j,0,26) {
			if (s[i] == 'a' + j) {
				p[i + 1][j] = p[i][j] + 1;
			} else {
				p[i + 1][j] = p[i][j];
			}
		}
	}
	int ans = 0;
	f0r(i,0,q) {
		int x, y;
		in(x >> y)
		// character is removed from first half
		vll f(26), d(26);
		int m = (x + y) / 2;
		f0r(j,0,26) {
			f[j] = p[m][j] - p[x - 1][j];
			d[j] = p[y][j] - p[m][j];
		}
		int c = 0;
		f0r(j,0,26) {
			if (f[j] == d[j]) {
				continue;
			} else if (f[j] == d[j] + 1) {
				c += 1;
				if (c > 1) {
					break;
				}
			} else {
				c = -1;
				break;
			}
		}
		if (c == 1) {
			ans += 1;
			continue;
		}
		// character is removed from second half
		fill(f.begin(), f.end(), 0);
		fill(d.begin(), d.end(), 0);
		c = 0;
		f0r(j,0,26) {
			f[j] = p[m - 1][j] - p[x - 1][j];
			d[j] = p[y][j] - p[m - 1][j];
		}
		f0r(j,0,26) {
			if (f[j] == d[j]) {
				continue;
			} else if (f[j] + 1 == d[j]) {
				c += 1;
				if (c > 1) {
					break;
				}
			} else {
				c = -1;
				break;
			}
		}
		if (c == 1) {
			ans += 1;
		}
	}
	out(ans)
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
