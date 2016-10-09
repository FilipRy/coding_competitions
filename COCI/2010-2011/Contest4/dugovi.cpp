#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
int A[300000];
int suma[300000];
int nOwers[300000];
int value[300000];
bool used[300000];
using namespace std;
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    int N;
    myfile>>N;
    vector <int> cycle;
    for(int a=0;a<N;a++){
        nOwers[a]=0;
        used[a]=false;
        value[a]=0;
    }
    for(int a=0;a<N;a++){
        myfile>>A[a]>>suma[a];
        nOwers[A[a]-1]++;
    }
    myfile.close();
    int sum=0;
    bool end=false;
    while(!end){
        end=true;
        for(int i=0;i<N;i++){
            if(nOwers[i]==0){
                int kon=0;
                kon=suma[i]-value[i];
                if(kon<0){kon=0;}
                sum=sum+kon;
                value[A[i]-1]=value[A[i]-1]+suma[i];
                nOwers[A[i]-1]--;
                nOwers[i]=-1;
                end=false;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(nOwers[i]==1&&!used[i]){
            cycle.resize(0);
            int n=A[i]-1;
            int min=suma[i]-value[i];
            int s=i;
            cycle.push_back(i);
            used[i]=true;
            used[n]=true;
            while(n!=i){
                if(min>suma[n]-value[n]){
                    min=suma[n]-value[n];
                    s=n;
                }
                cycle.push_back(n);
                n=A[n]-1;
                used[n]=true;
            }
            n=A[s]-1;
            int kon=suma[s]-value[s];
            if(kon<0){kon=0;}
            sum=sum+kon;
            value[A[s]-1]=value[A[s]-1]+suma[s];
            while(s!=n){
                kon=suma[n]-value[n];
                value[A[n]-1]=value[A[n]-1]+suma[n];
                if(kon<0){kon=0;}
                sum=sum+kon;
                n=A[n]-1;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}