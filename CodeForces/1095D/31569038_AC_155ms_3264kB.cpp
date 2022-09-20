/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, a[N][2];

void check(int l, int r) {
    vector < int > Ans;
    for(int i = 1; i <= n; i++) {
        int nxt = -1;
        if(a[l][0] == r) {
            nxt = a[l][1];
        } else if(a[l][1] == r) {
            nxt = a[l][0];
        } else return;
        Ans.push_back(nxt);
        l = r;
        r = nxt;
    }
    for(auto i : Ans)cout << i << " ";
    cout << endl;
    exit(0);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    check(1, a[1][0]);
    check(1, a[1][1]);


    return 0;
}
