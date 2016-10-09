#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
int ch[200000];
int main(int argc, char** argv) {
    ifstream myfile("input.txt");
    int N,Q,x,index,c,max=0;
    myfile>>N>>Q;
    vector <pair<int,int> >  m;
    bool f=false,u=false;
    for(int i=0;i<Q;i++){
        myfile>>x;
        if(ch[x-1]==0){ch[x-1]=1;c=0;}
        else if(ch[x-1]==1){ch[x-1]=0;c=1;}
        x--;
        int y=-10;
        max=0;
        int s=0;
        f=false;
        u=false;     
        index=0;
        for(int k=0;k<m.size();k++){
            if(x>=m[k].first&&m[k].first+m[k].second/10>x&&m[k].second%10==0){
                if(y==-10){
                    m.resize(m.size()+1);
                    y=m.size()-1;
                }
                    int e=m[k].first+m[k].second/10;
                    if(e-x>1){
                        m[y].first=x;
                        m[y].second=(e-x)*10;
                        y=-10;
                    }
                    e=x-1-m[k].first;
                    if(e>0){
                        m[k].second=x*10;
                    }
                    else{
                        m[k].second++;
                    }
                    u=true;f=true;
                    break;
            }
            if(m[k].first+m[k].second/10<=N&&m[k].first+m[k].second/10==x&&m[k].second%10==0&&ch[m[k].first+m[k].second/10-1]==c){
                if(f){
                    m[k].second=m[k].second/10+m[index].second/10;
                    m[k].second=m[k].second*10;
                    m[index].second++;
                    u=true;
                }
                if(!f){
                    m[k].second=m[k].second+10;
                    index=k;
                    s=1;
                }
                f=true;
            }
            if(m[k].first-1>=0&&m[k].first-1==x&&m[k].second%10==0&&ch[m[k].first-1]==c){
                if(f){
                    m[index].second=m[index].second/10+m[k].second/10;
                    m[index].second=m[index].second*10;
                    m[k].second++;
                    u=true;
                }
                if(!f){
                    m[k].first--;
                    m[k].second=m[k].second+10;
                    index=k;
                    s=-1;
                }
                f=true;
            }
            if(m[k].second%10==1){
                y=k;
            }
        }
        if(!u){
            if(s==1){
                if(m[index].first+m[index].second/10<N){
                    if(ch[m[index].first+m[index].second/10]==c){
                        m[index].second=m[index].second+10;
                    }
                }
            }
            if(s==-1){
                if(m[index].first-1>=0){
                    if(ch[m[index].first-1]==c){
                        m[index].first--;
                        m[index].second=m[index].second+10;
                    }
                }
            }
        }
        if(!f){
            if(y!=-10){
                m[y].first=x;
                m[y].second=10;
            }
            if(y==-10){
                m.resize(m.size()+1);
                m[m.size()-1].first=x;
                m[m.size()-1].second=10;
                y=m.size()-1;
            }
                if(m[y].first-1>=0){
                    if(ch[m[y].first-1]==c){
                        m[y].first--;
                        m[y].second=m[y].second+10;
                    }
                }
                if(m[y].first+m[y].second/10<N){
                    if(ch[m[y].first+m[y].second/10]==c){
                        m[y].second=m[y].second+10;
                    }
                }
        }
        for(int a=0;a<m.size();a++){
            cout<<"a "<<a<<" first "<<m[a].first<<" second "<<m[a].second<<'\n';
            if(m[a].second%10==0&&m[a].second/10>max){
                max=m[a].second/10;
            }
        }
        cout<<max<<'\n';
    }
    return 0;
}