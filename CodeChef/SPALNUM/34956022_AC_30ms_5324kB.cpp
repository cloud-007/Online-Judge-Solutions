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
ll Ans[N];

int check(int number) {
    int ret = number;
    vector < int > v;
    while(number) {
        v.push_back(number % 10);
        number /= 10;
    }
    int i = 0, j = v.size() - 1;
    while(i <= j) {
        if(v[i] != v[j])return 0;
        ++i; --j;
    }
    return ret;
}

void init() {
    for(int i = 1; i < N; i++) {
        if(check(i))Ans[i] = i;
        else Ans[i] = 0;
        Ans[i] += Ans[i - 1];
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    init();
    cin >> tc;
    while(tc--) {
        int l, r; cin >> l >> r;
        cout << Ans[r] - Ans[l - 1] << endl;
    }


    return 0;
}
