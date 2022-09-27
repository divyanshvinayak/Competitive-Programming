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

const int N = 1e6 + 1, MAX = 2e5, MOD = 1e9 + 7, INF = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Global Variables Here----->>//
vll fact2(N), fact7(N);

//<<-----Implement Functions Here---->>//
int add(int x, int y) {
	return (MOD + (x + y) % MOD) % MOD;
}

int sub(int x, int y) {
	return (MOD + (x - y) % MOD) % MOD;
}

int mul(int x, int y) {
	return (MOD + (x * y) % MOD) % MOD;
}

template <typename T>
class dynamic_segment_tree
{
	enum Color
	{
		RED,
		BLACK
	};

	struct Node
	{
		T data, sum, lazy;
		size_t size;
		Color color;
		Node *left, *right, *parent;
	};

	Node *root, *null;

	Node *Search(size_t pos)
	{
		Node *node = root;
		size_t idx = node->left->size + 1;
		Propagate(node);
		while (idx != pos)
		{
			if (pos < idx)
			{
				node = node->left;
			}
			else
			{
				pos -= idx;
				node = node->right;
			}
			idx = node->left->size + 1;
			Propagate(node);
		}
		return node;
	}

	void RotateLeft(Node *node)
	{
		Node *right = node->right;
		Propagate(right);
		Propagate(node->left);
		Propagate(right->left);
		node->right = right->left;
		if (right->left != null)
		{
			right->left->parent = node;
		}
		right->parent = node->parent;
		if (node == root)
		{
			root = right;
		}
		else if (node == node->parent->left)
		{
			node->parent->left = right;
		}
		else
		{
			node->parent->right = right;
		}
		right->left = node;
		node->parent = right;
		right->size = node->size;
		node->size = node->left->size + node->right->size + 1;
		right->sum = node->sum;
		node->sum = add(add(node->left->sum, node->right->sum), node->data);
	}

	void RotateRight(Node *node)
	{
		Node *left = node->left;
		Propagate(left);
		Propagate(node->right);
		Propagate(left->right);
		node->left = left->right;
		if (left->right != null)
		{
			left->right->parent = node;
		}
		left->parent = node->parent;
		if (node == root)
		{
			root = left;
		}
		else if (node == node->parent->right)
		{
			node->parent->right = left;
		}
		else
		{
			node->parent->left = left;
		}
		left->right = node;
		node->parent = left;
		left->size = node->size;
		node->size = node->left->size + node->right->size + 1;
		left->sum = node->sum;
		node->sum = add(add(node->left->sum, node->right->sum), node->data);
	}

