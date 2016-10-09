#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) {
    int N,M,K;
    ifstream myfile("input.txt");
    myfile>>N>>M>>K;
    float stud[N];
    for(int a=0;a<N;a++){stud[a]=0.0;}
    for(int i=0;i<M;i++){
        for(int y=0;y<N;y++){
            float s;
            int i;
            myfile>>i>>s;
            if(stud[i-1]<s){stud[i-1]=s;}
        }
    }
    sort(stud,stud+N);
    float i=0;
    for(int x=N-1;x>N-K-1;x--){
        i=i+stud[x];
    }cout<<i<<'\n';
    return 0;
}