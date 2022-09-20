/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n;
string a, b;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> a >> b;
    string number_a = "", number_b = "";
    for(int i = a.size() - 1; i >= 0; i--) {
        if(a[i] >= '0' && a[i] <= '9') {
            number_a += a[i];
        } else break;
    }
    for(int i = b.size() - 1; i >= 0; i--) {
        if(b[i] >= '0' && b[i] <= '9') {
            number_b += b[i];
        } else break;
    }

    reverse(number_a.begin(), number_a.end());
    reverse(number_b.begin(), number_b.end());

    //cout <<number_a <<" "<<number_b <<endl;
    // if(number_a.empty())number_a = "0";
    // if(number_b.empty())number_b = "0";

    for(int i = 0; i < min(a.size(), b.size()); i++) {
        if(a[i] >= 'a' && a[i] <= 'z' && b[i] >= 'a' && b[i] <= 'z') {
            if(a[i] == b[i])continue;
            else if(a[i] < b[i]) {
                cout << "<" << endl;
                exit(0);
            } else {
                cout << ">" << endl;
                exit(0);
            }
        }
    }
    if(number_a.size()<number_b.size())cout<<"<"<<endl;
    else if(number_a.size()>number_b.size())cout<<">"<<endl;
    else{
        for(int i=0;i<a.size();i++){
            if(a[i]<b[i]){
                cout<<"<"<<endl;
                exit(0);
            }else if(a[i]>b[i]){
                cout <<">"<<endl;
                exit(0);
            }
        }
        cout<<"="<<endl;
    }


    return 0;
}
