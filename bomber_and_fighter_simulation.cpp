#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,vf=20,time=12,xb[15]={80,90,99,108,116,125,133,141,151,160,169,179,180};

    int yb[15]={0,-2,-5,-9,-15,-18,-23,-29,-28,-25,-21,-20,-17};
    float yf[15],xf[15],dist,sqy,sqx,sin,cos;
    xf[0]=0;yf[0]=50;
    int gap,duration;
    cout<<"\tPure Pursuit Problem\n";

    for(i=1;i<=time;i++)
    {
        sqy = (yb[i]-yf[i])*(yb[i]-yf[i]);
        sqx = (xb[i]-xf[i])*(xb[i]-xf[i]);
        dist = sqrt(sqx+sqy);
        cout<<"\nDistance between fighter and bomber at t = "<<i<<" is : "<<dist<<endl;
        if(dist<=10)
        {
            cout<<"\nDestroyed at : ("<<xb[i]<<", "<<yb[i]<<") of bomber"<<"and at ("<<xf[i]<<", "<<yf[i]<<") of fighter \n";
            break;
        }
        sin = (yb[i]-yf[i])/dist;
        cos = (xb[i]-xf[i])/dist;
        xf[i+1] = xf[i]+ vf*(cos);
        yf[i+1] = yf[i]+ vf*(sin);


    }
    if(i>time)
    {
        cout<<"\n\nBomber escaped\n";
    }
    return 0;
}
