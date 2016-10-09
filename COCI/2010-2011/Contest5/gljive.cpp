#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    int k,sucet=0;
    bool end=false;
    for(int i=0;i<10;i++){
        myfile>>k;
        if(sucet+k>100&&!end){
            if((sucet+k-100)<=100-sucet){
                sucet=sucet+k;
            }
            end=true;
        }
        else if(!end){
            sucet=sucet+k;
        }
    }
    cout<<sucet<<'\n';
    return 0;
}