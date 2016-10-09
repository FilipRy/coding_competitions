#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int n[300000];
bool used[300000];
int mins[300000];
int main(int argc, char** argv) {
    int N;
    ifstream myFile;
    myFile.open("input.txt");
    myFile>>N;
    for(int a=0;a<N;a++){
        used[a]=false;
        myFile>>n[a];
        mins[n[a]-1]=a;
    }myFile.close();
    int maxPocet=0;
    for(int i=0;i<N;i++){
        int pocet=1;
        int index=mins[i];
        if(!used[i]){
            used[i]=true;
            for(int y=i+1;y<N;y++){
                if(mins[y]<index||used[y]){break;}
                pocet++;
                index=mins[y];
                used[y]=true;
            }
        }
        if(pocet>maxPocet){maxPocet=pocet;}
    }printf("%d\n",N-maxPocet);
    return 0;
}