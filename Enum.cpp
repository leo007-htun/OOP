#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
enum class State {kEmpty, kObstacle};
std::vector<State> ParseLine(std::string line)
{
    std::istringstream ist(line);
    int n;
    char c;
    std::vector<State> row;
    while(ist>>n>>c)
    {
        switch(n)
        {
            case 0: row.push_back(State::kEmpty);
            break;
            case 1: row.push_back(State::kObstacle);
            break;
        }
    }
    return row;
}
std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
    std::ifstream myFile(path);
    std::string str_;
    std::vector<std::vector<State>> grid;
    if(myFile)
    {
        while(getline(myFile,str_))
        {
            std::vector<State> test_vector;
            test_vector=ParseLine(str_);
            grid.push_back(test_vector);
        }
    }
    else
    {
        std::cout<<"ERROR!"<<std::endl;
    }
    return grid;
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
int main()
{
    auto board = ReadBoardFile("board.board");
    PrintBoard(board);
    return 0;
}