/*One touch and i IGNITE*/
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<algorithm>
#include<utility>
#include<iterator>
#include<istream>
#include<map>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, ans;
string s;

struct node {
    bool endmark;
    node* next[27];
    int cnt;
    node() {
        endmark  = cnt = false;
        for (int i = 0; i < 27; i++)
            next[i] = NULL;
    }
} * root;

void insert(string str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;
}

int search(string str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return i + 1;
        curr = curr->next[id];
        if(curr->cnt == 1) {
            curr->cnt++;
            return i + 1;
        }
    }
    curr->cnt++;
    return len;
}

void del(node* cur) {
    for (int i = 0; i < 27; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    root = new node();
    vector < string > v;
    set < string > st;
    set < string > :: iterator it;
    while(cin >> s) {
        v.push_back(s);
        st.insert(s);
        insert(s, s.size());
    }
    map < string, string > mp;

    for(it = st.begin(); it != st.end(); it++) {
        string i = *it;
        int len = search(i, i.size());
        string x = i.substr(0, len);
        mp[i] = x;
    }
    for(int i=0;i<v.size();i++){
        cout << v[i]<<" "<<mp[v[i]]<<endl;
    }

    return 0;
}
