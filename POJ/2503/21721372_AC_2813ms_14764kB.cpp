#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
int main()
{
    map<string,string >mp;
    map<string,string>::iterator it;
    string a;
    while(getline(cin,a) && !a.empty())
    {
        vector<string>v;
        int count=0;
        for(int i=0; i<a.size(); i++)
        {
            count++;
            if(a[i]==' ')
                break;
        }
       // v.push_back();
       // v.push_back();
       // cout<<v[0]<<' '<<v[1]<<endl;
        mp[a.substr(count,a.size())]=a.substr(0,count);
    }
    //for(auto i=mp.begin();i!=mp.end();i++)
    //    cout<<i->first<<' '<<i->second<<endl;
    string c;
    while(cin>>c)
    {
        if(c=="")
            break;
       // it=mp.find(c);
        if(mp.count(c))//it!=mp.end())
            cout<<mp[c]<<endl;
        else
            printf("eh\n");
    }
}
