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
int tc, n, a[N];

vector < int > x, temp, ans;

void div(int n) {
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            x.push_back(i);
            if(n / i != i)x.push_back(n / i);
        }
    }
    sort(x.rbegin(), x.rend());
}

void find_max(int cur, int idx) {
    if(idx >= x.size()) {
        if(temp.size() > ans.size()) {
            ans.clear();
            for(auto i : temp)ans.push_back(i);
        }
        return;
    }
    if(cur % x[idx] == 0) {
        temp.push_back(x[idx]);
        find_max(x[idx], idx + 1);
        temp.pop_back();
    }
    find_max(cur, idx + 1);
}

int main() {
#ifdef cloud_007
    //freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    temp.push_back(n);
    div(n);
    find_max(n, 1);
    for(auto i : ans)cout << i << " ";
    cout << endl;

    return 0;
}
