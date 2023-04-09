/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 30 + 5;
int tc, q, row, col, casee = 1, par[N][N];
char c[N][N];
string name;
bool found = false;
vector < pair < int, int >> vp;

map < pair < int, int >, string > change;
map < char, vector < pair < int, int >>> mp;

void init() {
    change[ {0, 1}] = ", R";
    change[ {0, -1}] = ", L";
    change[ {1, 0}] = ", D";
    change[ {-1, 0}] = ", U";
    change[ {1, 1}] = ", DR";
    change[ {1, -1}] = ", DL";
    change[ {-1, 1}] = ", UR";
    change[ {-1, -1}] = ", UL";
    change[ {0, 0}] = ", *";
}

///Eight sided direction array:
int fx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col);
}

void dfs(int sx, int sy, int idx, int req) {
    if(found)return;
    if((int)vp.size() == req) {
        found = true;
        return;
    }

    if(c[sx][sy] == name[idx]) {
        vp.push_back({sx, sy});
        dfs(sx, sy, idx + 1, req);
        if(!found)vp.pop_back();
    }

    for(int i = 0; i < 8; i++) {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(!found && valid(tx, ty) && c[tx][ty] == name[idx]) {
            vp.push_back({tx, ty});
            dfs(tx, ty, idx + 1, req);
            if(!found)vp.pop_back();
        }
    }

}


int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;

    init();

    cin >> tc;
    while(tc--) {
        cin >> row >> col; mp.clear();

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                mp[c[i][j]].push_back({i, j});
            }
        }

        cin >> q;
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            cin >> name;
            found = true;
            for(auto i : name) {
                if(!mp[i].size())found = false;
            }
            if(!found) {
                cout << name << " not found" << endl;
                continue;
            }
            int sx, sy;
            for(auto i : mp[name[0]]) {
                vp.clear(); found = false;
                vp.push_back({i.F, i.S});
                dfs(i.F, i.S, 1, (int)name.size());
                sx = i.F, sy = i.S;
                if(found)break;
            }

            if(!found) {
                cout << name << " not found" << endl;
                continue;
            }

            string Ans = "";
            Ans += "(";
            Ans += to_string(sx);
            Ans += ",";
            Ans += to_string(sy);
            Ans += ")";

            for(int i = 0; i < vp.size() - 1; i++) {
                int tx = vp[i + 1].F - vp[i].F, ty = vp[i + 1].S - vp[i].S;
                Ans += change[ {tx, ty}];
            }

            cout << name << " found: " << Ans << endl;

        }

    }


    return 0;
}
