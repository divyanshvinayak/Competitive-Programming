#include<bits/stdc++.h>
using namespace std;

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
#define pb emplace_back
#define all(v) v.begin(), v.end()
#define allr(arr, r) arr, arr + r
#define showv(v) for(auto it: v) cout<<it<<' '; ln;
#define show2d(v) for(auto it: v) {for(auto j: it) cout<<j<<' '; ln;}
#define printv(v) for(auto it: v) cout<<it<<endl;
#define showvm(v) for(auto it: v) cout<<it.F<<':'<<it.S<<' '; ln;
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

const ll MAXN = 1e6+5, MOD = 1e9+7, SIZE = 1e5+5, BLOCKSIZE = 1e3, LN = 19, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Variables Here----->>//
ll t, n, x, y, q, lca, val, ptr, d, dx, min_f, ans, L, R, fai[SIZE], lai[SIZE], dp[SIZE << 2][LN], logn[SIZE << 1], visited[SIZE], counter[MAXN], res[SIZE], id[SIZE << 1], euler[SIZE << 1], depth[SIZE << 1], inv[LN * SIZE];
vll spf(MAXN, 2), pow2(LN, 1), v[SIZE];
vpll factors, a[SIZE];
struct query_t
{
	ll left, right, lca, id;
} queries[SIZE];

//<<-----Implement Functions Here---->>//
void precompute()
{
    val = 1, ptr = 0, inv[0] = 1, inv[1] = 1;
    FORI(i, 3, MAXN, 2)
        spf[i] = i;
    FORI(i, 3, sqrt(MAXN), 2)
        if(spf[i]==i)
            FORI(j, i*i, MAXN, i)
                if(spf[j]==j)
                    spf[j] = i;
    FOR(i, 1, LN)
        pow2[i] = pow2[i-1] << 1;
    FOR(i, 1, SIZE<<1)
    {
        logn[i] = ptr-1;
        if(i==val)
            val <<= 1, logn[i] = ptr, ptr++;
    }
    FOR(i, 2, LN*SIZE)
        inv[i] = (inv[MOD % i] * (MOD - MOD / i)) % MOD;
}

void initialize()
{
    ptr = 0;
    reset(v, {});
    reset(counter, 0);
    reset(visited, 0);
}

void addEdge(ll x, ll y)
{
    v[x].pb(y);
    v[y].pb(x);
}

vpll getPrimeFactorization(ll x)
{
    min_f = 1, factors = {};
    while(x>1)
    {
        y = spf[x], x /= y;
        if(y>min_f)
            factors.pb(y, 1), min_f = y;
        else
            factors.back().S++;
    }
    return factors;
}

void DFS(ll cur, ll prev, ll dep)
{
    fai[cur] = ptr;
    id[ptr] = cur;
    euler[ptr] = cur;
	depth[ptr] = dep;
    ptr++;
    FORALL(x, v[cur])
        if(x!=prev)
        {
            DFS(x, cur, dep+1);
            euler[ptr] = cur;
			depth[ptr] = dep;
            ptr++;
        }
    id[ptr] = cur;
	lai[cur] = ptr;
}

void buildSparseTable()
{
    FOR(i, 1, n<<1)
        dp[i-1][0] = (depth[i]>depth[i-1])?i-1:i;
    FOR(l, 1, LN)
        FOR(i, 0, n<<1)
            if(dp[i][l-1]!=-1 && dp[i+pow2[l-1]][l-1]!=-1)
                dp[i][l] = (depth[dp[i][l-1]]>depth[dp[i+pow2[l-1]][l-1]])?dp[i+pow2[l-1]][l-1]:dp[i][l-1];
            else
                break;
}

ll query(ll l, ll r)
{
    d = r-l, dx = logn[d];
    if(l==r)
        return l;
    if(depth[dp[l][dx]]>depth[dp[r-pow2[dx]][dx]])
        return dp[r-pow2[dx]][dx];
    else
        return dp[l][dx];
}

ll LCA(ll u, ll v)
{
    if(u==v)
        return u;
    return euler[query(fai[u], fai[v])];
}

bool compare(const query_t &a,const query_t &b)
{
    return a.left/BLOCKSIZE!=b.left/BLOCKSIZE?a.left<b.left:a.right<b.right;
}

void add(vpll v)
{
    FORALL(it, v)
        ans = (ans*inv[counter[it.F]+1])%MOD, counter[it.F]+=it.S, ans = (ans*(counter[it.F]+1))%MOD;
}

void remove(vpll v)
{
    FORALL(it, v)
        ans = (ans*inv[counter[it.F]+1])%MOD, counter[it.F]-=it.S, ans = (ans*(counter[it.F]+1))%MOD;
}

void verify(ll x)
{
    if(visited[x])
		remove(a[x]);
	else
		add(a[x]);
	visited[x] ^= 1;
}

void getQueries()
{
	cin>>q;
	FOR(i, 0, q)
	{
		cin>>x>>y;
		if(fai[x]>fai[y])
			swap(x, y);
		lca = LCA(x, y);
		if(lca==x)
			queries[i] = {fai[x], fai[y], lca, i};
		else
			queries[i] = {lai[x], fai[y], lca, i};
	}
}

void processQueries()
{
	sort(queries, queries+q, compare);
	L = queries[0].left, R = queries[0].left - 1, ans = 1;
	FOR(i, 0, q)
	{
		while(L<queries[i].left) verify(id[L++]);
		while(L>queries[i].left) verify(id[--L]);
		while(R<queries[i].right) verify(id[++R]);
		while(R>queries[i].right) verify(id[R--]);
		if(queries[i].lca!=id[L] && queries[i].lca!=id[R])
			verify(queries[i].lca), res[queries[i].id]=ans, verify(queries[i].lca);
		else
			res[queries[i].id] = ans;
	}
	FOR(i, 0, q)
		print(res[i]);
}

//<<----------Start of Main---------->>//
int main()
{
    fastio;
    precompute();
    cin>>t;
    while(t--)
    {
        cin>>n;
        initialize();
        FOR(i, 1, n)
        {
            cin>>x>>y;
            addEdge(x, y);
        }
        FOR(i, 1, n+1)
        {
            cin>>x;
            a[i] = getPrimeFactorization(x);
        }
        DFS(1, 0, 0);
        buildSparseTable();
        getQueries();
		processQueries();
    }
    return 0;
}