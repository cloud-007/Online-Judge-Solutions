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
int tc, n, casee = 1, a[N], Div[1005];

struct R {
    int number, count;
    bool operator<(R a)const {
        if(count == a.count)return number>a.number;
        return count<a.count;
    }
};

vector < R > v;

void init() {
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) {
                Div[i]++;
                if(i / j != j)Div[i]++;
            }
        }
        v.push_back({i, Div[i]});
    }
    sort(v.begin(), v.end());
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    init();
    cin >> tc;
    while(tc--) {
        cin >> n;
        cout << "Case " << casee++ << ": " << v[n - 1].number << endl;
    }


    return 0;
}
