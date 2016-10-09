#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int spin[100];
char an[100];
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    char wf[25]={0};
    int N,K;
    bool f=false;
    myfile>>N>>K;
    for(int a=0;a<K;a++){
        myfile>>spin[a]>>an[a];
    }
    int a=0;
    wf[a]=an[K-1];
    for(int i=K-1;i>0;i--){
        a=(a+spin[i])%N;
        if(wf[a]!=0&&wf[a]!=an[i-1]){
            cout<<"!\n";
            f=true;
            break;
        }
        wf[a]=an[i-1];
    }
    if(!f){
        for(int a=0;a<N;a++){
            if(wf[a]==0){cout<<'?';}
            else{cout<<wf[a];}
        }cout<<'\n';
    }
    return 0;
}