#include "../include/conway.h"
#include <cstdlib>
#include <algorithm>

using Coord = std::pair<unsigned int, unsigned int>; // doing this so that I get some practice
using Grid = std::vector<std::vector<bool>>;

// return a vector containing coordinates of the surrounding cells that are inside the valid bounds
std::vector<Coord> Conway::getSurroundingCells(const Coord &pos) const noexcept
{
    auto [x, y] = pos;
    std::vector<Coord> possiblePositions = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}, {x + 1, y - 1}, {x + 1, y + 1}, {x - 1, y + 1}, {x - 1, y - 1}};
    std::vector<Coord> validPositions;
    validPositions.reserve(possiblePositions.size());

    auto isValid = [this](const Coord &pos)
    {    auto [x, y] = pos;
    return !(x < 0 || x >= xBounds || y < 0 || y >= yBounds); };
    std::copy_if(possiblePositions.begin(), possiblePositions.end(), std::back_inserter(validPositions), isValid);

    return validPositions;
}

// get the sum value of the surrounding cells
unsigned int Conway::calculateCellValue(const Coord &pos) const noexcept
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
bool Conway::isCellAliveNextTurn(const unsigned int &val, const bool &isAlive) noexcept
{
    // if its alive then it will stay alive if val is 2 or 3
    // if it is not alive then it will become alive if val == 3
    return (isAlive) ? (val == 2 || val == 3) : val == 3;
}

// determines this cells state for the next position
bool Conway::aliveInNextIteration(const Coord &pos) const noexcept
{
    unsigned int cellValue = calculateCellValue(pos);             // get the number of cells around the current pos that are alive
    bool isAlive = currentState[pos.first][pos.second];           // is the cell currently alive?
    bool aliveNextTurn = isCellAliveNextTurn(cellValue, isAlive); // apply rules to determine if it will be alive next turn
    return aliveNextTurn;
}

// output the current grid state to the console
void Conway::displayGrid() const noexcept
{
    // should only display the 10 x 5 central grid
    // assuming that the grid is atleast 10 x 5
    for (unsigned int i = 0; i < displayBoundsX; ++i)
    {
        for (unsigned int j = 0; j < displayBoundsY; ++j)
        {
            std::cout << (currentState[i + offSet][j + offSet] ? "+" : " ") << " ";
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

Conway::Conway(const Grid &initialState) : currentState(initialState)
{
    xBounds = initialState.size();
    yBounds = initialState[0].size();
    displayBoundsX = xBounds - offSet;
    displayBoundsY = yBounds - offSet;
}

Conway::Conway(const std::vector<Coord> &pattern, const unsigned int &xBounds, const unsigned int &yBounds) : xBounds(xBounds), yBounds(yBounds)
{
    currentState.resize(xBounds, std::vector<bool>(yBounds));

    // want to find the offset shift to put it in the center
    // assuming the pattern is 0 centered
    displayBoundsX = xBounds - offSet;
    displayBoundsY = yBounds - offSet;

    int xShift = (xBounds - offSet) / 2;
    int yShift = (yBounds - offSet) / 2;
    for (auto &[x, y] : pattern)
    {
        currentState[x + xShift][y + yShift] = true;
    }
}

// Take an initial state and produce the next iteration
Grid Conway::produceNextState(const Grid &initialState) const
{
    Grid nextState;
    nextState.resize(xBounds, std::vector<bool>(yBounds));
    for (unsigned int i = 0; i < xBounds; ++i)
    {
        for (unsigned int j = 0; j < yBounds; ++j)
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
    bool manual = false;
    while (true)
    {
        bool loopCondition = true;
        char c;
        while (loopCondition)
        {
            system("cls");
            displayGrid();
            // wait for input

            displayMenu();

            if (manual)
            {
                c = userInput::waitForCharInput();
            }
            else
            {
                c = userInput::waitForCharInput(1);
            }

            currentState = produceNextState(currentState);

            switch (c)
            {
            case '_':
                continue;
            case 'R':
            case 'r':
                loopCondition = false;
                break;
            case 'Q':
            case 'q':
                loopCondition = false;
                break;
            case 'P':
            case 'p':
                system("pause");
                break;
            case 'M':
            case 'm':
                manual = !manual;
                break;
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

void Conway::displayMenu() const
{
    std::cout << "M to switch progression mode \nP to pause \nR to reset \nQ to exit \n";
}