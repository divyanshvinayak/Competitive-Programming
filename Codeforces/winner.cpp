#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int X=0 ; X<T ; X++)
    {
        int N, MAX;
        cin>>N;
        vector <int> L, M;
        set <int> S;
        L.insert(L.end(), 0);
        if(N>100000)
            MAX = int(N/1000);
        else
            MAX = N+1;
        for(int Y=1 ; Y<MAX ; Y++)
        {
            if(int(N/Y)!= int(N/(Y+1)))
                L.insert(L.end(), Y);
        }
        if(N>100000)
        {
            for(int Y=1000 ; Y>0 ; Y--)
                if(find(M.begin(), M.end(), int(N/Y)) == M.end())
                    M.insert(M.end(), int(N/Y));
        }
        cout<<L.size()+M.size()<<'\n';
        for(int Y=0 ; Y<L.size() ; Y++)
            cout<<L[Y]<<' ';
        for(int Y=0 ; Y<M.size() ; Y++)
            cout<<M[Y]<<' ';
        cout<<'\n';
    }
}