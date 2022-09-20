/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], b[N], dp[N][2];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;

        for(int i = 1; i <= n; i++)cin >> a[i];

        deque < int > one, two;

        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            if(b[i] == 1)one.push_back(a[i]);
            else two.push_back(a[i]);
        }

        sort(one.begin(), one.end());
        sort(two.begin(), two.end());

        ll sum = 0, conv = 0;

        while(one.size() || two.size()) {
            if(one.size() >= 2 && two.size()) {
                if(sum + one.back() >= m) {
                    conv++;
                    sum += one.back();
                    break;
                }
                int onlyTwo = two.back();
                int onlyOne = one[one.size() - 1] + one[one.size() - 2];
                if(onlyOne > onlyTwo) {
                    sum += one.back();
                    one.pop_back();
                    conv++;
                } else {
                    sum += onlyTwo;
                    two.pop_back();
                    conv += 2;
                }
                if(sum >= m)break;
            } else if(one.size() == 1 && two.size()) {
                if(sum + one.back() >= m) {
                    conv++;
                    sum += one.back();
                    break;
                } if(sum + two.back() >= m) {
                    conv += 2;
                    sum += two.back();
                    break;
                }
                if(sum + one.back() + two.back() >= m) {
                    conv += 3;
                    sum += one.back() + two.back();
                    break;
                } if(one.back() >= two.back()) {
                    sum += one.back(); conv++;
                    one.pop_back();
                } else {
                    sum += two.back(); conv += 2;
                    two.pop_back();
                }
            } else if(two.size()) {
                sum += two.back(); two.pop_back();
                conv += 2;
                if(sum >= m)break;
            } else if(one.size()) {
                sum += one.back(); one.pop_back();
                conv++;
                if(sum >= m)break;
            }
        }

        if(sum >= m)cout << conv << endl;
        else cout << -1 << endl;


    }


    return 0;
}
