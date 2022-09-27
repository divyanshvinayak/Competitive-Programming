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

const int N = 5e5, MAX = 2e5, MOD = 1e9 + 7, INF = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Global Variables Here----->>//
int a[2 * N], b[N];

//<<-----Implement Functions Here---->>//
void getLps(int *pat, int M, int *lps) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

int kmp(int *pat, int *txt, int M, int N) {
	int lps[M];
	getLps(pat, M, lps);
	int i = 0;
	int j = 0;
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			i++;
			j++;
		}
		if (j == M) {
			return i - j;
			j = lps[j - 1];
		} else if (i < N && pat[j] != txt[i]) {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i = i + 1;
			}
		}
	}
	return -1;
}

void solve() {
	int n, k;
	in(n >> k)
	f0r(i, 0, n) {
		in(a[i])
		a[n + i] = a[i];
	}
	f0r(i, 0, n) {
		in(b[i])
	}
	bool f = true;
	bool f2 = true;
	f0r(i, 0, n) {
		if (a[i] != b[i]) {
			f = false;
			break;
		}
	}
	f0r(i, 1, n) {
		if (a[i - 1] != a[i]) {
			f2 = false;
			break;
		}
	}
	if (f2) {
		out("YES")
		return;
	}
	if (f) {
		if (k == 0) {
			out("YES")
			return;
		} else if (k == 1) {
			out("NO")
			return;
		} else if (n == 2) {
			if (k % 2 == 0) {
				out("YES")
				return;
			} else {
				out("NO")
				return;
			}
		} else {
			out("YES")
			return;
		}
	} else {
		int idx = kmp(b, a, n, 2 * n);
		if (idx == -1) {
			out("NO")
			return;
		}
		// B is a rotation of A
		if (k == 0) {
			out("NO")
			return;
		} else if (k == 1) {
			out("YES")
		} else if (n == 2) {
			if (k % 2 == 0) {
				out("NO")
				return;
			} else {
				out("YES")
				return;
			}
		} else {
			out("YES")
			return;
		}
	}
}

//<<----------Start of Main---------->>//
signed main() {
	fastio
	// precompute();
	// ts
	// solve();
	ks
}
