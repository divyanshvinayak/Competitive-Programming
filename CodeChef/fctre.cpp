#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
typedef unordered_map<ll, ll> um;
typedef unordered_set<ll> us;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ln cout<<endl;
#define input(x) cin>>x;
#define print(x) cout<<x<<endl;
#define reset(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b, c) for(ll i = a; i < b; i += c)
#define FORD(i, a, b) for(ll i = a; i > b; i--)
#define FOREACH(it, v) for(auto it = v.begin();  it != v.end(); it++)
#define FORALL(it, v) for(auto it: v)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(arr, r) arr, arr + r
#define showv(v) for(auto it: v) cout<<it.F<<':'<<it.S<<' '; ln;
#define show2d(v) for(auto it: v) {for(auto j: it) cout<<j<<' '; ln;}
#define printv(v) for(auto it: v) cout<<it<<endl;
#define showvm(v) for(auto it: v) {for(auto j: it) cout<<j.F<<':'<<j.S<<' '; ln;}
#define sortv(v) sort(all(v));
#define revv(v) reverse(all(v));
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define gcd __gcd
#define checkbit(n, i) (n >> i & 1) // check ith bit
#define bitcount __builtin_popcount // count set bits
#define firstbitindex __builtin_ctz // count trailing zeros
#define lastbitindex __builtin_clz // count leading zeros
#define bitparity __builtin_parity // check set bits are even or odd
#define findv(v, x) (find(all(v), x) != v.end()) // find in a vector
#define findsm(u, x) (u.find(x) != u.end()) // find in a set / map
#define findstr(s, x) (s.find(x) != string::npos) // find in a string
#define sz(a) a.size()
#define precise(x) cout<<fixed<<setprecision(x);

const ll MAXN = 1e6+5, MOD = 1e9+7, SIZE = 1e5+5, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Variables Here----->>//
ll t, n, x, y, ans, q, lca, val, ptr, d, dx, i, j, m, max_x, max_y, FAI[SIZE], dp[SIZE][20], logn[SIZE], level[SIZE];
vll spf(MAXN, 2), pow2(20, 1), euler, depthArr, store;
vvll v;
vvpll a, z;
vpll counter;

//<<-----Implement Functions Here---->>//
void sieve()
{
    FORI(i, 3, MAXN, 2)
        spf[i] = i;
    FOR(i, 3, sqrt(MAXN)+1)
        if(spf[i]==i)
            FORI(j, i*i, MAXN, i)
                if(spf[j]==j)
                    spf[j] = i;
}

void precompute()
{
    val = 1, ptr = 0;
    FOR(i, 1, 20)
        pow2[i] = pow2[i-1]*2;
    FOR(i, 1, SIZE)
    {
        logn[i] = ptr-1;
        if(i == val)
            val *= 2, logn[i] = ptr, ptr++;
    }
}

void addEdge(ll x, ll y)
{
    v[x].pb(y);
    v[y].pb(x);
}

vpll merge(vpll x, vpll y)
{
    i = 0, j = 0, max_x = sz(x), max_y = sz(y), counter = {};
    while(i < max_x && j < max_y)
        if(x[i].F==y[j].F)
            counter.pb(mp(x[i].F, x[i].S+y[j].S)), i++, j++;
        else if(x[i].F<y[j].F)
            counter.pb(x[i]), i++;
        else
            counter.pb(y[j]), j++;
    while(i < max_x)
        counter.pb(x[i]), i++;
    while(j < max_y)
        counter.pb(y[j]), j++;
    return counter;
}

vpll difference(vpll x, vpll y)
{
    i = 0, j = 0, max_x = sz(x), max_y = sz(y), counter = {};
    while(j < max_y)
        if(x[i].F==y[j].F)
            counter.pb(mp(x[i].F, x[i].S-y[j].S)), i++, j++;
        else
            counter.pb(x[i]), i++;
    while(i < max_x)
        counter.pb(x[i]), i++;
    return counter;
}

void DFS(ll cur, ll prev, ll dep)
{
    if(FAI[cur] == -1)
        FAI[cur] = ptr;
    level[cur] = dep;
    euler.pb(cur);
    ptr++;
    FORALL(x, v[cur])
        if(x != prev)
        {
            z[x] = merge(z[cur], a[x]);
            DFS(x, cur, dep+1);
            euler.pb(cur);
            ptr++;
        }
}

void createDepthArr()
{
    FORALL(x, euler)
        depthArr.pb(level[x]);
}

void buildSparseTable()
{
    x = sz(depthArr);
    FOR(i, 1, x)
        dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i;
    FOR(l, 1, 20)
        FOR(i, 0, x)
            if(dp[i][l-1]!=-1 && dp[i+pow2[l-1]][l-1]!=-1)
                dp[i][l] = (depthArr[dp[i][l-1]]>depthArr[dp[i+pow2[l-1]][l-1]])?dp[i+pow2[l-1]][l-1]:dp[i][l-1];
            else
                break;
}

ll query(ll l, ll r)
{
    d = r-l, dx = logn[d];
    if(l==r)
        return l;
    if(depthArr[dp[l][dx]] > depthArr[dp[r-pow2[dx]][dx]])
        return dp[r-pow2[dx]][dx];
    else
        return dp[l][dx];
}

ll LCA(ll u, ll v)
{
    if(u==v)
        return u;
    if(FAI[u]>FAI[v])
       swap(u, v);
    return euler[query(FAI[u], FAI[v])];
}

//<<----------Start of Main---------->>//
int main()
{
    fastio;
    sieve();
    precompute();
    cin>>t;
    while(t--)
    {
        cin>>n;
        ptr = 0, v = vvll(n+1), a = vvpll(n+1), euler = depthArr = {}, reset(FAI, -1), reset(dp, -1);
        FOR(i, 1, n)
        {
            cin>>x>>y;
            addEdge(x, y);
        }
        FOR(i, 1, n+1)
        {
            cin>>x;
            m = 1;
            while(x>1)
            {
                y = spf[x], x /= y;
                if(y>m)
                    a[i].pb(mp(y, 1)), m = y;
                else
                    a[i].back().S++;
            }
        }
        z = a;
        DFS(1, 0, 0);
        createDepthArr();
        buildSparseTable();
        cin>>q;
        store = vll(q);
        FOR(i, 0, q)
        {
            cin>>x>>y;
            ans = 1, lca = LCA(x, y);
            FORALL(it, merge(merge(difference(z[x], z[lca]), difference(z[y], z[lca])), a[lca]))
                ans=(ans*(it.S+1))%MOD;
            store[i] = ans;
        }
        printv(store);
    }
    return 0;
}