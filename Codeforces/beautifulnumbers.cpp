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
        int N, C, MIN, MAX;
        cin>>N;
        vector <int> P(N), D(N);
        for(int I=0 ; I<N ; I++)
            cin>>P[I];
        for(int I=0 ; I<N ; I++)
        {
            C = 0;
            MIN = I - P[I] + 1;
            MAX = I + P[I];
            if(MIN < 0)
                MIN = 0;
            if(MAX > N)
                MAX = N;
            for(int J=MIN ; J<MAX ; J++)
            {
                if(P[J]<=P[I])
                    C+=1;
                else
                    C=0;
                if(C == P[I])
                {
                    D[P[I]-1] = 1;
                    break;
                }
            }
        }
        for(int I=0 ; I<N ; I++)
            cout<<D[I];
        cout<<'\n';
    }
}