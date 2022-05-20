#include "../include/conway.h"
#include <cstdlib>
#include <algorithm>

using Coord = std::pair<unsigned int, unsigned int>; // doing this so that I get some practice
using Grid = std::array<std::array<bool, yDimension>, xDimension>;

// determine if the provided position is inside the grid
bool Conway::isValidPosition(const Coord &pos)
{
    auto [x, y] = pos;
    return !(x < 0 || x >= xDimension || y < 0 || y >= yDimension);
}

// return a vector containing coordinates of the surrounding cells that are inside the valid bounds
std::vector<Coord> Conway::getSurroundingCells(const Coord &pos)
{
    auto [x, y] = pos;
    std::vector<Coord> possiblePositions = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}, {x + 1, y - 1}, {x + 1, y + 1}, {x - 1, y + 1}, {x - 1, y - 1}};
    std::vector<Coord> validPositions;

    // std::copy_if(possiblePositions.begin(), possiblePositions.end(), std::back_inserter(validPositions), isValidPosition);
    for (const auto &i : possiblePositions)
    {
        if (isValidPosition(i))
        {
            validPositions.push_back(i); // debug copy_if later
        }
    }

    return validPositions;
}

// get the sum value of the surrounding cells
unsigned int Conway::calculateCellValue(const Coord &pos)
{
    auto positions = getSurroundingCells(pos);
    unsigned int val = 0;

    for (const auto &[x, y] : positions)
    {
        val += (currentState[x][y]);
    }

    return val;
}

// given number of surrounding cells determine if will become alive or dead
bool Conway::isCellAliveNextTurn(const unsigned int &val, const bool &isAlive)
{
    // if its alive then it will stay alive if val is 2 or 3
    // if it is not alive then it will become alive if val == 3
    return (isAlive) ? (val == 2 || val == 3) : val == 3;
}

// determines this cells state for the next position
bool Conway::aliveInNextIteration(const Coord &pos)
{
    unsigned int cellValue = calculateCellValue(pos);             // get the number of cells around the current pos that are alive
    bool isAlive = currentState[pos.first][pos.second];           // is the cell currently alive?
    bool aliveNextTurn = isCellAliveNextTurn(cellValue, isAlive); // apply rules to determine if it will be alive next turn
    return aliveNextTurn;
}

// output the current grid state to the console
void Conway::displayGrid()
{
    // should only display the 10 x 5 central grid
    // assuming that the grid is atleast 10 x 5
    for (unsigned int i = 0; i < displayX; ++i)
    {
        for (unsigned int j = 0; j < displayY; ++j)
        {
            std::cout << (currentState[i + offSet][j + offSet] ? "+" : "-") << " ";
        }
        std::cout << '\n';
    }
}

// method to wait for a user input
char Conway::waitForInput()
{
    return '_';
}

Conway::Conway(const Grid &initialState) : currentState(initialState)
{
}

Conway::Conway(const std::vector<Coord> &pattern)
{
    for (auto &i : currentState)
    {
        std::fill(i.begin(), i.end(), 0);
    }

    for (auto &[x, y] : pattern)
    {
        currentState[x][y] = true;
    }
}

// Take an initial state and produce the next iteration
Grid Conway::produceNextState(const Grid &initialState)
{
    Grid nextState;
    for (unsigned int i = 0; i < xDimension; ++i)
    {
        for (unsigned int j = 0; j < yDimension; ++j)
        {
            nextState[i][j] = aliveInNextIteration({i, j});
        }
    }
    return nextState;
}

// main run method
void Conway::run()
{
    Grid initialState = currentState;
    while (true)
    {
        bool loopCondition = true;
        char c;
        while (loopCondition)
        {
            system("cls");
            displayGrid();
            // wait for input
            currentState = produceNextState(currentState);
            c = userInput::waitForCharInput(1);
            switch (c)
            {
            case '_':
                continue;
            case 'r':
                loopCondition = false;
                break;
            case 'q':
                loopCondition = false;
                break;
            case 'p':
                system("pause");
            }
        }
        if (c == 'q')
            break;
        if (c == 'r')
        {
            currentState = initialState;
        }
    }
}