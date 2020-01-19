
#include <algorithm> // std::copy
#include <iterator>  // std::back_inserter
#include <vector>    // std::vector
#include "output_container.h"
#include <iostream>
 
#include <fstream>

using namespace std;

class istream_line_reader
{
public:
    class iterator
    {
        public:
            typedef ptrdiff_t difference_type;
            typedef string value_type;
            typedef const value_type *pointer;
            typedef const value_type &reference;
            typedef input_iterator_tag iterator_category;
    }
    istream_line_reader() noexcept: stream_(nullptr) {}
    explicit istream_line_reader(istream &is) noexcept : stream_(&is) {}

    iterator begin() {
        return iterator(*stream_);
    }

    iterator end() const noexcept {
        return iterator();
    }

private:
    istream *stream_;
};

int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6};
    vector<int> v2;
    copy(v1.begin(), v1.end(),back_inserter(v2));

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    copy(v2.begin(), v2.end(),ostream_iterator<int>(cout,""));
    cout << endl;
/*
    for (const string &line :istream_line_reader(is)) {
        cout << line << endl;
    }*/

    return 0;
}