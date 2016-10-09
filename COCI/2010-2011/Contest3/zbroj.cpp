#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char** argv) {
    string N,M;
    cin>>N>>M;
    int m=1;
    int y=0;
    int n=0;
    for(int i=N.length()-1;i>=0;i--){
        if(N[i]=='6'){N[i]='5';}
        n=(int)N[i]-48;
        y=y+n*m;
        m=m*10;
    }m=1;
    int y2=0;
    for(int i=M.length()-1;i>=0;i--){
        if(M[i]=='6'){M[i]='5';}
        n=(int)M[i]-48;
        y2=y2+n*m;
        m=m*10;
    }printf("%d ",y+y2);
    
    y=0;
    y2=0;
    m=1;
    for(int i=N.length()-1;i>=0;i--){
        if(N[i]=='5'){N[i]='6';}
        n=(int)N[i]-48;
        y=y+n*m;
        m=m*10;
    }m=1;
    for(int i=M.length()-1;i>=0;i--){
        if(M[i]=='5'){M[i]='6';}
        n=(int)M[i]-48;
        y=y+n*m;
        m=m*10;
    }printf("%d\n",y+y2);
    return 0;
}