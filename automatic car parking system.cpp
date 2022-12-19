#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    int totalcar=4,caramountS=10,caramountM=30,caramountH=100;
    int p,q,r,h,d,e,x,y,z,t,k,l,f,g,i;
    int startimeh[totalcar]={0},startimemin[totalcar]={0},startimesec[totalcar]={0};
    SYSTEMTIME a,b,v,n,m;
    int c=1,vehicle[totalcar]={0},amount=0,out,input,totalamount,allcaramount=0;
    GetLocalTime(&v);
    cout<<"Date :"<<v.wDay<<"/"<<v.wMonth<<"/"<<v.wYear<<endl;


while(true){
    cout<<"press 1 for entering parking"<<endl;
    cout<<"press 2 for leaving parking"<<endl;
    cout<<"press 3 for total amount"<<endl;
    cin>>input;

if(input==1)
{

     int position=-1;
    for(int i=0;i<totalcar;i++)
        {
        if(vehicle[i]==0)
        {
        position=i;
        break;
        }
        }
    if(position!=-1){
    GetLocalTime(&b);

    x=b.wHour;
    y=b.wMinute;
    z=b.wSecond;
    cout<<"Start Time :"<<x<<":"<<y<<":"<<z<<endl;
    c=position;
    startimeh[c]=x;
    startimemin[c]=y;
    startimesec[c]=z;

    vehicle[c]=1;

    cout<<"car: "<<c<<endl;
    }
    else
    cout<<"there is no space"<<endl;


 }
 else if(input==2)
 {
     cout<<"please give the out going car number :"<<endl;
 cin>>out;
 amount=0;
 if(vehicle[out]==1)
 {
    GetLocalTime(&a);
    h=a.wHour;
    d=a.wMinute;
    e=a.wSecond;
    cout<<" End Time :"<<h<<":"<<d<<":"<<e<<endl;


      //..................................start of calculation of difftime...............//
       if(e<startimesec[out])
        {
            p=(e+60)-startimesec[out];
        }
        else if(e>startimesec[out])
        {
            p=e-startimesec[out];
        }
        else if(e==startimesec[out])
        {
            p=e-startimesec[out];
        }

        if(d>startimemin[out] &&e<startimesec[out])
        {
            q=d-(startimemin[out]+1);
        }
        else if((d>startimemin[out]) && (e>startimesec[out]))
        {
            q=d-startimemin[out];
        }
        else if(d<startimemin[out] && e<startimesec[out])
        {
            q=(d+60)-(startimemin[out]+1);
        }
        else if(d<y && e>startimesec[out])
        {
            q=(d+60)-startimemin[out];
        }
        else if(d>startimemin[out] && e==startimesec[out])
        {
            q=d-startimemin[out];
        }
        else if(d<startimemin[out] && (e==startimesec[out]))
        {
            q=(d+60)-startimemin[out];
        }
        else if((d==startimemin[out]) && e<startimesec[out])
        {
            q=(d+60)-(startimemin[out]+1);
        }
        else if((d==startimemin[out])&& e>startimesec[out])
        {
            q=d-startimemin[out];
        }
      else if((d==startimemin[out]) && (e==startimesec[out]))
        {
            q=d-startimemin[out];
        }

       if( (h<startimeh[out] ||h>startimeh[out]||(h==startimeh[out])) && d>startimemin[out] && e<startimesec[out])
       {
           r=h-startimeh[out];
       }
       else if((h<startimeh[out] ||h>startimeh[out]||(h==startimeh[out])) && d<startimemin[out] && e<startimesec[out])
       {
           r=h-(startimeh[out]+1);
       }
       else if((h<startimeh[out] ||h>startimeh[out]||(h==startimeh[out])) && d<startimemin[out] && e>startimesec[out])
       {
           r=h-(startimeh[out]+1);
       }
       else if((h<startimeh[out] ||h>startimeh[out]||(h==startimeh[out])) && d>startimemin[out] && (e==startimesec[out]))
       {
           r=h-startimeh[out];
       }
       else if((h<startimeh[out] ||h>startimeh[out]||(h==startimeh[out])) &&  d<startimemin[out] && (e==startimesec[out]))
       {
           r=h-(startimeh[out]+1);
       }
       else if((h<startimeh[out] ||h>startimeh[out]||(h==startimeh[out])) && (d==startimemin[out])&&(e<startimesec[out]))
       {
           r=h-(startimeh[out]+1);
       }
       else if((h<startimeh[out] ||h>startimeh[out]||(h==startimeh[out])) && (d==startimemin[out])&&e>startimesec[out])
       {
           r=h-startimeh[out];
       }
       else if((h<startimeh[out] ||h>startimeh[out] ||(h==startimeh[out])) && (d==startimemin[out])&&(e==startimesec[out]))
       {
           r=h-startimeh[out];
       }

       else if((h<startimeh[out] ||h>startimeh[out] ||(h==startimeh[out])) && (d>startimemin[out])&&(e>startimesec[out]))
       {
           r=h-startimeh[out];
       }

//.........................................end of difftime.................................//
       totalamount=0;
       amount=caramountS;
       if(p>=2 && p<=3)
       {

        amount=amount*1;
        totalamount=totalamount+amount;
       }
        else if(p>=4 && p<=10)
       {

        amount=amount*2;
        totalamount=totalamount+amount;

       }
        else if(p>=11 && p<=59)
       {
        amount=amount*3;
        totalamount=totalamount+amount;
       }
       amount=caramountM;
       if(q==1)
       {
        amount=amount*4;
        totalamount=totalamount+amount;

       }
       else if(q>=2 && q<=3)
       {
        amount=amount*5;
        totalamount=totalamount+amount;

       }
        else if(q>=4 && q<=10)
       {
        amount=amount*6;
        totalamount=totalamount+amount;

       }
        else if(q>=11 && q<=59)
       {
           cout<<"y7"<<endl;
        amount=amount*7;
        totalamount=totalamount+amount;

       }
       amount=caramountH;
       if(r==1)
       {
        amount=amount*8;
        totalamount=totalamount+amount;

       }
       else if(r>=2&&r<6)
       {
        amount=amount*9;
        totalamount=totalamount+amount;

       }
       else if(r>=6 && r<=20)
       {
        amount=amount*10;
        totalamount=totalamount+amount;

       }
       else if(r>20 && r<=24)
       {
        amount=amount*11;
        totalamount=totalamount+amount;

       }
       cout<<"difftime :"<<r<<":"<<q<<":"<<p<<":"<<endl;
       cout<<"out going vehicle amount :"<<totalamount<<endl;
       vehicle[out]=0;
       allcaramount=allcaramount+ totalamount;
       }
       else
        cout<<"there is no car"<<endl;
 }
else if(input==3)
{
    cout<<"totalamount :"<<allcaramount<<endl;
}
}
//............end of while......................................................//
    return 0;
}
