/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 500 + 5;
int tc, n, m, casee = 1, a[N][N], dp[N][1030];
vector < int > Ans;

bool ok = false;

void rec(int idx, int Xor) {
    if(idx > n) {
        if(Xor)ok = true;
        return;
    }
    if(ok)return;
    int &ret = dp[idx][Xor];
    if(~ret)return;
    ret = 0;
    for(int i = 1; i <= m; i++) {
        if(ok)return;
        Ans.push_back(i);
        rec(idx + 1, Xor ^ a[idx][i]);
        if(!ok)Ans.pop_back();
    }
}



int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    rec(1, 0);

    if(ok) {
        cout << "TAK" << endl;
        for(auto i : Ans)cout << i << " ";
        cout << endl;
    } else {
        cout << "NIE" << endl;
    }


    return 0;
}
