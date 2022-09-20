#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int tc,casee=1;
    cin>>tc;
    stack < string > bc,fc;
    while(tc--)
    {
        printf("Case %d:\n",casee++);
        string s,now;
        while(!bc.empty())
            bc.pop();
        while(!fc.empty())
            fc.pop();
        now="http://www.lightoj.com/";
        while(cin>>s && s!="QUIT")
        {
            string go;
            if(s=="VISIT")
            {
                cin>>go;
                bc.push(now);
                now=go;
                cout<<now<<endl;
                while(!fc.empty())
                    fc.pop();
            }
            else if(s=="BACK")
            {
                if(bc.size())
                {
                    fc.push(now);
                    now=bc.top();
                    cout<<now<<endl;
                    bc.pop();
                }
                else
                    cout<<"Ignored"<<endl;

            }
            else if(s=="FORWARD")
            {
                if(fc.size())
                {
                    bc.push(now);
                    now=fc.top();
                    cout<<now<<endl;
                    fc.pop();
                }
                else
                    cout<<"Ignored"<<endl;
            }
        }
    }
}
