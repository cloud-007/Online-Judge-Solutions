/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, mp[20], firstNumber = -1;
vector <vector<int>>Ans;
vector < int > v;

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)return false;
    }
    return true;
}


void rec(int idx) {
    if(idx > n) {
        if(isPrime(v.back() + v.front())) {
            Ans.push_back(v);
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(mp[i])continue;
        if(v.empty()) {
            mp[i] = true;
            v.push_back(i);
            rec(idx + 1);
            v.pop_back();
            mp[i] = false;
        } else {
            if(isPrime(v.back() + i)) {
                mp[i] = true;
                v.push_back(i);
                rec(idx + 1);
                v.pop_back();
                mp[i] = false;
            }
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n) {
        v.clear(); Ans.clear();
        memset(mp, false, sizeof mp);
        v.push_back(1);
        mp[1] = true;
        rec(2);
        if(casee > 1)cout << endl;
        cout << "Case " << casee++ << ":" << endl;
        for(auto i : Ans) {
            for(int j = 0; j < i.size(); j++) {
                if(j)cout << " ";
                cout << i[j];
            }
            cout << endl;
        }
    }


    return 0;
}
