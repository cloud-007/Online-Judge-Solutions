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
set < int > st;
int same = 0, diff = 0;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(x == a[i])same++;
        else if(st.count(x))diff++;
    }
    cout << same << endl;
    cout << diff << endl;



    return 0;
}
