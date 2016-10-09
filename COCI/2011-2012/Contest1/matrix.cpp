#include <cstdlib>
#include <iostream>
using namespace std;
int sum[400][400][2];
int vstup[400][400];
int main(int argc, char** argv) {
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int y=0;y<N;y++){
            scanf("%d",&vstup[i][y]);
            sum[i][y][0]=vstup[i][y];
            sum[i][y][1]=vstup[i][y];
        }
    }
    int max=-800000;
    for(int i=2;i<=N;i++){
        for(int y=i-1;y<N;y++){
            for(int z=i-1;z<N;z++){
                sum[y][z][0]=sum[y-1][z-1][0]+vstup[y][z];
                sum[y][z-i+1][1]=sum[y-1][z-i+2][1]+vstup[y][z-i+1];
                if(y>=i&&z>=i){
                    sum[y][z][0]=sum[y][z][0]-vstup[y-i][z-i];
                }
                if(y>=i&&y-i>=0&&z+1<N){sum[y][z-i+1][1]=sum[y][z-i+1][1]-vstup[y-i][z+1];}
                if(sum[y][z][0]-sum[y][z-i+1][1]>max){
                    max=sum[y][z][0]-sum[y][z-i+1][1];
                }
            }
        }
    }
    printf("%d\n",max);
    return 0;
}