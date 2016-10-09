#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int h[50][50];
int o[50][50];
bool uMax[1000000];
bool uMin[1000000];
int pole[50][50];
int sur[2500][2];
int N;
int dir[8][2];
int n=0;
int p=0;
int sta[2500][2];
int f=0;
int rozdiel=999999999;
bool found=false;
int main(int argc, char** argv) {
    dir[0][0]=-1;
    dir[0][1]=0;
    dir[1][0]=-1;
    dir[1][1]=1;
    dir[2][0]=0;
    dir[2][1]=1;
    dir[3][0]=1;
    dir[3][1]=1;
    dir[4][0]=1;
    dir[4][1]=0;
    dir[5][0]=1;
    dir[5][1]=-1;
    dir[6][0]=0;
    dir[6][1]=-1;
    dir[7][0]=-1;
    dir[7][1]=-1;
    ifstream myfile;
    myfile.open("input.txt");
    myfile>>N;
    int ll,rr;
    for(int i=0;i<N;i++){
        for(int y=0;y<N;y++){
            char c;
            myfile>>c;
            if(c=='P'||c=='K'){o[i][y]=1;}
            if(c=='P'){ll=i;rr=y;}
            if(c!='.'){
                sur[n][0]=i;
                sur[n][1]=y;
                n++;
            }
        }
    }
    int min=999999999;
    int max=0;
    int nMax=1;
    int nMin=1;
    vector<int> Max (0);
    vector<int> Min (0);
    for(int i=0;i<N;i++){
        for(int y=0;y<N;y++){
            myfile>>h[i][y];
            if(o[i][y]==1){
                if(h[i][y]>max){
                    max=h[i][y];
                }
                if(h[i][y]<min){
                    min=h[i][y];
                }

            }
        }
    }
    Max.push_back(max);
    Min.push_back(min);
    for(int i=0;i<N;i++){
        for(int y=0;y<N;y++){
            if(h[i][y]>max&&!uMax[h[i][y]-1]){
                Max.push_back(h[i][y]);
                uMax[h[i][y]-1]=true;
                nMax++;
            }
            if(h[i][y]<min&&!uMin[h[i][y]-1]){
                Min.push_back(h[i][y]);
                uMin[h[i][y]-1]=true;
                nMin++;
            }
        }
    }
    sort(Max.begin(),Max.begin()+nMax);
    p=0;
    int lg=0;
    for(int i=0;i<nMin;i++){
        bool iE=false;
        bool t=false;
        bool la=false;
        int x=nMax/2;
        for(int y=x;;){
            if((found&&Max[0]-Min[i]>rozdiel)){break;}
            min=Min[i];
            max=Max[y];
            sta[0][0]=ll;
            sta[0][1]=rr;
            int m=1;
            int l,r;
            p++;
            f=0;
            pole[ll][rr]=p;
            bool tE=false;
            for(int x=0;x<m;x++){
                l=sta[x][0];
                r=sta[x][1];
                if(o[l][r]==1){
                    f++;
                    if(f==n){
                        tE=true;
                        if(!la){
                        iE=true;}
                        found=true;
                        if(rozdiel>max-min){
                            rozdiel=max-min;
                        }
                        break;
                    }
                }
                for(int d=0;d<8;d++){
                    if(l+dir[d][0]>=0&&l+dir[d][0]<N&&r+dir[d][1]>=0&&r+dir[d][1]<N){
                        if(h[l+dir[d][0]][r+dir[d][1]]>=min&&h[l+dir[d][0]][r+dir[d][1]]<=max){
                            if(p!=pole[l+dir[d][0]][r+dir[d][1]]){
                                pole[l+dir[d][0]][r+dir[d][1]]=p;
                                sta[m][0]=l+dir[d][0];
                                sta[m][1]=r+dir[d][1];
                                m++;
                            }
                        }
                    }
                }
            }
            la=true;
            if(iE){
                if(tE&&!t){
                    lg=y;
                    y=y-15;
                    if(y<0){y=lg;t=true;}
                }
                if(!tE&&!t){
                    y=lg-1;
                    if(y<0){break;}
                    t=true;
                }
                else if(t){
                    if(!tE){break;}
                    y--;
                    if(y<0){break;}
                }
            }
            if(!iE){
                if(y==nMax-1){break;}
                if(tE&&!t){
                    lg=y;
                    t=true;
                }
                if(!tE&&!t){
                    y=y+15;
                    if(y>=nMax){y=nMax-1;}
                }
                if(t){
                    y--;
                    if(!tE||y<0){break;}
                }
            }
        }
    }cout<<rozdiel<<'\n';
    return 0;
}