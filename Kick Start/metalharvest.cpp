#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int k, t, n, x, r;
struct Interval
{
    int start, end;
} top, temp, arr[MAXN];
deque<Interval> que;

bool compareIntervals(Interval left, Interval right)
{
    return left.start < right.start;
}

void mergeIntervals()
{
    sort(arr, arr + n, compareIntervals);
    que.push_back(arr[0]);
    for (int i = 1; i < n; ++i)
    {
        top = que.back();
        if (top.end < arr[i].start)
            que.push_back(arr[i]);
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            que.pop_back();
            que.push_back(top);
        }
    }
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i].start >> arr[i].end;
    mergeIntervals();
    temp.start = temp.end = r = 0;
    while (!que.empty())
    {
        top = que.front();
        if (top.start < temp.end)
            temp.start = temp.end;
        else
            temp.start = top.start;
        x = (top.end - temp.start) / k;
        temp.end = temp.start + x * k;
        r += x;
        if (temp.end < top.end)
            temp.end += k, ++r;
        que.pop_front();
    }
    cout << r << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i)
        cout << "Case #" << i << ": ", solve();
    return 0;
}