/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1050;
int n, c, lp[N + 1];
vector < int > pr;

void sieve() {
    pr.push_back(1);
    for(int i = 2; i <= N; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 1; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve();
    while(cin >> n >> c) {
        auto pos = lower_bound(pr.begin(), pr.end(), n) - pr.begin();
        if(pr[pos] > n)--pos;
        cout << n << " " << c << ": ";
        if(pos + 1 <= 2 * c) {
            for(int i = 0; i <= pos; i++){
                cout << pr[i];
                if(i<pos)cout<<" ";
            }
            cout << endl << endl;
        } else {
            int tot = pos + 1;
            c *= 2;
            int st = (tot - c) / 2;
            if(tot & 1)--c, ++st;
            for(int i = st, cnt = 1; cnt <= c; ++cnt, ++i){
                cout << pr[i];
                if(cnt<c)cout<<" ";
            }
            cout << endl << endl;
        }
    }

    return 0;
}
