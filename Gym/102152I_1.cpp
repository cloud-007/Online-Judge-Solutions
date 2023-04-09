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
    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        priority_queue <int> pq;
        while(n--) {
            int x; cin >> x;
            pq.push(-x);
        }
        while(k--) {
            int cur = pq.top(); pq.pop();
            pq.push(-cur);
        }
        int Ans = 0;
        while(pq.size()) {
            Ans += -pq.top(); pq.pop();
        }
        cout << Ans << endl;
    }


    return 0;
}
