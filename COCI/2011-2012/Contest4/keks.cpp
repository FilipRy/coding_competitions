#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;
char ns[500010];
vector <char> out;
int main()
{
    int N=0,K=0;
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");
    ifile>>N>>K;
    for(int i=0;i<N;i++){
        ifile>>ns[i];
    }
    char M='0';
    int li=0;
    int k=K;
    int end=K;
    int last=-1;
    for(int i=0;i<N;i++){
        //cout<<M<<" end "<<end<<" i "<<i<<" "<<ns[i]<<" k "<<k<<endl;
        if(M<ns[i]){
            M=ns[i];
            li=i;
        }
        if(end==i){
            out.push_back(M);
            k=k-(li-last-1);
            last=li;
            end=li+k+1;
            M='0';
            i=li;
        }
    }
    for(int i=0;i<out.size();i++)
        ofile<<out[i];
    cout<<endl;
    return 0;
}
