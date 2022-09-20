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

ll check(deque < string > v, int f, int r, int c) {
    int cnt = 0;
    for(auto i : v) {
        if(i == "saturday" && r) {
            ++cnt, --r;
        } else if(i == "sunday" && f) {
            ++cnt, --f;
        } else if(i == "monday" && f) {
            ++cnt, --f;
        } else if(i == "tuesday" && r) {
            ++cnt, --r;
        } else if(i == "wednesday" && c) {
            ++cnt, --c;
        } else if(i == "thursday" && f) {
            ++cnt, --f;
        } else if(i == "friday" && c) {
            ++cnt, --c;
        } else break;
    }
    return cnt;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    int fish, rabbit, chicken;
    cin >> fish >> rabbit >> chicken;

    ll Ans = 0;

    int total_fish = fish / 3, rem_fish;
    int totalRabbit = rabbit / 2, remRabbit;
    int totalChicken = chicken / 2, remChicken;

    Ans = min({totalChicken, totalRabbit, total_fish});
    rem_fish = fish - (Ans * 3), remChicken = chicken - (Ans * 2), remRabbit = rabbit - (Ans * 2);
    ll remMax = 0;

    deque < string > v = {"saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday"};

    for(int i = 1; i <= 6; i++) {
        remMax = max(remMax, check(v, rem_fish, remRabbit, remChicken));
        v.push_back(v.front());
        v.pop_front();
    }

    cout << Ans * 7 + remMax << endl;


    return 0;
}
