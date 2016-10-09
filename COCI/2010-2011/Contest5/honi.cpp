#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int task[100000];
int pile[100000];
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    int N;
    myfile>>N;
    for(int a=0;a<N;a++){
        myfile>>task[a];
    }
    for(int a=0;a<N-1;a++){
        myfile>>pile[a];
    }
    long long int x=0LL,xx=0LL,yy=0LL,y=0LL;
    x=task[0];
    y=pile[0];
    for(int i=1;i<N;i++){
        xx=(x*(task[i]+pile[i-1])+y*(task[i]+pile[i-1]-1))%1000000007;
        yy=(pile[i]*(x+y))%1000000007;
        x=xx,y=yy;
    }
    cout<<xx<<'\n';
    return 0;
}