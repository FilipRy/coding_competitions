#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int cisla[300000];
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    int N;
    myfile>>N;
    for(int a=0;a<N;a++){
        myfile>>cisla[a];
    }myfile.close();
    unsigned long long int a=0LL;
    int min=0,max=0;
    for(int i=0;i<N-1;i++){
        min=cisla[i];
        max=cisla[i];
        for(int y=i+1;y<N;y++){
            if(cisla[y]>max){max=cisla[y];}
            if(cisla[y]<min){min=cisla[y];}
            a=a+(max-min);
        }
    }
    cout<<a<<endl;
    return 0;
}