#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
unsigned long long int cisla[100000];
int main(int argc, char** argv) {
    int N=0,M=0;
    ifstream myfile;
    myfile.open ("input.txt");
    myfile>>M>>N;
    unsigned long long int sucet=0LL;
    for(int a=0;a<N;a++){
        cisla[a]=0LL;
        myfile>>cisla[a];
        sucet=sucet+cisla[a];
    }
    sort(cisla,cisla+N);
    myfile.close();
    unsigned long long int m=M;
    unsigned long long int vys=0LL;
    for(int i=0;i<N;i++){
        unsigned long long int n=cisla[i]*(N-i);
        if(n>sucet-m){
            vys=vys+(((sucet-m)/(N-i))*((sucet-m)/(N-i)));
            m=m-(cisla[i]-(sucet-m)/(N-i));
        }
        else{vys=vys+cisla[i]*cisla[i];}
        sucet=sucet-cisla[i];
    }
    cout<<vys<<'\n';
    return 0;
}