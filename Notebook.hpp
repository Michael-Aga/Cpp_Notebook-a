#include <iostream>
#include <string>
#include "Direction.hpp"

using namespace std;

namespace ariel
{
    class Notebook
    {
    public:
        void write(int page, int row, int col, Direction direction, string const &sentence);
        static string read(int page, int row, int col, Direction direction, int lenght);
        void erase(int page, int row, int col, Direction direction, int lenght);
        void show(int page_to_show);
    };
}