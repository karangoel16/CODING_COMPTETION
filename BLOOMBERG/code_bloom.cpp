#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    std::cin>>n;
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        int test;
        std::cin>>test;
        temp.push_back(test);
    }
    int res=temp[n-1];
    int min_=temp[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(min_>=temp[i])
        {
            min_=temp[i];
            res+=temp[i];
        }
        else
        {
            min_=temp[i];
            if(res<temp[i])
                res=temp[i];
        }
    }
    std::cout<<res;
    return 0;
}
