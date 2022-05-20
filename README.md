# Conways game of Life


## Rules

<pre>
· Any live cell with fewer than two live neighbor's dies as if caused by under pop
· Any live cell with 2 or more neighbor's will live
· Any live cell with more than 3 neighbor's will die
· any dead cell with 3 live neighbor's becomes live
</pre>

## Goals

<pre>
· The world is represented by a 2D array (10 x 5)
· This 2d array should be represented in the CMD/Terminal as a grid
· Each cell is represented by a “.” for dead and “*” for living
· Initial state or a seed world will need to be used to kick off the life
· Your code should use the seed world to generate the next generation
· Correctly handle cells that start to “go off the board” cells that go off the edge do not get displayed
</pre>

## Example

<pre>
Input : ..........
        ...**.....
        ....*.....
        ..........
        ..........

Output: ..........
        ...**.....
        ...**.....
        ..........
        ..........
        ..........
</pre>

## Extras

<pre>
★
· Have the game “tick”, progress a generation with each tick
· Implement a restart (which goes back to initial state)
· Implement a pause (which halts the progression of time)
· Implement a way to go from manual progression to automatic progression

★★
· Instead of providing an entire seed world simply supply a seed pattern/s that can be put down in the centre of the world
· Experiment with the world size / Have the user decide the world size
</pre>