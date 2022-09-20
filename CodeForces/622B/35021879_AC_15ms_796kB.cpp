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
    int hour, minute, passed;
    char c;
    cin >> hour >> c >> minute >> passed;
    minute += hour * 60;
    minute += passed;
    hour = minute / 60;
    hour %= 24;
    minute %= 60;
    string h = to_string(hour);
    if(h.size() == 1)h = "0" + h;
    string m = to_string(minute);
    if(m.size() ==1)m = "0" + m;
    h += ":" + m;
    cout << h << endl;


    return 0;
}
