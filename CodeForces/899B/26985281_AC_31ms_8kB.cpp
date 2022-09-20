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
    int n,i,x,j;
    cin >> n;
    vector < int > v;
    vector < int >t;
    vector < int >o;
    map < int,int>m;
    t.pb(1);
    t.pb(3);
    t.pb(5);
    t.pb(7);
    t.pb(8);
    t.pb(10);
    t.pb(12);
    o.pb(4);
    o.pb(6);
    o.pb(9);
    o.pb(11);
    m[1]=31;
    m[2]=28;
    m[3]=31;
    m[4]=30;
    m[5]=31;
    m[6]=30;
    m[7]=31;
    m[8]=31;
    m[9]=30;
    m[10]=31;
    m[11]=30;
    m[12]=31;
    int coun=0,p=0,k=0,z;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        v.pb(x);
        if(x==29)
            coun++;
    }
    if(coun>1)
        cout << "NO" << endl;
    else if(v[0]==31)
    {
        for(i=0; i<t.size(); i++)
        {
            k=0,z=t[i];
            for(j=0; j<n; j++)
            {
                if(z==2)
                {
                    if((v[j]==28 || v[j]==29))
                        z++;
                    else
                    {
                        k=1;
                        break;
                    }
                }
                else
                {
                    if(m[z]==v[j])
                    {
                        if(z==12)
                            z=1;
                        else
                            z++;
                    }
                    else
                    {
                        k=1;
                        break;
                    }
                }
            }
            if(k==0)
            {
                p=1;
                break;
            }
        }

        if(p)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else if(v[0]==30)
    {
        for(i=0; i<o.size(); i++)
        {
            k=0,z=o[i];
            for(j=0; j<n; j++)
            {
                if(z==2)
                {
                    if((v[j]==28 || v[j]==29))
                        z++;
                    else
                    {
                        k=1;
                        break;
                    }
                }
                else
                {
                    if(m[z]==v[j])
                    {
                        if(z==12)
                            z=1;
                        else
                            z++;
                    }
                    else
                    {
                        k=1;
                        break;
                    }
                }
            }
            if(k==0)
            {
                p=1;
                break;
            }
        }

        if(p)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    else
    {
        k=0,z=2;
        for(j=0; j<n; j++)
        {

            if(z==2)
            {
                if((v[j]==28 || v[j]==29))
                    z++;
                else
                {
                    k=1;
                    break;
                }
            }
            else
            {
                if(m[z]==v[j])
                {
                    if(z==12)
                        z=1;
                    else
                        z++;
                }
                else
                {
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
        {
            p=1;
        }

        if(p)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }


    return 0;
}
