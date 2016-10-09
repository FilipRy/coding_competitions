#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int hill[1000];
int main(int argc, char** argv) {
    int N;
    bool inc=false;
    ifstream myfile("input.txt");
    myfile>>N;
    for(int a=0;a<N;a++){
        myfile>>hill[a];
    }
    int s,max=0,n=0;
    for(int i=0;i<N;i++){
        inc=false;
        for(int j=i+1;j<N;j++){
            if(hill[j-1]<hill[j]){
                if(!inc){
                    s=hill[j-1];
                }
                inc=true;
            }
            if(hill[j-1]>=hill[j]){
                if(inc&&max<(hill[j-1]-s)){
                    max=hill[j-1]-s;
                }
                inc=false;
            }
            if(j==N-1&&inc&&max<(hill[j]-s)){
                max=hill[j]-s;
            }
        }
    }
    printf("%d\n",max);
    return 0;
}