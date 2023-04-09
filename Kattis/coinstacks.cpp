/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, a[sz];

priority_queue < pair < int, int >> pq;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(x)pq.push({x, i});
    }
    vector < pair < int, int >> ans;
    while(pq.size() >= 2) {
        pair < int, int > it = pq.top();
        pq.pop();
        pair < int, int > it1 = pq.top();
        pq.pop();
        ans.push_back({it.S, it1.S});
        it.F--, it1.F--;
        if(it.F)pq.push(it);
        if(it1.F)pq.push(it1);
    }

    if(pq.size())cout << "no" << Endl;
    else {
        cout << "yes" << endl;
        for(auto i : ans)cout << i.F << " " << i.S << endl;
    }


    return 0;
}
