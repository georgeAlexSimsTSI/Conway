#ifndef CONWAY_H
#define CONWAY_H

#include <vector>
#include <iostream>

#include "./userinput.h"

class Conway
{

private:
    using Coord = std::pair<unsigned int, unsigned int>; // doing this so that I get some practice
    using Grid = std::vector<std::vector<bool>>;

    unsigned int xBounds = 18, yBounds = 18;
    unsigned int displayBoundsX = 14, displayBoundsY = 14;
    unsigned int offSet = 2;

    // vector of living or dead cells, only 2 states so using a boolean value
    Grid currentState; // [x][y]

    // return a vector containing coordinates of the surrounding cells that are inside the valid bounds
    std::vector<Coord> getSurroundingCells(const Coord &pos) const noexcept;

    // get the sum value of the surrounding cells
    unsigned int calculateCellValue(const Coord &pos) const noexcept;

    // given number of surrounding cells determine if will become alive or dead
    static bool isCellAliveNextTurn(const unsigned int &val, const bool &isAlive) noexcept;

    // determines this cells state for the next position
    bool aliveInNextIteration(const Coord &pos) const noexcept;

    // output the current grid state to the console
    void displayGrid() const noexcept;

    void displayMenu() const;

public:
    explicit Conway(const Grid &initialState);
    explicit Conway(const std::vector<Coord> &pattern, const unsigned int &xBounds, const unsigned int &yBounds);

    // Take an initial state and produce the next iteration
    Grid produceNextState(const Grid &initialState) const;

    // main run method
    void run();
};

#endif