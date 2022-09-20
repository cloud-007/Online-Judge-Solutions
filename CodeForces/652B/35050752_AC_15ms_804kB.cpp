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
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    int i = 1, j = n;
    vector < int > v;
    v.push_back(INT_MAX);
    while(i <= j) {
        v.push_back(a[i++]);
        if(i <= j)v.push_back(a[j--]);
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        if(i & 1 && v[i]>v[i-1])ok = false;
        if(i%2==0 && v[i]<v[i-1])ok = false;
    }
    if(!ok)cout <<"Impossible"<<endl;
    else for(int i=1;i<=n;i++)cout << v[i]<<" ";


    return 0;
}
