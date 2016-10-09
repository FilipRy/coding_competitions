#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int cislo[100000];
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    ofstream ofile;
    ofile.open("output.txt");
    int N,S;ofile<<"1 ";
    myfile>>N>>S;
    bool stop=false;
    int x=0;
    for(int a=0;a<N;a++){
        myfile>>cislo[a];
    }myfile.close();
    int nSum1=0,nSum2=0,nk=0,Sum1=0,Sum2=0,x1=0,a1=0,a2=0;
    bool end1=false,end2=false,stop1=false,b=false;
    for(int n=0;n<N-1;){
        int k=nk+1;
        int k2=k-1;
        int sum1=Sum1,sum2=Sum2;
        nk=0,Sum1=0,Sum2=0,nSum1=0,nSum2=0;
        stop=false;
        end1=false;
        end2=false;
        b=true;
        while(true){
            if(b){
                if(n+2*k>N){
                    a1=2*(k-1);
                    end1=true;
                }
                if(n+1+2*k2>N){
                    a2=2*(k2-1);
                    end2=true;
                }
            }b=false;
            if(!end1){
                sum1=sum1+cislo[n+k-1];
                sum2=sum2-cislo[n+k-1]+cislo[n+2*k-1]+cislo[n+2*k-2];
            }
            if(!end2){
                if(k2>0){
                if(end1){
                    nSum1=nSum1+cislo[n+1+k2-1];
                    nSum2=nSum2-cislo[n+1+k2-1]+cislo[n+1+2*k2-1]+cislo[n+1+2*k2-2];
                    }
                    else{
                        nSum1=sum1-cislo[n];
                        nSum2=sum2-cislo[n+2*k-1];
                    }
                    if(nSum1<=S&&nSum2<=S){
                        stop1=false;
                        if(k2>1){
                            nk=k2-1;
                            Sum1=nSum1-cislo[n+1];
                            Sum2=nSum2-cislo[n+2*k2];
                        }
                    }
                }
                if(nSum1>S){
                    if(stop1){a2=2*(x1-1);}
                    else{a2=2*(k2-1);}
                    end2=true;
                }
                else if(nSum2>S&&!stop1){
                    stop1=true;
                    x1=k2;
                }
                k2++;
                if(n+1+2*k2>N&&!end2){
                    if(stop1){a2=2*(x1-1);}
                    else{a2=2*(k2-1);}
                    end2=true;
                }
            }
            if(!end1){
                if(sum1<=S&&sum2<=S){stop=false;}
                if(sum1>S&&!end1){
                    if(stop){a1=2*(x-1);}
                    else{a1=2*(k-1);}
                    end1=true;
                }
                else if(sum2>S&&!stop){
                    stop=true;
                    x=k;
                }
                k++;
                if(n+2*k>N&&!end1){
                    if(stop){a1=2*(x-1);}
                    else{a1=2*(k-1);}
                    end1=true;
                }
            }
            if(end1&&end2){
                ofile<<a1<<'\n'<<a2<<'\n';
                break;
            }
        }
        n=n+2;
    }
    if(N%2==1)
        ofile<<"0\n";
    ofile.close();
    return 0;
}