#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <stdio.h>
#include <fstream>
using namespace std;
typedef pair <long long,long long>xx;
xx pole[300000];
int main(int argc, char** argv) {
    long long N,M;
    ifstream myfile ("input.txt");
    myfile >>N>>M;
    int x,y,pocet=0;
    for(int a=0;a<N;a++){
        myfile>>x>>y;
        if(x>y){
        pole[pocet]=make_pair(y,x);
        pocet++;}
    }
    sort(pole,pole+pocet);
    bool nI=true;
    int interval[2];
    x=0;
    long long last=0;
    long long skore=0;
    for(int i=0;i<pocet;i++){
        if(pole[i].first==x){
            if(pole[i].second>interval[1]){interval[1]=pole[i].second;}
        }
        if(x!=pole[i].first&&i!=0){
            y=pole[i].first;
            if(interval[0]<=y&&y<=interval[1]){
                if(pole[i].second>interval[1]){
                    interval[1]=pole[i].second;
                }
            }
            else{nI=true;}
        }
        if(nI){
            if(i!=0){
                skore=skore+fabs(last-interval[1])+fabs(interval[1]-interval[0]);
                last=interval[0];
            }
            interval[0]=pole[i].first;
            interval[1]=pole[i].second;
        }
        x=pole[i].first;
        nI=false;
    }
    skore=skore+fabs(last-interval[1])+fabs(interval[1]-interval[0])+fabs(interval[0]-M);
    cout << skore<< endl;
    return 0;
}