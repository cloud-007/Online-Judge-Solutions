/*One touch and i IGNITE*/
#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n;

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

PT a[105], b[105];

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

bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
           && fabs(cross(a - b, a - c)) < EPS
           && fabs(cross(c - d, c - a)) < EPS;
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if(LinesCollinear(a, b, c, d)) {
        if(dist2(a, c) < EPS || dist2(a, d) < EPS ||
                dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
        if(dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
            return false;
        return true;
    }
    if(cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
    if(cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
    return true;
}

bool PointInPolygon(const vector<PT> &p, PT q) {
    bool c = 0;
    int s = p.size();
    for(int i = 0, j = s - 1; i < s; j = i++) {
        if(((p[i].y > q.y) != (p[j].y > q.y)) &&
                (q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)))
            c = !c;
    }
    return c;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        PT a, b, upper_left, lower_right;
        cin >> a.x >> a.y >> b.x >> b.y >> upper_left.x >> upper_left.y >> lower_right.x >> lower_right.y;
        PT lower_left = PT(upper_left.x, lower_right.y);
        PT upper_right = PT(lower_right.x, upper_left.y);
        bool Ans = SegmentsIntersect(upper_left, upper_right, a, b);
        if(Ans) {
            cout << "T" << endl;
            continue;
        }
        Ans = SegmentsIntersect(upper_right, lower_right, a, b);
        if(Ans) {
            cout << "T" << endl;
            continue;
        }
        Ans = SegmentsIntersect(lower_left, lower_right, a, b);
        if(Ans) {
            cout << "T" << endl;
            continue;
        }
        Ans = SegmentsIntersect(lower_left, upper_left, a, b);
        if(Ans) {
            cout << "T" << endl;
            continue;
        }
        vector < PT > v;
        v.push_back(upper_left);
        v.push_back(upper_right);
        v.push_back(lower_left);
        v.push_back(lower_right);
        if(PointInPolygon(v, a) || PointInPolygon(v, b)) {
            cout << "T" << Endl;
            continue;
        }
        cout << "F" << Endl;
    }

    return 0;
}
