#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int N,sol=0;
    bool f=false;
    cin>>N;
    for(int i=0;i<=N;){
        if((N-i)%3==0){
            f=true;
            sol=i;
        }
        i=i+5;
    }
    cout<<(N-sol)/3+sol/5<<'\n';
    return 0;
}