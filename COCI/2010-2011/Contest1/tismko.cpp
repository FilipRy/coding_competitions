#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int M,N,T;
    scanf("%d %d %d",&M,&N,&T);
    int g=2;
    int b=1;
    int t=1;
    while(true){
        if(g*t<=M&&b*t<=N&&g*t+b*t+T<=M+N){}
        else{break;}
        t++;
    }
    printf("%d\n",t-1);
    return 0;
}