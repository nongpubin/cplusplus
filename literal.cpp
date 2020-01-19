#include <iostream>
#include <vector>
#include <stdexcept>
#include "output_container.h"
#include <unistd.h>
#include <chrono>
#include <complex>
#include <string>
#include <thread>

using namespace std;

int main()
{
    cout << "literal test" << endl;

    cout << "i * i = " << 1i * 1i << endl;
    cout << "Waiting for 500ms" << endl;
    this_thread::sleep_for(500ms);
    cout << "Hello world"s.substr(0, 5) << endl;

    return 0;
}