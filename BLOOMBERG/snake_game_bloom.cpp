#include <vector>
#include <iostream>
#include <queue>
using namespace std;
//test here is the game board
vector<int> x_next={0,-1,1,0};
vector<int> y_next={1,0,0,-1};
//here route gaves snake col and next row which can be taken
int game(vector<int> route,int step,vector<vector<int>> &test,deque<pair<int,int>> &de, int row,int col)
{
    if(step+1>=(route.size()))
    {
        return -1;//this is done to know that snake has not been eaten anywhere
    }
    step++;//this is to add the step
    int next_col=col+x_next[route[step]];
    int next_row=row+y_next[route[step]];
//    std::cout<<step<<" "<<next_col<<" "<<next_row<<" "<<col<<" "<<row<<"\n";
//    std::cout<<"matrix"<<test[next_row][next_col]<<"\n";
    if(test[next_row][next_col]==-1)
    {
        return step+1;//this is to tell that the snake looses at this step
    }

    if(test[next_row][next_col]==1)//we will write code for the food here
    {
//        std::cout<<"*";
        de.push_back(make_pair(next_row,next_col));
        test[next_row][next_col]=-1;//this is to move snake one step ahead
    }
    if(test[next_row][next_col]==0)//we will write code for the normal here , i.e. move out the last item
    {
        de.push_back(make_pair(next_row,next_col));
        int temp_row=de[0].first;
        int temp_col=de[0].second;
        test[temp_row][temp_col]=0;//this is to remove from the map the snake
        test[next_row][next_col]=-1;//this is to move the snake to the next row and column
        de.pop_front();//this is to pop from front
    }
    return game(route,step,test,de,next_row,next_col);//this to move the snake in the next row and column
}
int main()
{
    int row,col;
    std::cin>>row>>col;
    deque<pair<int,int>>de;//this is to keep the value of the snake
    vector<vector<int>>test(row,vector<int>(col,0));//this is given to find the number of rows and col
    int food;
    std::cin>>food;
    for(int i=0;i<food;i++)
    {
        int n,m;
        std::cin>>n>>m;
        test[n][m]=1;//1 stands for food
    }
    int steps;
    std::cin>>steps;
    vector<int> route;
    for(int i=0;i<steps;i++)
    {
        char t;
        int j;
        std::cin>>t;
        switch(t)//we will enter according to the arrays
        {
            case 'U':j=3;
                break;
            case 'D':j=0;
                break;
            case 'R':j=2;
                break;
            case 'L':j=1;
                break;
        }
        route.push_back(j);//this is done to push back steps
    }
//    for(auto i:route)
//    {
//        std::cout<<i<<" "<<x_next[i]<<" "<<y_next[i]<<"\n";
//    }
    test[0][0]=-1;//this is for snake at initial position
    de.push_back(make_pair(0,0));//to push into deque so that it can be used later
    std::cout<<game(route,-1,test,de,0,0);
    return 0;
}
