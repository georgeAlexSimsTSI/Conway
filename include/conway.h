#ifndef CONWAY_H
#define CONWAY_H

#define xDimension 18 // only displaying center 10
#define yDimension 18 // only displaying center 5

#define offSet 2

#include <array>
#include <vector>
#include <iostream>

#include "./userinput.h"

class Conway
{

private:
    using Coord = std::pair<unsigned int, unsigned int>; // doing this so that I get some practice
    using Grid = std::array<std::array<bool, yDimension>, xDimension>;

    unsigned int displayX = 14, displayY = 14;

    // array of living or dead cells, only 2 states so using a boolean value
    Grid currentState; // [x][y]

    // determine if the provided position is inside the grid
    static bool isValidPosition(const Coord &pos);

    // return a vector containing coordinates of the surrounding cells that are inside the valid bounds
    static std::vector<Coord> getSurroundingCells(const Coord &pos);

    // get the sum value of the surrounding cells
    unsigned int calculateCellValue(const Coord &pos);

    // given number of surrounding cells determine if will become alive or dead
    bool isCellAliveNextTurn(const unsigned int &val, const bool &isAlive);

    // determines this cells state for the next position
    bool aliveInNextIteration(const Coord &pos);

    // output the current grid state to the console
    void displayGrid();

    // method to wait for a user input
    char waitForInput();

public:
    explicit Conway(const Grid &initialState);
    explicit Conway(const std::vector<Coord> &pattern);

    // Take an initial state and produce the next iteration
    Grid produceNextState(const Grid &initialState);

    // main run method
    void run();
};

#endif