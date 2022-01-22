#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

enum class State {kEmpty, kObstacle,kClosed,kPath,kStart,kFinish};
const int delta[4][2] {{-1,0},{0,-1},{1,0},{0,1}};
std::vector<State> ParseLine(std::string line)
{
    std::istringstream ist(line);
    int n;
    char c;
    std::vector<State> row;
    while(ist>>n>>c==',')
    {
        switch(n)
        {
            case 0: row.push_back(State::kEmpty);
            break;
            case 1: row.push_back(State::kObstacle);
            break;
            case 2: row.push_back(State::kClosed);
            break;
            case 3: row.push_back(State::kPath);
            break;
            case 4: row.push_back(State::kStart);
            break;
            case 5: row.push_back(State::kFinish);
            break;
        }
    }
    return row;
}
std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
    std::ifstream myFile(path);
    std::vector <std::vector<State>> grid{};
    if(myFile)
    {
        std::string str_;
        while(getline(myFile,str_))
        {
            std::vector<State> row = ParseLine(str_);
            grid.push_back(row);
        }
    }
    return grid;
}
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2])
{
    std::vector<std::vector<int>> open{};
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x,y,goal[0],goal[1]);
    AddToOpen(x,y,g,h,open,grid);
    while (open.size()>0)
    {
        Cellsort(&open);
        auto current = open.back();
        open.
    }

}
bool Compare(const std::vector<int> a, const std::vector<int> b)
{
    int f1 = a[2] + a[3]; //f1=g1+h1;
    int f2 = b[2] + b[3]; //f2=g2+h2;
    return f1>f2;
}
void Cellsort(std::vector<std::vector<int>> *o)
{
    std::sort( o->begin(), o->end(), Compare);
}
std::string cellString(State state)
{
    switch(state)
    {
        case State::kObstacle : return"💩";
        break;
        default: return"0 ";
    }
}
void PrintBoard(std::vector<std::vector<State>> board)
{
    for (int i=0; i< board.size(); i++)
    {
        for(int j=0; j<board[i].size();j++)
        {
            std::cout<<cellString(board[i][j]);
        }
        std::cout<<"\n";
    }
}
int Heuristic(int x, int y, int goal_x, int goal_y)
{
    return abs (goal_x-x) + abs(goal_y-y);
}
void AddToOpen(int x, 
               int y, 
               int g, 
               int h, 
               std::vector<std::vector<int>> &openlist, 
               std::vector<std::vector<State>> &grid)
{
    openlist.push_back(std::vector<int>{x,y,g,h});
    grid[x][y] = State::kClosed;
}
int main()
{
    int init[2] = {0,0};
    int goal[2] = {3,7};
    auto board = ReadBoardFile("board.board");
    std::cout<<"=============================="<<std::endl;
    PrintBoard(board);
    std::cout<<"=============================="<<std::endl;
    std::cout<<"A * SEARCHING ALGORITHM ..... "<<std::endl;
    std::cout<<"=============================="<<std::endl;
    auto solution = Search(board, init, goal);
    PrintBoard(solution);
    std::cout<<"=============================="<<std::endl;
    return 0;
}