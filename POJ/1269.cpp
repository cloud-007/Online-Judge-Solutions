/*One touch and i IGNITE*/
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, a[sz];

const double INF = 1e100, EPS = 1e-9, PI = acos(-1.0);

int sign(double x) {
    return (x > EPS) - (x < EPS);
}

typedef struct PT {
    double x, y;
    PT() {};
    PT(double x, double y): x(x), y(y) {};
    PT(const PT &p): x(p.x), y(p.y) {};
    PT operator + (const PT &p)  const {
        return PT(x + p.x, y + p.y);
    }
    PT operator - (const PT &p)  const {
        return PT(x - p.x, y - p.y);
    }
    PT operator * (double c)     const {
        return PT(x * c,   y * c);
    }
    PT operator / (double c)     const {
        return PT(x / c,   y / c);
    }
    bool operator < (const PT &p)const {
        return x < p.x || x == p.x && y < p.y;
    }
    PT trunc(double t)const {
        double r = t / sqrt(x * x + y * y);

        if(sign(r) == 0) return *this;
        return PT(x * r, y * r);
    }
} point;

double dot(PT p, PT q) {
    return p.x * q.x + p.y * q.y;
}
double dist2(PT p, PT q) {
    return dot(p - q, p - q);
}
double norm2(PT p) {
    return dot(p, p);
}
double norm(PT p) {
    return sqrt(dot(p, p));
}
double distPoint(PT p, PT q) {
    return sqrt(dot(p - q, p - q));
}
double cross(PT p, PT q) {
    return p.x * q.y - p.y * q.x;
}
int orientation(PT a, PT b, PT c) {
    return sign(cross(b - a, c - a));
}
PT orth(PT p) {
    return PT(-p.y, p.x);
}

double distToLine(PT p, PT A, PT B) {
    double scale = (double)(dot(p - A, B - A)) / (dot(B - A, B - A));
    PT c;
    c.x = A.x + scale * (B.x - A.x);
    c.y = A.y + scale * (B.y - A.y);
    return distPoint(p, c);
}

bool LinesParallel(PT a, PT b, PT c, PT d) {
    return fabs(cross(b - a, c - d)) < EPS;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    double a1, b1, c1, a2, b2, c2;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = cross(a, b);
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = cross(c, d);
    double D = a1 * b2 - a2 * b1;
    return PT((b1 * c2 - b2 * c1) / D, (c1 * a2 - c2 * a1) / D);
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    cout << fixed << setprecision(2);
    while(tc--) {
        PT a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if(!(distToLine(c, a, b) + distToLine(d, a, b))) {
            cout << "LINE" << endl;
        } else if(distToLine(a, c, d) + distToLine(b, c, d) == 0) {
            cout << "LINE" << endl;
        } else if(LinesParallel(a, b, c, d))cout << "NONE" << endl;
        else {
            PT Ans = ComputeLineIntersection(a, b, c, d);
            cout << "POINT " << Ans.x << " " << Ans.y << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
