/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, a;
stack < int > st;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(st.empty())st.push(a);
        else if((st.top() + a) % 2 == 0) {
            st.pop();
        } else st.push(a);
    }

    cout << st.size() << endl;


    return 0;
}
