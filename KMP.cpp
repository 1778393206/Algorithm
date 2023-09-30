#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;


vector<int> Next(const string &p)
{
    vector<int> next;
    next.push_back(0);	//next容器的首位必定为0
    for (int i = 1, j = 0; i < p.length(); i++)
    {
        while (j > 0 && p[j] != p[i])
        { 
            j = next[j - 1];
        }
        if (p[i] == p[j])
        {
            j++; 
        }
        next.push_back(j);
    }
    return next;
}

// 求模式串p在主串s的位置
int kmp(const string &s,const string &p)
{     
    auto next=Next(p);
    for(int i = 0, j = 0; i < s.length(); i++)
    {
        while(j && s[i] != p[j])
        {
            j = next[j-1]; 
        }
        if(s[i] == p[j])
        {
            j++;   // 两者相等，继续匹配
        }
        if(j==p.length())
        {
            return i-j+1;//匹配成功，返回下标                                    
        }
    }
    return -1;// 未匹配成功，返回-1
}

vector<int> NEXT(const string &p){
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

int KMP(const string &s,const string &p){
    auto next=NEXT(p);
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