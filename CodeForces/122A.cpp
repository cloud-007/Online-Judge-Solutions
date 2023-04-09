#include<bits/stdc++.h>
using namespace std;
int main()
{
    int fx[]={4,7,47,74,444,447,474,477,744,774,777};
    int n;
    cin>>n;
    for(int i=0;i<11;i++)
    {
        if(fx[i]<=n && n%fx[i]==0)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
