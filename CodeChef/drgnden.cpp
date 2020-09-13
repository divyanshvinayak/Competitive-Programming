#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sumF[200000], sumB[200000], *H;
vector<ll> Forward[200000], Backward[200000];

ll RMQUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MIN;
    ll mid = (ss + se) / 2;
    return max(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1), RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
}

ll RMQ(ll *st, ll n, ll qs, ll qe)
{
    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    ll mid = (ss + se) / 2;
    st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1), constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}

ll *constructST(ll arr[], ll n)
{
    ll x = ceil(log2(n));
    ll max_size = 2 * (ll) pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

void moveForward(ll h[], ll a[], ll n)
{
    stack<ll> s;
    ll nextF[n];
    for (ll i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }
        while (!s.empty() && h[s.top()] < h[i])
        {
            nextF[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        nextF[s.top()] = -1;
        s.pop();
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (nextF[i] == -1)
        {
            sumF[i] = a[i];
        }
        else
        {
            sumF[i] = a[i] + sumF[nextF[i]];
            Forward[nextF[i]].push_back(i);
        }
    }
}

void moveBackward(ll h[], ll a[], ll n)
{
    stack<ll> s;
    ll nextB[n];
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }
        while (!s.empty() && h[s.top()] < h[i])
        {
            nextB[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        nextB[s.top()] = -1;
        s.pop();
    }
    for (ll i = 0; i < n; i++)
    {
        if (nextB[i] == -1)
        {
            sumB[i] = a[i];
        }
        else
        {
            sumB[i] = a[i] + sumB[nextB[i]];
            Backward[nextB[i]].push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q, x, y, z;
    cin >> n >> q;
    ll h[n], a[n];
    for (ll i = 0; i < n; i++)
        cin >> h[i];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    moveForward(h, a, n);
    moveBackward(h, a, n);
    H = constructST(h, n);
    for (ll i = 0; i < q; i++)
    {
        cin >> x >> y >> z;
        --x, --y;
        if (x)
        {
            --z;
            if (y > z)
            {
                if (h[y] > h[z] && RMQ(H, n, z + 1, y - 1) < h[y])
                {
                    cout << sumF[z] - sumF[y] + a[y] << '\n';
                }
                else
                {
                    cout << -1 << '\n';
                }
            }
            else if (y < z)
            {
                if (h[y] > h[z] && RMQ(H, n, y + 1, z - 1) < h[y])
                {
                    cout << sumB[z] - sumB[y] + a[y] << '\n';
                }
                else
                {
                    cout << -1 << '\n';
                }
            }
            else
            {
                cout << a[y] << '\n';
            }
        }
        else
        {
            ll diff = z - a[y];
            vector<ll> que = {y};
            vector<ll> temp;
            vector<bool> vis(n);
            vis[y] = true;
            while(!que.empty())
            {
                for (auto it: que)
                {
                    sumF[it] += diff;
                    for (auto jt: Forward[it])
                    {
                        if (!vis[jt])
                        {
                            temp.push_back(jt);
                            vis[jt] = true;
                        }
                    }
                }
                que = temp;
                temp = {};
            }
            que = {y};
            vis = vector<bool>(n);
            vis[y] = true;
            while(!que.empty())
            {
                for (auto it: que)
                {
                    sumB[it] += diff;
                    for (auto jt: Backward[it])
                    {
                        if (!vis[jt])
                        {
                            temp.push_back(jt);
                            vis[jt] = true;
                        }
                    }
                }
                que = temp;
                temp = {};
            }
            a[y] = z;
        }
    }
    return 0;
}