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
    deque < int > zero;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0)zero.push_back(i);
    }
    int lastZero = -1;

    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            cout << 0 << " ";
            lastZero = i;
            if(zero.size())zero.pop_front();
            continue;
        }
        int Ans = INT_MAX;
        if(~lastZero)Ans = min(Ans, i - lastZero);
        if(zero.size())Ans = min(Ans, zero.front() - i);
        cout << Ans << " ";
    }
    cout << endl;


    return 0;
}
