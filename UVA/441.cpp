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
vector < int > v;
vector < vector < int >> Ans;

void rec(int idx) {
    if(v.size() == 6) {
        Ans.push_back(v);
        return;
    }
    if(idx > n)return;
    if(v.size() < 6) {
        v.push_back(a[idx]);
        rec(idx + 1);
        v.pop_back();
    }
    rec(idx + 1);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n && n) {
        for(int i = 1; i <= n; i++)cin >> a[i];
        rec(1);
        if(casee > 1)cout << endl;
        for(auto i : Ans) {
            for(int j = 0; j < 6; j++) {
                if(j)cout << " ";
                cout << i[j];
            }
            cout << endl;
        }
        ++casee;
        Ans.clear(); v.clear();
    }


    return 0;
}
