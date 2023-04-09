/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 10000  + 5;
int tc, n, l, a[sz];

void init() {
    int month = 4, cnt = 0, year = 2018;
    while(year <= 10000 ) {
        if(cnt == 0)a[year] = 1;
        month++, cnt++;
        if(month == 13) {
            month = 1, year++;
        }
        if(cnt == 26)cnt = 0;
    }

}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    memset(a, 0, sizeof a);
    init();
    while(cin >> n)
        puts(a[n] ? "yes" : "no");

    return 0;
}
