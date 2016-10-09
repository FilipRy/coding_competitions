#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
char znaky[1000][1000];
int zhodnost[1000][1000];
int main(int argc, char** argv) {
    int R,C;
    ifstream myfile ("input.txt");
    vector <vector<int> > v(25999);
    vector <vector<int> > b(26);
    int tmp=0;
    myfile>>R>>C;
    for(int a=0;a<R;a++){
        if(a<26){b[a].resize(0);}
        for(int b=0;b<C;b++){
            myfile>>znaky[a][b];
            zhodnost[a][b]=-1;
        }
    }
    int del=R-1;
    bool end=false;
    bool f=false;
    for(int y=R-1;y>=0;y--){
        if((R-(y+1))%2==0){tmp=2;}
        else{tmp=1;}
        end=true;
        for(int x=0;x<C;x++){
            if(y==R-1){
                if(b[znaky[y][x]-97].size()>1){
                    zhodnost[y][x]=b[znaky[y][x]-97][1];
                }
                if(b[znaky[y][x]-97].size()==0){
                    b[znaky[y][x]-97].push_back(x);
                }
                else if(b[znaky[y][x]-97].size()==1){
                    zhodnost[y][b[znaky[y][x]-97][0]]=tmp;
                    zhodnost[y][x]=tmp;
                    b[znaky[y][x]-97].push_back(tmp);
                    tmp=tmp+2;
                }
            }
            if(y<R-1){
                if(zhodnost[y+1][x]>=0){
                    int index=(znaky[y][x]-97)*1000+zhodnost[y+1][x];
                    if(v[index].size()!=2*(R-y-1)){v[index].resize(2*(R-y-1));}
                    if(v[index][(2*(R-y-1))-2]!=0&&v[index][(2*(R-y-1))-1]!=0){
                        zhodnost[y][x]=v[index][(2*(R-y-1))-1];
                    }
                    if(v[index][(2*(R-y-1))-2]==0&&v[index][(2*(R-y-1))-1]==0){
                        v[index][(2*(R-y-1))-2]=x+1;
                    }
                    else if(v[index][(2*(R-y-1))-2]!=0&&v[index][(2*(R-y-1))-1]==0){
                        end=false;
                        zhodnost[y][v[index][(2*(R-y-1))-2]-1]=tmp;
                        zhodnost[y][x]=tmp;
                        v[index][(2*(R-y-1))-1]=tmp;
                        tmp=tmp+2;
                    }
                }
            }
        }
        if(end&&y<R-1){
            del=y;
            break;
        }
    }
    printf("%d\n",del);
    return 0;
}