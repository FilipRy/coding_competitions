#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int Lj,S,vys[5],x;
    scanf("%d %d",&Lj,&S);
    for(int a=0;a<5;a++){
        scanf("%d",&x);
        vys[a]=x-Lj*S;
    }
    for(int a=0;a<5;a++){
        printf("%d",vys[a]);
        if(a<4){printf(" ");}
    }printf("\n");
    return 0;
}