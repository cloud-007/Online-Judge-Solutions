/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, p, m, allCase = 0, totalSuccess = 0;
string a, b;

void rec(int idx, int pre, int pls, int mns) {
    if(idx >= a.size()) {
        allCase++;
        if(pls == p && mns == m)totalSuccess++;
        return;
    }
    if(b[idx] == '+') {
        rec(idx + 1, 1, pls + 1, mns);
    } else if(b[idx] == '-') {
        rec(idx + 1, 0, pls, mns + 1);
    } else {
        rec(idx + 1, 1, pls + 1, mns);
        rec(idx + 1, 0, pls, mns + 1);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> a >> b;
    for(auto i : a) {
        if(i == '+')p++;
        else if(i == '-')m++;
    }

    rec(0, 0, 0, 0);

    cout << fixed << setprecision(10);

    cout << (float)totalSuccess / (float)allCase << endl;


    return 0;
}
