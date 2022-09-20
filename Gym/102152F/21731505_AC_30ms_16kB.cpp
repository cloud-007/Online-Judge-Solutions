#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        string word="";
        vector<string>v;
        for(int i=0; i<s.size(); i++)
        {
            if(isupper(s[i]))
            {
                v.push_back(word);
                word="";
                word+=s[i];
                if(isupper(s[i+1]) && s[i+2]=='\0')
                {
                    v.push_back(word);
                    word="";
                    word+=s[i+1];
                    v.push_back(word);
                    word="";
                    break;
                }
            }
            else if(s[i+1]=='\0')
            {
                word+=s[i];
                word+=s[i+1];
                v.push_back(word);
                break;
            }
            else
                word+=s[i];
        }
        int count=0;
        if(islower(v[0][0]))
            count++;
        for(int i=1; i<v.size(); i++)
        {

            if(isupper(v[i][0]))
                count++;
        }
       // cout<<v.size()<<endl;
       // cout<<count<<endl;
        if(v.size()<=7 && count==v.size())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
       // for(int i=0; i<v.size(); i++)
        // cout<<v[i]<<endl;
    }
}
