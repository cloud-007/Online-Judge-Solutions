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
int len, finalSum;
vector < int > vec, Ans;

void rec(int idx, int sum) {
    if(idx > n) {
        if(sum > finalSum) {
            finalSum = sum;
            Ans.clear();
            for(auto i : vec)Ans.push_back(i);
        }
        return;
    }
    if(sum + a[idx] <= len) {
        vec.push_back(a[idx]);
        rec(idx + 1, sum + a[idx]);
        vec.pop_back();
    }
    rec(idx + 1, sum);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> len) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        finalSum = 0; Ans.clear(); vec.clear();
        rec(1, 0);
        for(auto i : Ans)cout << i << " ";
        cout << "sum:" << finalSum << endl;
    }


    return 0;
}
