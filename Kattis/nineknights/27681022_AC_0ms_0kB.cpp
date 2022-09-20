/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int cnt = 0;
char a[6][6];
int fx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int fy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool valid(int tx, int ty) {
    if(tx >= 1 && ty >= 1 && tx <= 5 && ty <= 5)return true;
    return false;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> a[i][j];
            if(a[i][j]=='k')cnt++;
        }
    }
    if(cnt!=9){
        cout<<"invalid"<<endl;
        return 0;
    }

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(a[i][j] == 'k') {
                for(int k = 0; k < 8; k++) {
                    int tx = i + fx[k], ty = j + fy[k];
                    if(valid(tx, ty) && a[tx][ty] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "valid" << endl;


    return 0;
}
