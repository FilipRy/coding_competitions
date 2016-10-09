#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
string ret[100];
bool used[26];
bool pUsed[26];
char znaky[26];
bool used2[26];
int par[100][2];
int main(int argc, char** argv) {
    int N,n=0;
    ifstream myfile("input.txt");
    myfile>>N;
    for(int a=0;a<26;a++){
        used[a]=false;
        pUsed[a]=false;
    }
    for(int i=0;i<N;i++){
        myfile>>ret[i];
        for(int ii=0;ii<ret[i].length();ii++){
            if(!used[ret[i][ii]-97]){n++;}
            used[ret[i][ii]-97]=true;
        }
    }
    int x=0;
    bool found=false,c=true,o=false;
    for(int i=0;i<N-1;i++){
        int ii=0;
        while(ret[i][ii]==ret[i+1][ii]){ii++;
        if(ii==ret[i].length()||ii==ret[i+1].length()){ii=-1;break;}}
        if(ii>=0){
        par[x][0]=ret[i][ii];
        par[x][1]=ret[i+1][ii];
        x++;}
    }
    for(int i=0;i<26;i++){
        pUsed[i]=false;
    }
    int xx=0;int ii=0;
    bool end=false;
    while(!end){
        for(int i=0;i<26;i++){
            used2[i]=false;
        }
        for(int i=0;i<x;i++){
            if(!pUsed[par[i][1]-97]){
                used2[par[i][0]-97]=true;
            }
        }
        found=false;
        xx=0;
        for(int i=0;i<26;i++){
            if(used[i]!=used2[i]&&!pUsed[i]){
                found=true;
                znaky[ii]=(char)(i+97);
                ii++;
                xx++;
                if(xx>1){
                    c=false;
                    o=true;  
                }
                if(ii==n){end=true;break;}
            }
            if(i==25&&!found){
                c=false;
                cout<<"!\n";
                o=false;
                end=true;
                break;
            }
            if(i==25){
                pUsed[znaky[ii-1]-97]=true;
            }
        }
        
    }
    if(o){
        cout<<"?\n";
        c=false;
    }
    if(c){
        ii--;
        while(ii>=0){
            cout<<znaky[ii];
            ii--;
        }cout<<'\n';
    }
    return 0;
}