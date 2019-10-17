
/**
* CS V15 Object Oriented Programming
* Assignment: Nifty
*
* Statement of code ownership: I hereby state that I have written all of this
* code and I have not copied this code from any other person or source.
*
* Jesus Ochoa
*/

#include <iostream>
#include <iomanip>
#include <glob.h>
#include <fstream>
#include <sstream>
#include <ostream>


using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2){
        std::cerr << "Usage: " << argv[0] << "[data file].csv" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream data (argv[1]);

    std::string text;
    while(data >> text ) {
        istringstream columns(text);
        string datum;
        while (getline(columns, datum), && !columns.eof()) {
            cout << datum << endl;
            istringstream val (datum);
            uint64_t value;
            val >> value;

            if (!number.fail()) {
                cout << num << endl;
                data_points++;
                counts[datum[0] - '0']++;
            }

        }
        cout <<text <<endl;
    }

    return EXIT_SUCCESS
}


if (num = 0)


if (num == ) int 1

for int 2;

for int 3;

for int 4;

for int 5;

for int 6;

for int 7;

for int 8,

for int 9;


return EXIT_SUCCESS;
}

