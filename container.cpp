#include <iostream>
#include <string.h>
#include <unistd.h>
#include "output_container.h"
#include <vector>
#include <map>


using namespace std;

int main()
{
    map<int, int> test{{1, 1}, {2, 4}, {3, 9}};
    cout << test << endl;
    vector<vector<int>> vv{{7,8},{6,2},{11,25}};
    cout << vv << endl;
    return 0;
}



