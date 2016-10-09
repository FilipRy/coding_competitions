#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <vector>
using namespace std;
vector <vector<int> >z(26);
bool used[100000];
char mirko[100000];
char slavko[100000];
char str[100000];
int main(int argc, char** argv) {
    int N;
    ifstream myfile;
    myfile.open ("input.txt");
    myfile>>N;
    for(int a=0;a<N;a++){
        char c;
        myfile>>c;
        z[c-97].push_back(a);
        str[a]=c;
        used[a]=false;
    }myfile.close();
    int m=0,s=0;
    int l=N-1;
    while(m+s<N){
        while(used[l]){l--;}
        used[l]=true;
        mirko[m]=str[l];
        m++;
        z[str[l]-97].pop_back();
        for(int x=0;x<26;x++){
            if(z[x].size()>0){
                slavko[s]=str[z[x][z[x].size()-1]];
                used[z[x][z[x].size()-1]]=true;
                s++;
                z[x].pop_back();
                break;
            }
        }
    }
    bool win=false;
    m=0;
    while(m<s){
        if(slavko[m]<mirko[m]){
            printf("DA\n");
            win=true;
            break;
        }
        if(mirko[m]<slavko[m]){
            printf("NE\n");
            win=true;
            break;
        }
        m++;
    }m=0;
    if(!win){printf("NE\n");}
    while(m<s){
        printf("%c",slavko[m]);m++;
    }printf("\n");
    return 0;
}