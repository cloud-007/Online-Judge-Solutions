/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
unsigned long long a, b;

string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    if(len1 == 0 || len2 == 0)
        return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0, i_n2 = 0;

    for(int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;
        for(int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }
        if(carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while(i >= 0 && result[i] == 0)
        i--;
    if(i == -1)
        return "0";
    string s = "";

    while(i >= 0)
        s += to_string(result[i--]);

    return s;
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> a >> b;
    if(b - a >= 10)cout << 0 << endl;
    else {
        string ans = "1";
        while(b > a) {
            ans = multiply(ans, to_string(b));
            --b;
        }
        cout << ans[ans.size() - 1] << endl;
    }

    return 0;
}
