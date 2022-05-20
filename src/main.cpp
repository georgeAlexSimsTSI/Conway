#include "../include/conway.h"

// https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
// {4,4},{5,4},{6,4}, // blinker
// {4,4},{4,5},{4,6},{5,5},{5,6},{5,7}, // toad
// {4,4},{4,5},{5,4},{5,5},{6,6},{6,7},{7,6},{7,7}, // blinker
// {5,4},{5,5},{5,6},{4,6},{3,5}, // glider

int main()
{
    std::vector<std::pair<unsigned int, unsigned int>> pattern = {
        {5, 4},
        {5, 5},
        {5, 6},
        {4, 6},
        {3, 5},
    };

    std::array<std::array<bool, yDimension>, xDimension> initialPattern
    {
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0},
        std::array<bool, yDimension>{0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0},
        std::array<bool, yDimension>{0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0},
        std::array<bool, yDimension>{0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0},
        std::array<bool, yDimension>{0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        std::array<bool, yDimension>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},        
    };

    Conway gameOfLife = Conway(initialPattern);
    gameOfLife.run();
}