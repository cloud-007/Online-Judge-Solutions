#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, n, casee=1 ;
struct R
{
    int id, tot;
    bool operator <(R a)const
    {
        if(tot == a.tot)
            return id > a.id;
        return tot < a.tot;
    }
};
vector < R > x(1001);

void init()
{
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = i; j <= 1000; j += i)
        {
            x[j].id=i;
            x[j].tot++;
        }
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    init();
    sort(x.begin(), x.end());
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        cout<<"Case "<<casee++<<": "<<x[n].id<<endl;
    }

    return 0;
}
