///s=(a+b+c+d)/2;
///trapezium formula = (a+b)/(a-b)*sqrt((s-a)(s-b)(s-b-c)(s-b-d))
///for(triangle) s=(a+b+c)/2 and its area= sqrt(s*(s-a)(s-b)(s-c)
///for calculation ae=(ad/ab)*ac;
/// de=(ad/ab)*bc;

#include<bits/stdc++.h>
using namespace std;

void solve(double ab,double bc,double ac, double item)
{
    double lo=0.0,hi=ab*1.0,triangle,trapezium;
    double ad,ae,de,ts,tre,ans=0.0;
    while(hi-lo>.00000001)
    {
        double mid=(lo+hi)/2;
        ad=mid;
        ae=(ad/ab)*ac;
        de=(ad/ab)*bc;
        ts=(ad+ae+de)/2;
        tre=(bc+(ab-ad)+(ac-ae)+de)/2;
        triangle=sqrt(ts*abs(ts-ad)*abs(ts-de)*abs(ts-ae));
        ///a=bc= long prl side b=de=short;
        trapezium=((bc+de)/(bc-de))*sqrt(abs(tre-bc)*abs(tre-de)*abs(tre-de-(ab-ad))*abs(tre-de-(ac-ae)));
        double rat=triangle/trapezium;
        ans=mid;
        if(abs(item-rat)<=0.00000001)
        {
            ans=mid;
            break;
        }
        else if(rat>item)
            hi=mid;
        else lo=mid;
    }
    cout<<fixed;
    cout<<setprecision(6)<<ans<<endl;
}

int main()
{
   // freopen("in.txt","r",stdin);
    cin.tie(0),cout.tie(0);
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        double ab,bc,ac,rat;
        cin>>ab>>bc>>ac>>rat;
        cout<<"Case "<<casee++<<": ";
        solve(ab,bc,ac,rat);
    }
}
