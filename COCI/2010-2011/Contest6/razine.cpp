#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int n[100];
int main(int argc, char** argv) {
    int N;
    ifstream myfile("input.txt");
    myfile>>N;
    bool inc=false;
    for(int a=0;a<N;a++){
        myfile>>n[a];
    }
    int b=0,e=0,sum=0,min;
    while(b<N){
        inc=false;
        min=20000;
        for(int i=b;i<N;i++){
            if(i>0&&n[i-1]>=n[i]){inc=true;}
            if(n[i]-i<min){
                min=n[i]-i;
                e=i;
            }
        }
        for(int i=b;i<e&&inc;i++){
            sum=sum+(n[i]-(i+min));
        }
        if(!inc){
            break;
        }
        b=e+1;
    }
    printf("%d\n",sum);
    return 0;
}