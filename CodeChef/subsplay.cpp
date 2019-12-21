//Created on Sat Dec 21 12:00:00 2019

//@author: divyanshvinayak

#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    int T, X;
    cin>>T;
    for(X=0 ; X<T ; X++)
    {
        int N, P, F, Y, Z, I;
        cin>>N;
        string S;
        cin>>S;
        F = 0;
        for(Y=N-1 ; Y>0 ; Y--)
        {
            int C[Y];
            for(I = 0; I < Y; I++)
			    C[I] = I;
			unordered_set <string> L;
			while(true)
			{
			    string A = "";
			    for(Z=0 ; Z<Y ; Z++)
			        A += S[C[Z]];
			    if(L.find(A) == L.end())
			        L.insert(A);
			    else
			    {
			        cout<<A.length()<<'\n';
			        F = 1;
			        break;
			    }
			    if(C[0] == N - Y)
			        break;
			    else
			    {
                    P = Y - 1;
	                while(P >= 0)
	                {
		                if(C[P] == N - Y + P)
			                P-=1;
		                else
		                	break;
                	}
	                C[P]+=1;
			    }
			}
		    if(F == 1)
		        break;
        }
        if(F == 0)
            cout<<0<<'\n';
    }
    return 0;
}