#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int N,M,J;
    scanf("%d %d",&N,&M);
    scanf("%d",&J);
    int pos;
    int d=0;
    int x=0;
    for(int i=0;i<J;i++){
        scanf("%d",&pos);
        pos--;
        if(pos>x){
            if(x+M-1<pos){
                d=d+(pos-(x+M-1));
                x=pos-(M-1);
            }
        }
        if(pos<x){
            d=d+(x-pos);
            x=pos;
        }
    }
    printf("%d\n",d);
    return 0;
}