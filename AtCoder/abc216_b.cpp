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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    set < pair < string , string >> st;
    while(n--){
        string x, y;
        cin >> x >> y;
        if(st.count({x , y})){
            cout<<"Yes"<<endl;
            exit(0);
        }
        st.insert({x, y});
    }
    cout<<"No"<<endl;

    return 0;
}
