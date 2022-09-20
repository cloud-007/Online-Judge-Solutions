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
    cin >> n ;
    deque < int > even, odd;
    vector < int > original;
    while(n--) {
        int x; cin >> x;
        original.push_back(x);
        if(x & 1)odd.push_back(x);
        else even.push_back(x);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if(even.size() && odd.size()) {
        while(even.size() || odd.size()) {
            if(even.size() && odd.size()) {
                if(even.front() < odd.front()) {
                    cout << even.front() << " ";
                    even.pop_front();
                } else {
                    cout << odd.front() << " ";
                    odd.pop_front();
                }
            } else if(even.size()) {
                cout << even.front() << " ";
                even.pop_front();
            } else {
                cout << odd.front() << " ";
                odd.pop_front();
            }
        }
        exit(0);
    }
    for(auto i : original)cout << i << " ";
    cout << endl;


    return 0;
}
