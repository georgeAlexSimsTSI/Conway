#include "../include/conway.h"

using Coord = std::pair<unsigned int, unsigned int>; // doing this so that I get some practice
using Grid = std::array<std::array<bool, yDimension>, xDimension>;

// determine if the provided position is inside the grid
bool Conway::isValidPosition(const Coord &pos)
{
    return (pos.first < 0 || pos.first >= xDimension && pos.second < 0 || pos.second >= yDimension);
}

// return a vector containing coordinates of the surrounding cells that are inside the valid bounds
std::vector<Coord> Conway::getSurroundingCells(const Coord &pos)
{
    return {};
}

// get the sum value of the surrounding cells
unsigned int Conway::calculateCellValue(const Coord &pos)
{
    return 0u;
}

// given number of surrounding cells determine if will become alive or dead
bool Conway::isCellAlive(const unsigned int &val)
{
    return true;
}

// determines this cells state for the next position
bool Conway::aliveInNextIteration(const Coord &pos)
{
    return true;
}

// output the current grid state to the console
void Conway::displayGrid()
{
}

// method to wait for a user input
char Conway::waitForInput()
{
    return '_';
}

explicit Conway::Conway(const Grid &initialState) : currentState(initialState)
{
}
explicit Conway::Conway(const std::vector<Coord> &pattern)
{
}

// Take an initial state and produce the next iteration
Grid Conway::produceNextState(const Grid &initialState)
{
}

// main run method
void Conway::run()
{
}