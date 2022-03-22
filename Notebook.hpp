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
        static string read(int page, int row, int col, Direction direction, int length);
        void erase(int page, int row, int col, Direction direction, int length);
        void show(int page_to_show);
    };
}