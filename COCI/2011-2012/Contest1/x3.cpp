#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
long long bi[20];
int main(int argc, char** argv) {
    int N=0;
    scanf("%d",&N);
    int a;
    for(int i=0;i<N;i++){
        scanf("%d",&a);
        int x=0;
        while(a>0){
            if(a%2==1){bi[x]++;}
            a=a/2;
            x++;
        }
    }
    
    long long ans = 0LL;
    long long m=1LL;
    for(int y=0;y<20;y++){
        ans+=(bi[y])*(N-bi[y])*m;
        m=m*2;
    }
    printf( "%lld\n", ans );
    return 0;
}