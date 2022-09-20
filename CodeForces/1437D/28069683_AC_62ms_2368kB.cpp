/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, a[200005], sum, next_sum, level, cnt = 1;
vector < int > v;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        v.clear();
        sum = next_sum = level = 0, cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 2; i <= n; i++) {
            if(a[i] > a[i - 1])cnt++;
            else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);

        for(auto i : v) {
            next_sum += i;
            if(sum)sum--;
            if(sum == 0) {
                sum=next_sum;
                level++;
                next_sum=0;
            }
        }
        if(next_sum)level++;

        cout << level << endl;
    }

    return 0;
}
