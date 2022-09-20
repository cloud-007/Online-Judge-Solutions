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
int tc, n, m, cnt[N], Total = 0;
deque < pair < int, int >> two;
deque < int > x[N], stored[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int tot, cnt = 0; cin >> tot;
        Total += tot;
        while(tot--) {
            int a; cin >> a;
            x[i].push_back(a);
        }
    }
    for(int i = 1; i <= m; i++) {
        int value = x[i][0];
        cnt[value]++;
        stored[value].push_back(i);
        if(cnt[value] == 2) {
            two.push_back({stored[value][0], stored[value][1]});
        }
    }
    int Cnt = 0;
    while(two.size()) {
        Cnt += 2; pair < int, int > cur = two.front(); two.pop_front();
        x[cur.F].pop_front();
        x[cur.S].pop_front();
        if(x[cur.F].size()) {
            int value = x[cur.F][0];
            cnt[value]++;
            stored[value].push_back(cur.F);
            if(cnt[value] == 2) {
                two.push_back({stored[value][0], stored[value][1]});
            }
        }
        if(x[cur.S].size()) {
            int value = x[cur.S][0];
            cnt[value]++;
            stored[value].push_back(cur.S);
            if(cnt[value] == 2) {
                two.push_back({stored[value][0], stored[value][1]});
            }
        }
    }
    cout << (Total == Cnt ? "Yes" : "No") << endl;

    return 0;
}
