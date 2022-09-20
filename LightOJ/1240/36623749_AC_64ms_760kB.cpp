/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1;

struct pt {
    double x, y, z;
};

pt a, b, p;

void inp(pt &x) {
    cin >> x.x >> x.y >> x.z;
}

void out(pt x) {
    cout << x.x << " " << x.y << " " << x.z << " ";
}

double dot(double x) {
    return x * x;
}

double planeDis(pt a, pt b) {
    double res = dot(a.x - b.x) + dot(a.y - b.y) + dot(a.z - b.z);
    return sqrt(res);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        inp(a); inp(b); inp(p);

        int cnt = 100;
        double Ans1, Ans2;
        while(cnt--) {
            pt f, s;
            f.x = (2 * a.x + b.x) / 3.0;
            f.y = (2 * a.y + b.y) / 3.0;
            f.z = (2 * a.z + b.z) / 3.0;

            s.x = (a.x + 2 * b.x) / 3.0;
            s.y = (a.y + 2 * b.y) / 3.0;
            s.z = (a.z + 2 * b.z) / 3.0;

            Ans1 = planeDis(f, p);
            Ans2 = planeDis(s, p);

            if(Ans1 > Ans2) a = f;
            else b = s;
        }

        cout << fixed << setprecision(8);
        cout << "Case " << casee++ << ": " << abs(Ans1 + Ans2) / 2.0 << endl;

    }


    return 0;
}
