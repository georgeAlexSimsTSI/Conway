#ifndef USER_INPUT_H
#define USER_INPUT_H
#include <conio.h>
#include <unistd.h>

namespace userInput
{
    /**
     * @brief A program that will wait a given amount of seconds for any keyboard input
     *
     * @param seconds number of seconds to wait
     * @return char the entered character
     */
    char waitForCharInput(int seconds);
};
#endif