#include<iostream>
using namespace std;
int main()
{
    ///boys max 2
    int gl,gr,bl,br;
    cin>>gl>>gr>>bl>>br;
    int x=abs(gl-br);
    int y=abs(gr-bl);
    if((gl>br && abs(gl-br)<=1)||(gl==br || gr==bl) || (gr>bl&& abs(gr-bl)<=1)||
       (gl<br && abs(gl-br)<(gl*2)+2)|| (gr<bl && abs(gr-bl)<(gr*2)+2))
        puts("YES");
    else
        puts("NO");
}
