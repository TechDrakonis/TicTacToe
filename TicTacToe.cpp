#include <iostream>
#include <array>
#include "c++s50.hpp"

void game_field(std::array<char, 9>);
char winner(std::array<char, 9>);
int menu();

int main()
{
    // declare and define or initialize needed variables
    int i{ 0 }, input;
    std::array<char, 9> values{'1', '2', '3',
                               '4', '5', '6',
                               '7', '8', '9'};
    std::array<char, 2> x_o{'X', 'O'};

    game_field(values);

    values.fill(' ');

    for(; i < 9; ++i)
    {
        // which field
        do
        {
            get_value("Please input the field, where you want to tip [1 - 9]: ", input);
        } while(input < 1 || input > 10 || values[--input] != ' ');

        // initializing of values[i] with char X or O
        values[input] = x_o[i % 2];

        // output and create the game field
        game_field(values);

        char victor{ winner(values) };
        if(victor == 'X' || victor == 'O')
        {
            std::cout << "The winner is Player: " << victor << "\n" << std::endl;
            break;
        }

        std::cout << "\n" << std::endl;
    }

    if(!menu())
    {
        main();
    }

    return 0;
}

void game_field(std::array<char, 9> values)
{
    for(int i{ 0 }; i < 9; i += 3)
    {
        if(i == 3)
        {
            std::cout << "\n";

            for(int u{0}; u < 9; ++u)
            {
                std::cout << "-";
            }

            std::cout << "\n";

            for(int l{ 0 }; l < 3; ++l)
            {
                if(l == 1)
                {
                    std::cout << " | " << values[i + l] << " | ";
                }
                else
                {
                    std::cout << values[i + l];
                }
            }

            std::cout << "\n";

            for(int u{0}; u < 9; ++u)
            {
                std::cout << "-";
            }

            std::cout << "\n";
        }
        else
        {
            for(int l{ 0 }; l < 3; ++l)
            {
                if(l == 1)
                {
                    std::cout << " | " << values[i + l] << " | ";
                }
                else
                {
                    std::cout << values[i + l];
                }
            }
        }
    }

    std::cout << std::endl;
}

char winner(std::array<char, 9> values)
{
    char _0{ values[0] }, _1{ values[1] }, _2{ values[2] }, _3{ values[3] }, _4{ values[4] }, _5{ values[5] }, _6{ values[6] }, _7{ values[7] }, _8{ values[8]};
    if((_0 == _4 && _4 == _8) || (_2 == _4 && _4 == _6) || (_1 == _4 && _4 == _7) ||( _3 == _4 && _4 == _5))
    {
        return _4;
    }
    else if((_0 == _1 && _0 == _2) || (_0 == _3 && _0 == _6))
    {
        return _0;
    }
    else if(_2 == _8 && _5 == _8 || _6 == _8 && _7 == _8)
    {
        return _8;
    }
    else
    {
        return 'd'; // draw
    }
}

int menu()
{
    int i;
    do
    {
        get_value("(1) new\n(2) exit\nyour decision: ", i);
    } while(i != 1 && i != 2);
    return --i;
}
