#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
int score[5];
int task[8];
int stask[8];
int main()
{
    ifstream ifile;
    ifile.open("input.txt");
    for(int i=0;i<8;i++){ifile>>task[i];stask[i]=task[i];}
    sort(stask,stask+8);
    int iit=0;
    int sc=0;
    for(int i=7;i>=3;i--){
        sc=sc+stask[i];
        for(int y=0;y<8;y++){
            if(stask[i]==task[y]){
                score[iit]=y+1;
                iit++;
            }
        }
    }
    sort(score,score+iit);
    cout<<sc<<'\n';
    for(int i=0;i<5;i++){
        if(i>0){cout<<" ";}
        cout<<score[i];
    }cout<<'\n';
    return 0;
}
