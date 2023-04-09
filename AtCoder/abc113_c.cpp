/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, m, p[sz], y[sz];
vector < pair < int, int >> x[sz];
string ans[sz];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> p[i] >> y[i];
        x[p[i]].push_back({y[i], i});
    }

    for(int i = 1; i <= n; i++)sort(x[i].begin(), x[i].end());

    int id = 1;

    for(int i = 1; i <= n; i++) {
        if(x[i].empty())continue;
        id = 1;
        string left = "", s = to_string(i);
        int N = s.size();
        N = 6 - N;
        while(N--)left += "0";
        left += s;
        for(auto j : x[i]) {
            string right = "", ss = to_string(id);
            N = ss.size();
            N = 6 - N;
            while(N--)right += "0";
            right += ss;
            ++id;
            ans[j.S] = left + right;
        }
    }

    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;


    return 0;
}
