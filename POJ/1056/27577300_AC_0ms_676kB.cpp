/*One touch and i IGNITE*/
#include<iostream>
#include<fstream>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, casee = 1;
string s, ans = "-1";

struct node {
    bool endmark;
    node* next[2];
    node() {
        endmark = false;
        for (int i = 0; i < 2; i++)
            next[i] = NULL;
    }
} * root;

bool insert(string str, int len) {
    node* curr = root;
    bool ok = false, ok1 = true;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if(curr->endmark)ok = true;
        if (curr->next[id] == NULL)
            curr->next[id] = new node(), ok1 = false;
        curr = curr->next[id];
    }
    curr->endmark = true;
    return ok || ok1;
}

int search(string str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur) {
    for (int i = 0; i < 2; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    //cloud_007;
    root = new node();
    cin >> tc;
    bool check = false;
    while(cin >> s) {
        if(s == "9") {
            del(root);
            root = new node();
            cout << "Set " << casee++ << " is ";
            if(!check)cout << "immediately decodable" << endl;
            else cout << "not immediately decodable" << endl;
            check = false;
        } else {
            if(insert(s, s.size()))check = true;
        }

    }
    return 0;
}
