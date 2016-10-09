#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    FILE * pFile;
    pFile=fopen("input.txt","rw");
    int s1,s2,i1,i2;
    for(int a=0;a<4;a++){
        int h,m;
        fscanf(pFile,"%d:%d",&h,&m);
        if(a==0){s1=h*60+m;}
        if(a==1){s2=h*60+m;}
        if(a==2){i1=h*60+m;}
        if(a==3){i2=h*60+m;}
    }
    int y=1;
    int cf=0;
    bool found=false;
    bool e1=false;
    bool e2=false;
    while(true){
        if((s2+(i2*y)-s1)%(i1)==0){
            cf=s2+i2*y;
            found=true;
            break;
        }
        if((y*i1)%10080==0){
            e1=true;
        }
        if((y*i2)%10080){
            e2=true;
        }
        if(e1&&e2){
            found=false;
            break;
        }
        y++;
    }
    if(found){
        int h=cf/60;
        int m=cf%60;
        int d=h/24;
        d=d%7;
        h=h%24;
        if(d==0){cout<<"Saturnday";}
        if(d==1){cout<<"Sunday";}
        if(d==2){cout<<"Monday";}
        if(d==3){cout<<"Tuesday";}
        if(d==4){cout<<"Wednesday";}
        if(d==5){cout<<"Thursday";}
        if(d==6){cout<<"Friday";}
        cout<<'\n';
        if(h<10){cout<<"0";}
        cout<<h<<":";
        if(m<10){cout<<"0";}
        cout<<m<<'\n';
    }
    else{cout<<"Never\n";}
    return 0;
}