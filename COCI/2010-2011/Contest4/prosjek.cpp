#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

int gcd(unsigned int a,unsigned int b){
    if(a%b==0){
        return b;
    }
    gcd(b,a%b);
}
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    string in;
    unsigned long long int m=1;
    unsigned long long int v=0;
    myfile>>in;
    for(int a=in.length()-1;a>=0;a--){
        if(in[a]!='.'){
            v=v+(in[a]-48)*m;
            m=m*10;
        }
    }
    m=m/10;
    int max=gcd(v,m);
    v=v/max;
    m=m/max;
    int m1=(int)in[0]-48;
    unsigned long long int b=v-m1*m;
    unsigned long long int a=m-b;
    for(int i=0;i<5;i++){
        int n=0;
        if(i+1==m1){
            n=a;
        }
        if(i==m1){
            n=b;
        }
        cout<<n;
        if(i<4){
            cout<<" ";
        }
        if(i==4){
            cout<<'\n';
        }
    }
    myfile.close();
    return 0;
}