#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct comp{
    bool operator()(pair<int,int> &a,pair<int,int> &b)
    {
        return a.first>b.first;
    }
};
int main()
{
    int n,m;
    std::cin>>n>>m;
    vector<int> test;
    std::priority_queue<pair<int,int>,vector<pair<int,int>>> pr1;
    for(int i=0;i<n;i++)
    {
        int temp;
        std::cin>>temp;
        test.push_back(temp);
        pr1.push(make_pair(temp,i));
    }
    int res=0;
    int m_=n;
    while(!pr1.empty() && pr1.top().first>test[m])
    {
        res+=2;
        m_=pr1.top().second;
        pr1.pop();
    }
    while(!pr1.empty() && pr1.top().first==test[m])
    {
        if((pr1.top().second<=m || pr1.top().second>=m_))
        {
            res+=2;
        }
        pr1.pop();
    }
    std::cout<<res;
    return 0;
}