	void FixInsert(Node *node)
	{
		Node *parent = node->parent, *grandparent = parent->parent, *uncle;
		while (parent->color == RED)
		{
			if (parent == grandparent->right)
			{
				uncle = grandparent->left;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					parent->color = BLACK;
					grandparent->color = RED;
					node = grandparent;
				}
				else
				{
					if (node == parent->left)
					{
						node = parent;
						RotateRight(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					RotateLeft(node->parent->parent);
				}
			}
			else
			{
				uncle = grandparent->right;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					parent->color = BLACK;
					grandparent->color = RED;
					node = grandparent;
				}
				else
				{
					if (node == parent->right)
					{
						node = parent;
						RotateLeft(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					RotateRight(node->parent->parent);
				}
			}
			if (node == root)
			{
				break;
			}
			parent = node->parent;
			grandparent = parent->parent;
		}
		root->color = BLACK;
	}

	void Insert(size_t pos, T data)
	{
		Node *node = new Node{data, data, 0, 1, RED, null, null, NULL}, *parent;
		if (root == null)
		{
			root = node;
			node->color = BLACK;
			return;
		}
		else
		{
			if (pos == root->size + 1)
			{
				parent = root;
				Propagate(parent);
				while (parent->right != null)
				{
					parent->size++;
					parent->sum = add(parent->sum, data);
					parent = parent->right;
					Propagate(parent);
				}
				parent->size++;
				parent->sum = add(parent->sum, data);
				parent->right = node;
				node->parent = parent;
			}
			else
			{
				parent = root;
				size_t idx = parent->left->size + 1;
				Propagate(parent);
				while (idx != pos)
				{
					parent->size++;
					parent->sum = add(parent->sum, data);
					if (pos < idx)
					{
						parent = parent->left;
					}
					else
					{
						pos -= idx;
						parent = parent->right;
					}
					idx = parent->left->size + 1;
					Propagate(parent);
				}
				parent->size++;
				parent->sum = add(parent->sum, data);
				if (parent->left == null)
				{
					parent->left = node;
					node->parent = parent;
				}
				else
				{
					parent = parent->left;
					Propagate(parent);
					while (parent->right != null)
					{
						parent->size++;
						parent->sum = add(parent->sum, data);
						parent = parent->right;
						Propagate(parent);
					}
					parent->size++;
					parent->sum = add(parent->sum, data);
					parent->right = node;
					node->parent = parent;
				}
			}
		}
		if (parent == root)
		{
			return;
		}
		FixInsert(node);
	}

	Node *BSTReplace(Node *node)
	{
		node->size--;
		node->sum = sub(node->sum, node->data);
		if (node->left != null)
		{
			if (node->right != null)
			{
				node = node->right;
				Propagate(node);
				T data = Minimum(node)->data;
				while (node->left != null)
				{
					node->size--;
					node->sum = sub(node->sum, data);
					node = node->left;
				}
				return node;
			}
			Propagate(node->left);
			return node->left;
		}
		if (node->right != null)
		{
			Propagate(node->right);
			return node->right;
		}
		return null;
	}

	Node *Sibling(Node *node)
	{
		if (node == root)
		{
			return null;
		}
		if (node == node->parent->left)
		{
			return node->parent->right;
		}
		return node->parent->left;
	}

	void FixDoubleBlack(Node *node)
	{
		while (node != root)
		{
			Node *parent = node->parent, *sibling = Sibling(node);
			if (sibling == null)
			{
				node = parent;
			}
			else
			{
				if (sibling->color == RED)
				{
					parent->color = RED;
					sibling->color = BLACK;
					if (sibling == parent->left)
					{
						RotateRight(parent);
					}
					else
					{
						RotateLeft(parent);
					}
				}
				else
				{
					if (sibling->left->color == RED || sibling->right->color == RED)
					{
						if (sibling->left->color == RED)
						{
							if (sibling == parent->left)
							{
								sibling->left->color = BLACK;
								sibling->color = parent->color;
								RotateRight(parent);
							}
							else
							{
								sibling->left->color = parent->color;
								Propagate(sibling);
								RotateRight(sibling);
								RotateLeft(parent);
							}
						}
						else
						{
							if (sibling == parent->left)
							{
								sibling->right->color = parent->color;
								Propagate(sibling);
								RotateLeft(sibling);
								RotateRight(parent);
							}
							else
							{
								sibling->right->color = BLACK;
								sibling->color = parent->color;
								RotateLeft(parent);
							}
						}
						parent->color = BLACK;
						return;
					}
					else
					{
						sibling->color = RED;
						if (parent->color == BLACK)
						{
							node = parent;
						}
						else
						{
							parent->color = BLACK;
							return;
						}
					}
				}
			}
		}
	}

	void Delete(Node *node)
	{
		Node *substitute = BSTReplace(node), *parent = node->parent, *sibling = Sibling(node);
		bool doubleblack = substitute->color == BLACK && node->color == BLACK;
		if (substitute == null)
		{
			if (node == root)
			{
				root = null;
			}
			else
			{
				if (doubleblack)
				{
					FixDoubleBlack(node);
				}
				else if (sibling != null)
				{
					sibling->color = RED;
				}
				if (node == parent->left)
				{
					parent->left = null;
				}
				else
				{
					parent->right = null;
				}
			}
			delete node;
		}
		else if (node->left == null || node->right == null)
		{
			if (node == root)
			{
				node->data = substitute->data;
				node->left = node->right = null;
				delete substitute;
			}
			else
			{
				if (node == parent->left)
				{
					parent->left = substitute;
				}
				else
				{
					parent->right = substitute;
				}
				delete node;
				substitute->parent = parent;
				if (doubleblack)
				{
					FixDoubleBlack(substitute);
				}
				else
				{
					substitute->color = BLACK;
				}
			}
		}
		else
		{
			node->data = substitute->data;
			Delete(substitute);
		}
	}

	void Delete(size_t pos)
	{
		Node *node = root;
		size_t idx = node->left->size + 1;
		T data = Search(pos)->data;
		while (idx != pos)
		{
			node->size--;
			node->sum = sub(node->sum, data);
			if (pos < idx)
			{
				node = node->left;
			}
			else
			{
				pos -= idx;
				node = node->right;
			}
			idx = node->left->size + 1;
		}
		Delete(node);
	}

	Node *Minimum(Node *node)
	{
		while (node->left != null)
		{
			node = node->left;
			Propagate(node);
		}
		return node;
	}

	Node *Maximum(Node *node)
	{
		while (node->right != null)
		{
			node = node->right;
			Propagate(node);
		}
		return node;
	}

	Node *Successor(Node *node)
	{
		if (node->right != null)
		{
			Propagate(node->right);
			return Minimum(node->right);
		}
		Node *parent = node->parent;
		while (node == parent->right)
		{
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}

	Node *Predecessor(Node *node)
	{
		if (node->left != null)
		{
			Propagate(node->left);
			return Maximum(node->left);
		}
		Node *parent = node->parent;
		while (node == parent->left)
		{
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}

	void Clear(Node *node)
	{
		if (node == null)
		{
			return;
		}
		Clear(node->left);
		Clear(node->right);
		delete node;
	}

	void Propagate(Node *node)
	{
		if (node->lazy)
		{
			node->data = add(node->data, node->lazy);
			node->sum = add(node->sum, mul(node->lazy, node->size));
			if (node->left != null)
			{
				node->left->lazy += node->lazy;
			}
			if (node->right != null)
			{
				node->right->lazy += node->lazy;
			}
			node->lazy = 0;
		}
	}

	T Query(Node *node, size_t ss, size_t se, size_t qs, size_t qe)
	{
		Propagate(node);
		if (qs == ss && qe == se)
		{
			return node->sum;
		}
		size_t idx = node->left->size + 1;
		if (qs <= idx && qe >= idx)
		{
			return add(add(Query(node->left, 1, node->left->size, qs, idx - 1), node->data), Query(node->right, 1, node->right->size, 1, qe - idx));
		}
		if (qe < idx)
		{
			return Query(node->left, 1, node->left->size, qs, qe);
		}
		return Query(node->right, 1, node->right->size, qs - idx, qe - idx);
	}

	void Update(Node *node, size_t ss, size_t se, size_t us, size_t ue, T diff)
	{
		if (us == ss && ue == se)
		{
			node->lazy += diff;
			return;
		}
		node->sum = add(node->sum, mul(diff, (ue - us + 1)));
		size_t idx = node->left->size + 1;
		if (us <= idx && ue >= idx)
		{
			node->data = add(node->data, diff);
			if (us < idx)
			{
				Update(node->left, 1, node->left->size, us, idx - 1, diff);
			}
			if (ue > idx)
			{
				Update(node->right, 1, node->right->size, 1, ue - idx, diff);
			}
		}
		else if (ue < idx)
		{
			Update(node->left, 1, node->left->size, us, ue, diff);
		}
		else
		{
			Update(node->right, 1, node->right->size, us - idx, ue - idx, diff);
		}
	}

	size_t Index(Node *node)
	{
		size_t pos = node->left->size + 1;
		while (node != root)
		{
			Node *parent = node->parent;
			if (node == parent->right)
			{
				pos += parent->left->size + 1;
			}
			node = parent;
		}
		return pos;
	}

public:
	dynamic_segment_tree()
	{
		null = new Node{0, 0, 0, 0, BLACK, NULL, NULL, NULL};
		root = null;
	}

	void insert(size_t pos, T data)
	{
		Insert(pos, data);
	}

	void erase(size_t pos)
	{
		Delete(pos);
	}

	void erase(Node *node)
	{
		Delete(Index(node));
	}

	Node *find(size_t pos)
	{
		return Search(pos);
	}

	T at(size_t pos)
	{
		return Search(pos)->data;
	}

	T operator[](size_t pos)
	{
		return Search(pos)->data;
	}

	T sum(size_t left, size_t right)
	{
		return Query(root, 1, root->size, left, right);
	}

	void update(size_t left, size_t right, T diff)
	{
		Update(root, 1, root->size, left, right, diff);
	}

	Node *next(Node *node)
	{
		return Successor(node);
	}

	Node *prev(Node *node)
	{
		return Predecessor(node);
	}

	size_t size()
	{
		return root->size;
	}

	size_t index(Node *node)
	{
		return Index(node);
	}

	bool empty()
	{
		return root == null;
	}

	void clear()
	{
		Clear(root);
		root = null;
	}
};

void precompute() {
	fact2[0] = 1;
	fact7[0] = 1;
	f0r(i,1,N) {
        fact2[i] = (fact2[i - 1] * i * 2) % MOD;
		fact7[i] = (fact7[i - 1] * i * 7) % MOD;
	}
}

void solve() {
	int n;
	int q;
	in(n)
	vin(v, n);
	in(q)
	dynamic_segment_tree<int> p, p2;
	unordered_map<int, set<int>> ms, ms2;
	f0r(i,0,n) {
		p.insert(i + 1, fact2[v[i]]);
		p2.insert(i + 1, fact7[v[i]]);
		ms[fact2[v[i]]].insert(i + 1);
		ms2[fact7[v[i]]].insert(i + 1);
	}
	int ans = 0;
	f0r(i,0,q) {
		int z, x, y;
		in(z >> x >> y)
		int m = (x + y) / 2;
		if (z == 1) {
			ms[fact2[v[x - 1]]].erase(x);
			ms2[fact7[v[x - 1]]].erase(x);
			if (ms[fact2[v[x - 1]]].empty()) {
				ms.erase(fact2[v[x - 1]]);
			}
			if (ms2[fact7[v[x - 1]]].empty()) {
				ms2.erase(fact7[v[x - 1]]);
			}
			ms[fact2[y]].insert(x);
			ms2[fact7[y]].insert(x);
			p.update(x, x, -fact2[v[x - 1]]);
			p2.update(x, x, -fact7[v[x - 1]]);
			p.update(x, x, fact2[y]);
			p2.update(x, x, fact7[y]);
			v[x - 1] = y;
		} else {
			// removed from first half
			int f = p.sum(x, m);
			int f2 = p2.sum(x, m);
			int s = p.sum(m + 1, y);
			int s2 = p2.sum(m + 1, y);
			int d = (MOD + (f - s) % MOD) % MOD;
			int d2 = (MOD + (f2 - s2) % MOD) % MOD;
			if (ms.count(d) && ms2.count(d2)) {
				auto it = ms[d].lower_bound(x);
				auto it2 = ms2[d2].lower_bound(x);
				// check if d is present in first half
				if (it != ms[d].end() && it2 != ms2[d2].end() && *it <= m && *it2 <= m) {
					++ans;
					continue;
				}
			}
			// removed from second half
			f = p.sum(x, m - 1);
			f2 = p2.sum(x, m - 1);
			s = p.sum(m, y);
			s2 = p2.sum(m, y);
			d = (MOD + (s - f) % MOD) % MOD;
			d2 = (MOD + (s2 - f2) % MOD) % MOD;
			if (ms.count(d) && ms2.count(d2)) {
				auto it = ms[d].lower_bound(m);
				auto it2 = ms2[d2].lower_bound(m);
				// check if d is present in second half
				if (it != ms[d].end() && it2 != ms2[d2].end() && *it <= y && *it2 <= y) {
					++ans;
					continue;
				}
			}
		}
	}
	out(ans)
}

//<<----------Start of Main---------->>//
signed main() {
	fastio
	precompute();
    // ts
	// solve();
	ks
}
