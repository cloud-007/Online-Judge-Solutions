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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    int Ans[n + 5];
    memset(Ans, false, sizeof Ans);
    for(int i = 2, cnt = 1; i <= n; i++) {
        bool found = false;
        for(int j = i; j <= n; j += i) {
            if(Ans[j])continue;
            found = true;
            Ans[j] = cnt;
        }
        if(found)++cnt;
    }
    for(int i = 2; i <= n; i++)cout << Ans[i] << " ";
    cout << endl;


    return 0;
}
