#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, casee = 1, n, mp[100];
set < int > st;
vector < int > prime;
bool isp(int n)
{
    for(int i = 3; i * i <= n; i++)if(n % i == 0)return false;
    return true;
}

void init()
{
    prime.push_back(2);
    for(int i = 3; i < 100; i += 2)
    {
        if(isp(i))prime.push_back(i);
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    init();
    cin >> tc;
    while(tc--)
    {
        memset(mp, 0, sizeof mp);
        st.clear();
        cin >> n;
        for(int i = 2; i <= n; i++)
        {
            int val = i;
            for(auto j : prime)
            {
                if(val == 1)break;
                while(val % j == 0 && val != 1)
                {
                    val /= j;
                    st.insert(j);
                    mp[j]++;
                }
            }
        }
        cout<<"Case "<<casee++<<": "<<n<<" = ";
        int cnt = 0;
        for(auto i : st)
        {
            cnt ++;
            cout<<i<<" ("<<mp[i]<<")";
            if(cnt < st.size())cout<<" * ";
        }
        cout<<endl;
    }
}
