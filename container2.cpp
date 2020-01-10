
#include <algorithm>   // std::sort
#include <functional>  // std::less/greater/hash
#include <iostream>    // std::cout/endl
#include <string>      // std::string
#include <vector>      // std::vector
#include "output_container.h"
#include <queue> 

/*
template <class T> struct hash;

template <>
struct hash<int>
  : public unary_function<int, size_t> {
  size_t operator()(int v) const
    noexcept
  {
    return static_cast<size_t>(v);
  }
};
*/
using namespace std;

int main()
{
  /*//  初始数组
  vector<int> v{13, 6, 4, 11, 29};
  cout << v << endl;

  //  从小到大排序
  sort(v.begin(), v.end());
  cout << v << endl;

  //  从大到小排序
  sort(v.begin(), v.end(),greater<int>());
  cout << v << endl;
  cout << hex;

  auto hp = hash<int*>();
  cout << "hash(nullptr)  = " << hp(nullptr) << endl;
  cout << "hash(v.data()) = " << hp(v.data()) << endl;
  cout << "v.data()       = " << static_cast<void*>(v.data()) << endl;

  auto hs = hash<string>();
  cout << "hash(\"hello\")  = " << hs(string("hello")) << endl;
  cout << "hash(\"hellp\")  = " << hs(string("hellp")) << endl;
*/
    priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>>  q; 
    q.push({1, 1});  
    q.push({2, 2}); 
    q.push({0, 3}); 
    q.push({9, 4}); 
    while (!q.empty()) {   
        cout << q.top() << endl;    
        q.pop(); 
    }

}