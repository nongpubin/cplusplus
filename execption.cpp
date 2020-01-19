#include <iostream>
#include <vector>
#include <stdexcept>
#include "output_container.h"

using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4};
    cout << v << endl;

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    cout << v[4] << endl;
    cout << v[5] << endl;

    //cout << v.at(5) << endl; //抛出异常

    try { v.at(5);}
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    
    return 0;
}

