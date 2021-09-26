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
	int n, m, x, y, ans = 0;
	in(n >> m)
	vll a(m), p(m);
	vb mc(m), uc(m), zx(m);
	unordered_map<int, deque<int>> ms;
	f0r(j,0,m) {
		in(x)
		ms[x].push_back(j);
	}
	f0r(i,0,n) {
		x = y = 0;
		zx = uc;
		f0r(j,0,m) {
			in(p[j])
			a[j] = -1;
			mc[j] = false;
		}
		f0r(j,0,m) {
			if (ms.count(p[j])) {
				a[j] = ms[p[j]].back();
				if (ms[p[j]].size() == 1) {
					ms.erase(p[j]);
				} else {
					ms[p[j]].pop_back();
				}
				zx[a[j]] = mc[a[j]] = true;
			}
		}
		while (y < m && zx[y]) {
			++y;
		}
		f0r(j,0,m) {
			if (a[j] == -1) {
				if (y == m) {
					while (mc[x]) {
						++x;
					}
					a[j] = x;
					mc[x] = true;
					++ans;
				} else {
					a[j] = y;
					zx[y] = mc[y] = uc[y] = true;
					while (y < m && zx[y]) {
						++y;
					}
				}
			}
		}
		ms.clear();
		f0r(j,0,m) {
			if (uc[a[j]]) {
				ms[p[j]].push_back(a[j]);
			} else {
				ms[p[j]].push_front(a[j]);
			}
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
