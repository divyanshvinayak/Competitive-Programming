#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
typedef unordered_map<ll, ll> um;
typedef unordered_set<ll> us;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define endl '\n'
#define ln cout << endl;
#define input(x) cin >> x;
#define print(x) cout << x << endl;
#define reset(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FORI(i, a, b, c) for (ll i = a; i < b; i += c)
#define FORD(i, a, b) for (ll i = a; i > b; i--)
#define FOREACH(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define FORALL(it, v) for (auto it : v)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(arr, r) arr, arr + r
#define showv(v)           \
    for (auto it : v)      \
        cout << it << ' '; \
    ln;
#define showm(v)                            \
    for (auto it : v)                       \
        cout << it.F << ',' << it.S << ' '; \
    ln;
#define show2d(v)             \
    for (auto it : v)         \
    {                         \
        for (auto j : it)     \
            cout << j << ' '; \
        ln;                   \
    }
#define printv(v)     \
    for (auto it : v) \
        cout << it << endl;
#define showvm(v)             \
    for (auto it : v)         \
    {                         \
        for (auto j : it)     \
            cout << j << ' '; \
        ln;                   \
    }
#define sortv(v) sort(all(v));
#define revv(v) reverse(all(v));
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define gcd __gcd
#define checkbit(n, i) (n >> i) & 1               // check ith bit
#define bitcount __builtin_popcount               // count set bits
#define firstbitindex __builtin_ctz               // count trailing zeros
#define lastbitindex __builtin_clz                // count leading zeros
#define bitparity __builtin_parity                // check set bits are even or odd
#define findv(v, x) (find(all(v), x) != v.end())  // find in a vector
#define findsm(u, x) (u.find(x) != u.end())       // find in a set / map
#define findstr(s, x) (s.find(x) != string::npos) // find in a string
#define sz(a) a.size()
#define precise(x) cout << fixed << setprecision(x);

const ll MAXN = 1e5 + 5, MOD = 1e9 + 7, SIZE = 1e5 + 5, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Variables Here----->>//
ll t, n, k;
vll p, visited, cycle;
vvll cycles, ans, tmp;
bool flag;

//<<-----Implement Functions Here---->>//
void solve()
{
    input(n >> k)
    p = visited = vll(n + 1), cycle = {};
    cycles = ans = tmp = {};
    flag = true;
    FOR(i, 1, n + 1)
        input(p[i])
    FOR(i, 1, n + 1)
    {
        while (!visited[i])
            visited[i] = 1, cycle.pb(i), i = p[i];
        if (!cycle.empty())
            cycles.pb(cycle), cycle = {};
    }
    FORALL(i, cycles)
    {
        FORI(j, 1, sz(i) - 1, 2)
            ans.pb({i[0], i[j], i[j + 1]});
        if (!(sz(i) % 2))
            tmp.pb({i[0], i[sz(i) - 1]});
    }
    if (sz(tmp) % 2)
        flag = false;
    else
    {
        FORI(i, 0, sz(tmp), 2)
        {
            ans.pb({tmp[i][0], tmp[i][1], tmp[i + 1][0]});
            ans.pb({tmp[i + 1][0], tmp[i][0], tmp[i + 1][1]});
        }
    }
    if (flag && sz(ans) <= k)
    {
        print(sz(ans))
        FORALL(i, ans)
            print(i[0] << ' ' << i[1] << ' ' << i[2])
    }
    else
        print(-1)
    return;
}

//<<----------Start of Main---------->>//
int main()
{
    fastio
    input(t) while (t--)
        solve();
    return 0;
}