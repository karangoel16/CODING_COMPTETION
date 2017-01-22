#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    unordered_map<char,set<int,std::greater<int>>>mul;
    unordered_map<char,bool>mul1;//this is to keep the mul open
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        std::cin>>str;
        if(str[0]=='^')
        {
            //we will write code to open here
            mul1[str[1]]=true;
            if(mul.find(str[1])==mul.end())
            {
                mul[str[1]]=std::set<int,std::greater<int>>{};
            }
        }
        else if(str[0]=='/')
        {
            //we will write to code to close here
            if(mul1.find(str[1])!= mul1.end())
                mul1[str[1]]=false;//to close the map
        }
        else
        {
            int n=stoi(str);
            for(auto it=mul.begin();it!=mul.end();it++)
            {
                if(mul1.find(it->first)!= mul1.end() && mul1[it->first])
                {
                    it->second.insert(n);//this is to insert into the open list
                }
            }
        }
    }
    for(char it='a';it<='z';it++)
    {
        if(mul.find(it)!=mul.end())
        {
            std::cout<<it<<" ";
            //std::sort(mul1[it].begin(),mul1[it].end());
            for(auto i=mul[it].begin();i!=mul[it].end();i++)
            {
                std::cout<<*i<<" ";
            }
            std::cout<<std::endl;
        }
    }
    for(auto it='A';it<='Z';it++)
    {
        if(mul.find(it)!=mul.end())
        {
            std::cout<<it<<" ";
            //std::sort(mul1[it].begin(),mul1[it].end());
            for(auto i=mul[it].begin();i!=mul[it].end();i++)
            {
                std::cout<<*i<<" ";
            }
            std::cout<<std::endl;
        }
    }
}
