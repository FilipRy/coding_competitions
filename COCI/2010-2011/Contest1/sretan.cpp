#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char** argv) {
    int N;
    scanf("%d",&N);
    int mocniny[30];
    int y=N;
    int n=1;
    int x=0;
    int c=0;
    while(x<N){
        n=n*2;
        x=x+n;
        mocniny[c]=n;
        c++;
    }
    x=x-n;
    y=y-x;
    c--;
    for(int i=c;i>0;i--){
        int ii=mocniny[i-1];
        if(y>ii){
            printf("7");
            y=fabs(y-ii);
        }
        else if(y<=ii){
            printf("4");
        }
        
    }
    if(N%2==0){printf("7\n");}
    if(N%2==1){printf("4\n");}
    return 0;
}
