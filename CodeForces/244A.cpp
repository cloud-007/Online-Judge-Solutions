/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, k, mp[1000], a[35];
vector < int > x[35];

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cin >> n >> k;
    for(int i=1;i<=k;i++)
    {
        cin >> a[i];
        x[i].push_back(a[i]);
        mp[a[i]]=1;
    }
    for(int i=1, j=1;i<=n*k;i++)
    {
        if(!mp[i])
        {
            if(x[j].size()>=n)j++;
            x[j].push_back(i);
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(auto j : x[i])cout<<j<<" ";
        cout << endl;
    }
    return 0;
}
