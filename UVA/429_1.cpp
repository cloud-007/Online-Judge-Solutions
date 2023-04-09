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
vector < string > v;
map < string, int > dis;
map < string, bool > vis;

void bfs(string u) {
    vis[u] = true;
    dis[u] = 0;
    queue < string > q;
    q.push(u);
    while(q.size()) {
        u = q.front(); q.pop();
        for(auto i : v) {
            if(i.size() != u.size() || i == u)continue;
            int diffPlace = 0;
            for(int j = 0; j < u.size(); j++)diffPlace += (u[j] != i[j]);
            if(diffPlace == 1) {
                if(dis[i] > dis[u] + 1) {
                    dis[i] = dis[u] + 1;
                    q.push(i);
                }
            }
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    bool newLine = false;
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc) {
        if(newLine)cout << endl;
        newLine = true;
        string s;
        while(cin >> s && s != "*")v.push_back(s);
        sort(v.begin(), v.end());
        cin.ignore();
        while(getline(cin, s) && s != "") {
            stringstream ss(s);
            string word, st = "-1", en;
            while(ss >> word) {
                if(st == "-1")st = word;
                else en = word;
            }
            vis.clear();
            dis.clear();
            for(auto i : v)dis[i] = INT_MAX;
            bfs(st);
            cout << st << " " << en << " " << dis[en] << endl;
        }
        --tc;
        v.clear();
    }


    return 0;
}
