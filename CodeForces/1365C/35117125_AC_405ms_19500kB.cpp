/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];
map < int, int > mp, dis;


int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x; mp[x] = i;
    }

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        int pre = mp[x], cur = i;
        if(pre >= cur)dis[pre - cur]++;
        else dis[pre + (n - cur)]++;
    }

    int Ans = 0;

    for(auto i : dis)Ans = max(Ans, i.S);

    cout << Ans << endl;


    return 0;
}
