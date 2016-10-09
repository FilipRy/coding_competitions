#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    int N;
    myfile>>N;
    int ship[N];
    for(int a=0;a<N;a++){
        myfile>>ship[a];
        ship[a]--;
    }
    int n=0;
    bool found=false;
    for(int i=1;i<N;i++){
        found=false;
        for(int y=1;y<i;y++){
            if(ship[i]%ship[y]==0){
                found=true;
                break;
            }
        }
        if(!found){
            n++;
        }
    }
    cout<<n<<'\n';
    return 0;
}