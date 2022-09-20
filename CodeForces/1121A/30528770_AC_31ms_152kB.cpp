/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 100 + 5;
int tc, n, m, k, a[sz], b[sz], used[sz];
vector < pair < int, int >> x[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        x[b[i]].push_back({a[i], i});
    }
    for(int i = 1; i <= m; i++)sort(x[i].begin(), x[i].end());

    int Ans = 0;

    while(k--) {
        int c; cin >> c;
        if(x[b[c]].size()) {
            if(x[b[c]].back().S == c){
                if(!used[b[c]])x[b[c]].pop_back();
                else Ans++;
                used[b[c]]=1;
            }else Ans++;
        } else Ans++;
    }

    cout << Ans << endl;


    return 0;
}
