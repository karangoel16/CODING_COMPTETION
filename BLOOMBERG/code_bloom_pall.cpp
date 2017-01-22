#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str;
    std::cin>>str;
    vector<int>test(10,0);
    for(auto i:str)
    {
        test[i-48]++;
    }
    int max_odd=-1;
    int index=-1;
    for(int i=0;i<10;i++)
    {
        if(test[i]%2==1 && max_odd<=test[i])
        {
            index=i;
            max_odd=test[i];
        }
    }
    string t="";
    if(max_odd!=-1)
    {
        for(int i=0;i<max_odd;i++)
        {
            t+=to_string(index);
        }
    }
    int flag=0;
    for(int i=0;i<10;i++)
    {
        if(test[i]%2==0)
        {

            while(test[i])
            {
                flag=1;
                t=to_string(i)+t+to_string(i);
                test[i]-=2;
            }
        }
    }
    if(index==0 && flag==0)
    {
        t="0";
    }
    std::cout<<t<<"\n";
    return 0;
}
