#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

vector<int> Next(const string &p){
    vector<int> next(p.length(),0);
    next[0]=-1;
    int i=0,j=-1;
    while(i<int(p.length())-1){
        if(j==-1 || p[i]==p[j]){
            i++;
            j++;
            if(p[i]!=p[j])
                next[i]=j;
            else
                next[i]=next[j];
        }
        else{
            j=next[j];
        }
    }
    return next;
}
// 求模式串p在主串s的位置
int Kmp(const string &s,const string &p){
    auto next=Next(p);
    int i=-1,j=-1;
    while(i<(int)s.length() && j<(int)p.length()){
        if(j==-1 || s[i]==p[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j>=(int)p.length())
        return i-p.length();
    else
        return -1;

}


int main()
{
    string a="dfdgsdgdfhsasdsa";
          // -1,0,-1,1,0,-1,1,-1,0,2,0,0,0,-1,1,0
    auto next=Next(a);
    for(auto v:next){
        printf("%2d ",v);
    }
    cout<<endl;
}