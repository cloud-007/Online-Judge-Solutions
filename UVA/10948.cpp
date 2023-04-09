/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e6 + 5;
int tc, n, c, a[N + 5], lp[N + 5];
vector < int > pr;

void sieve() {
    for(int i = 2; i <= N; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve();
    while(cin >> n && n){
        bool flag = true;
        printf("%d:\n", n);
        for(auto i : pr){
            if(i>=n)break;
            if(lp[n-i] == n-i){
                printf("%d+%d\n", i, n-i);
                flag = false;
                break;
            }
        }
        if(flag)printf("NO WAY!\n");
    }


    return 0;
}
