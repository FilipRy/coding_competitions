#include <iostream>
#include <fstream>
using namespace std;
int As[1000];
int gcd(int a,int b){
    if(a%b==0){return b;}
    gcd(b,a%b);
}
int zisti_dlzku(unsigned long long int n){
    int l=0;
    while(n>0){
        n=n/10;
        l++;
    }
    return l;
}
int main()
{
    int N,M;
    ifstream ifile;
    ifile.open("input.txt");
    ifile>>N;
    for(int i=0;i<N;i++)
        ifile>>As[i];
    ifile>>M;
    unsigned long long int GCD=1;
    bool ll=false;
    int in;
    for(int i=0;i<M;i++){
        ifile>>in;
        for(int y=0;y<N;y++){
            int a=gcd(in,As[y]);
            in=in/a;
            As[y]=As[y]/a;
            if(GCD*a>=1000000000){ll=true;}
            GCD=((unsigned long long int)GCD*a)%1000000000;
        }
    }
    if(ll){
        int x=zisti_dlzku(GCD);
        if(x<9){
            while(x<9){cout<<"0";x++;}
        }
    }
    cout<<GCD<<'\n';
    return 0;
}