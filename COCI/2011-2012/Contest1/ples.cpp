#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int bk[100000];
int bz[100000];
int gk[100000];
int gz[100000];
int N;
int maxN;
int main(int argc, char** argv) {
    scanf("%d",&N);
    maxN=0;
    int b,g;
    int iB,iB2,iG,iG2;
    iB=0;
    iB2=0;
    iG=0;
    iG2=0;
    for(int i=0;i<N;i++){
        scanf("%d",&b);
        if(b<0){bz[iB++]=b;}
        if(b>=0){bk[iB2++]=b;}
    }
    for(int i=0;i<N;i++){
        scanf("%d",&g);
        if(g>=0){gk[iG2++]=g;}
        if(g<0){gz[iG++]=g;}
    }
    sort(bz,bz+iB);
    sort(gk,gk+iG2);
    int n1=0;
    int y=0;
    for(int i=iG2-1;i>=0;i--){
        int a=gk[i];
        bool f=false;
        while(y<iB){
            if(-bz[y]>a){f=true;y++;break;}
            if(-bz[y]<=a){break;}
            y++;
        }
        if(f){n1++;}
    }
    sort(bk,bk+iB2);
    sort(gz,gz+iG);
    y=0;
    for(int i=iB2-1;i>=0;i--){
        int a=bk[i];
        bool f=false;
        while(y<iG){
            if(-gz[y]>a){f=true;y++;break;}
            if(-gz[y]<=a){break;}
            y++;
        }
        if(f){n1++;}
    }
    printf("%d\n",n1);
    return 0;
}