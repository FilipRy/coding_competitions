#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int f[6][500000];
int si[6];
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    int N,P,s,t,p=0;
    myfile>>N>>P;
    for(int a=0;a<N;a++){
        myfile>>s>>t;
        int i=si[s-1];
        bool x=false;
        if(f[s-1][i]==t){x=true;}
        while(f[s-1][i]>=t){
            p++;
            if(f[s-1][i]==t){
                p--;
                x=true;
                break;
            }
            i--;
            if(i<0){break;}
        }
        if(!x){
            f[s-1][i+1]=t;
            si[s-1]=i+1;
            p++;
        }
        if(x){si[s-1]=i;}
        
    }
    cout<<p<<'\n';
    return 0;
}