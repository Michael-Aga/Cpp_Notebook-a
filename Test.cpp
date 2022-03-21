#include <stdexcept>
#include "doctest.h"
#include "Notebook.hpp"
#define MALAWAH "MALAWAH"

using namespace ariel;
using namespace std;

Notebook notebook;

TEST_CASE("Bad input")
{
    /*
    In this test case we will check if we get bad input from the user will we get an error,
    first we will check the write function in Horizonatl and Vertical mode.
    */
    CHECK_THROWS(notebook.write(-1, 0, 0, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, -1, 0, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, -1, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 168, Direction::Horizontal, MALAWAH));

    CHECK_THROWS(notebook.write(-1, 0, 0, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, -1, 0, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, -1, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 168, Direction::Vertical, MALAWAH));

    /*
    Next we will check the read function, again Horizontal and Vertical.
    */
    CHECK_THROWS(notebook.read(-1, 0, 0, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(0, -1, 0, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(0, 0, -1, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(0, 0, 168, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(0, 0, 0, Direction::Horizontal, -5));

    CHECK_THROWS(notebook.read(-1, 0, 0, Direction::Vertical, 5));
    CHECK_THROWS(notebook.read(0, -1, 0, Direction::Vertical, 5));
    CHECK_THROWS(notebook.read(0, 0, -1, Direction::Vertical, 5));
    CHECK_THROWS(notebook.read(0, 0, 168, Direction::Vertical, 5));
    CHECK_THROWS(notebook.read(0, 0, 0, Direction::Vertical, -5));

    /*
    Now we will check the erase function.
    */
    CHECK_THROWS(notebook.erase(-1, 0, 0, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(0, -1, 0, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(0, 0, -1, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(0, 0, 168, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(0, 0, 0, Direction::Horizontal, -5));

    CHECK_THROWS(notebook.erase(-1, 0, 0, Direction::Vertical, 5));
    CHECK_THROWS(notebook.erase(0, -1, 0, Direction::Vertical, 5));
    CHECK_THROWS(notebook.erase(0, 0, -1, Direction::Vertical, 5));
    CHECK_THROWS(notebook.erase(0, 0, 168, Direction::Vertical, 5));
    CHECK_THROWS(notebook.erase(0, 0, 0, Direction::Vertical, -5));

    /*
    Even though it wasnt asked we will do a little check for the show function.
    */
    CHECK_THROWS(notebook.show(-1));
}

TEST_CASE("Check the write function on an existing line")
{
    /*
    In this test case we will try to write on an existing line on horizontal mode
    */
    notebook.write(0, 0, 0, Direction::Horizontal, MALAWAH);

    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 1, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 2, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 3, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 4, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 5, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 6, Direction::Horizontal, MALAWAH));

    /*
    Below we will try to write on vertical mode on the same line as before
    */
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 1, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 2, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 3, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 4, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 5, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 6, Direction::Vertical, MALAWAH));

    /*
    Here we will "erase" the line and try to write on it on horizontal mode
    */
    notebook.erase(0, 0, 0, Direction::Horizontal, 5);

    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 1, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 2, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 3, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 4, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 5, Direction::Horizontal, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 6, Direction::Horizontal, MALAWAH));

    /*
    And here we will try on vertical mode
    */
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 1, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 2, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 3, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 4, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 5, Direction::Vertical, MALAWAH));
    CHECK_THROWS(notebook.write(0, 0, 6, Direction::Vertical, MALAWAH));
}