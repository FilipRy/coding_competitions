#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(int argc, char** argv) {
    FILE * pFile;
    pFile=fopen("input.txt","rw");
    int R,B;
    fscanf(pFile,"%d %d",&R,&B);
    float l=((R+4)+(sqrt(((R+4)*(R+4))-(4*(2*(2*R+2*B))))))/4;
    float w=((R+4)-(sqrt(((R+4)*(R+4))-(4*(2*(2*R+2*B))))))/4;
    if(l>w){
        cout<<l<<" "<<w<<'\n';
    }
    else{
        cout<<w<<" "<<l<<'\n';
    }
    return 0;
}