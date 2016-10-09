#include <iostream>
#include <fstream>
using namespace std;
int town[10][10];
int main()
{
    int R,C;
    ifstream ifile;
    ifile.open("input.txt");
    ifile>>R>>C;
    char c;
    for(int i=0;i<R;i++){
        for(int y=0;y<C;y++){
            ifile>>c;
            town[i][y]=0;
            if(c=='X'){town[i][y]=1;}
        }
    }
    bool end=false;
    for(int i=0;i<R;i++){
        for(int y=0;y<C;y++){
            if(town[i][y]==0){
                int n=0;
                if(i-1>=0){if(town[i-1][y]==0){n++;}}
                if(i+1<R){if(town[i+1][y]==0){n++;}}
                if(y-1>=0){if(town[i][y-1]==0){n++;}}
                if(y+1<C){if(town[i][y+1]==0){n++;}}
                if(n==1){
                    end=true;
                    i=R;
                    break;
                }
            }
        }
    }
    R=(int)end;
    cout<<R<<'\n';
    return 0;
}
