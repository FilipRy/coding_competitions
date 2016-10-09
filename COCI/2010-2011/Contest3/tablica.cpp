#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char** argv) {
    float val[4];
    cin>>val[0]>>val[1];
    cin>>val[2]>>val[3];
    float tmp=0;
    float max=-100000;
    int r=0;
    for(int a=0;a<4;a++){
        float b=val[0]/val[2]+val[1]/val[3];
        if(b>max){max=b;r=a;}
        tmp=val[3];
        val[3]=val[1];
        val[1]=val[0];
        val[0]=val[2];
        val[2]=tmp;
    }cout<<r<<'\n';
    return 0;
}