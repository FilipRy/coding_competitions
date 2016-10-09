#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int N;
    scanf("%d",&N);
    int n[N][2];
    int x,y,note;
    for(int a=0;a<N;a++){
        scanf("%d %d",&x,&y);
        n[a][0]=x;
        n[a][1]=y;
        note=x;
        if(x<note){note=x;}
    }
    int max=1;
    for(int a=1;a<=5;a++){
        int dlzka=1;
        for(int b=1;b<N;b++){
            if((n[b-1][0]==a||n[b-1][1]==a)&&(n[b][0]==a||n[b][1]==a)){
                dlzka++;
                if(dlzka>max){
                    max=dlzka;
                    note=a;
                }
            }
            else{dlzka=1;}
        }
    }printf("%d %d\n",max,note);
    return 0;
}