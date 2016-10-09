#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    FILE* myfile=fopen("input.txt","rw");
    int N;
    fscanf(myfile,"%d",&N);
    int As=0;
    int Bs=0;
    int At=0;
    int Bt=0;
    int Bw=0;
    int Aw=0;
    int team=0;
    int h,m;
    for(int i=0;i<N;i++){
        fscanf(myfile,"%d %d:%d",&team,&h,&m);
        if(As==Bs){
            At=h*60+m;
            Bt=h*60+m;
        }
        if(team==1){
            As++;
            if(As==Bs){Bw=Bw+((h*60+m)-Bt);}
            if(As>Bs){
                Aw=Aw+((h*60+m)-At);
                At=h*60+m;
            }
        }
        if(team==2){
            Bs++;
            if(As==Bs){Aw=Aw+((h*60+m)-At);}
            if(Bs>As){
                Bw=Bw+((h*60+m)-Bt);
                Bt=h*60+m;
            }
        }
    }
    if(As>Bs){Aw=Aw+((48*60)-At);}
    if(Bs>As){Bw=Bw+((48*60)-Bt);}
    if(Aw/60<10){cout<<"0";}
    cout<<Aw/60<<":";
    if(Aw%60<10){cout<<"0";}
    cout<<Aw%60<<'\n';
    if(Bw/60<10){cout<<"0";}
    cout<<Bw/60<<":";
    if(Bw%60<10){cout<<"0";}
    cout<<Bw%60<<'\n';
    return 0;
}