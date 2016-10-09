#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
    int N=0;
    scanf("%d",&N);
    int t=0,y=0;
    vector<int> f;
    vector<int> s;
    int cisla[N];
    int pocet=0;
    for(int a=0;a<N;a++){scanf("%d",&cisla[a]);}
    for(int i=0;i<N;i++){
        if(cisla[i]!=i+1){
            int b=i+1;
            y=cisla[i];
            s.push_back(i+1);
            while(y!=b){
                t=y;
                f.push_back(y);
                y=cisla[y-1];
                cisla[t-1]=t;
            }cisla[i]=i+1;
            f.push_back(i+1);
        }
    }
    if(s.size()>1){pocet=2;}
    else{pocet=1;}
    printf("%d\n",pocet);
    printf("%d: ",f.size());
    for(int a=0;a<f.size();a++){
        printf("%d ",f[a]);
    }printf("\n");
    if(pocet==2){
        printf("%d: ",s.size());
    for(int a=s.size()-1;a>=0;a--){
        printf("%d ",s[a]);
    }printf("\n");}
    return 0;
}