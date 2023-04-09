#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
//cout << fixed << setprecision(8) << a << endl;
//cout << "Case " << ca << ": " << ans << endl;
#define Fast_Input ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MX 100005
#define infinity 20000000
#define pb push_back
#define ff first
#define ss second
#define all(a)  a.begin(), a.end()
#define rall(a)  a.rbegin(), a.rend()
#define mem(a, b)     memset(a, b, sizeof(a))
//#include <boost/math/common_factor.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*sort(v.begin(), v.end(),
     [](const pair<int, int>& x, const pair<int, int>& y)
{
    if (x.first != y.first)
        return x.first < y.first;
    return x.second < y.second;
});

for (const pair<int, int> &p: v)
{
    cout << p.first <<" "<< p.second <<endl;
}
*/

int const fx[]= {+1,+1,-1,-1,+2,+2,-2,-2};
//int const fz[]= {0,+1,-1};
int const fy[]= {+2,-2,+2,-2,+1,-1,+1,-1};

const ll mod=98244353;
const int inf = numeric_limits<int>::max();
int main()
{
    string s;
    int n,m,i,j,f=200,l=-1,last=1;
    cin >> n >> m;
    vector <pair<int,int>>v;
    for(i=1; i<=n; i++)
    {
        cin >> s;
        f=200,l=-1;
        for(j=0; j<m; j++)
        {
            if(s[j]=='W')
            {
                if(f==200)
                {
                    f=j+1;
                }
                l=j+1;
            }
        }
        v.pb({f,l});
        if(f!=200)
        {
            last=i;
        }
    }
    int pre=0,cur=1;
    ll sum=0;
    for(i=0; i<n-1; i++)
    {
        if(pre)
        {
            if(v[i+1].first!=200 || v[i].first!=200)
            {
                sum+=abs(cur-(min(v[i].first,v[i+1].first)));
                cur=min(v[i].first,v[i+1].first);
            }

        }
        else
        {
            if(v[i+1].second!=-1 || v[i].second!=-1)
            {
                sum+=abs(cur-(max(v[i].second,v[i+1].second)));
                cur=(max(v[i].second,v[i+1].second));
            }
        }
        pre=!pre;
    }

    if(pre)
    {
        if(v[i].first!=200)
            sum+=abs(cur-v[i].first);
    }
    else
    {
        if(v[i].second!=-1)
            sum+=abs(cur-v[i].second);
    }
    cout << sum+(last-1) << endl;
    return 0;
}
