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
    int t;
    cin >> t;
    while(t--)
    {
        int n,x,y,i;
        cin >> n;
        int coun=1;
        vector < int > ans;
        for(i=1;i<=n;i++)
        {
            cin >> x >> y;
            if(coun<=y)
            {
                ans.pb(max(x,coun));
                coun=max(x,coun);
                coun++;
            }
            else
            {
                ans.pb(0);
            }
        }

        for(i=0;i<ans.size();i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }
    return 0;
}
