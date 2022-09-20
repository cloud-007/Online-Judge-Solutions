/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1429431 + 5;
int tc, n, casee = 1, a[N];

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

ordered_set os;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    for(int i = 1; i < N; i += 2)os.insert(i);

    for(int i = 1; i < N; i++) {
        int curIdx = *os.find_by_order(i);
        if(curIdx > os.size())break;
        vector < int > v;
        for(int j = curIdx; j < N; j += curIdx) {
            if(j > os.size())break;
            v.push_back(*os.find_by_order(j - 1));
        }
        for(auto j : v)os.erase(j);
        v.clear();
    }

    cin >> tc;
    while(tc--) {
        cin >> n;
        cout << "Case " << casee++ << ": " << *os.find_by_order(n - 1) << endl;
    }


    return 0;
}
