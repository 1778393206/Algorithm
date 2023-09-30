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
int main()
{
    string a="dfdgsdgdfhsasdsa";
    auto next=Next(a);
    for(auto v:next){
        printf("%2d ",v);
    }
    cout<<endl;
}