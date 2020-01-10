#include <iostream>
#include <string.h>
#include <unistd.h>
#include "output_container.h"
#include <vector>
#include <map>


#include <algorithm>
#include <list>
#include <queue>
#include <stack>

/*
容器的共同点：
1、容器都有开始和结束点。
2、容器会记录其状态是否非空。
3、容器有大小。
4、容器支持交换。
*/

using namespace std;

//vector拷贝与移动

class obj1
{
    public:
        obj1() { cout << "obj1 ... " << endl;}
        obj1(const obj1 &) { cout << " const obj1 & " << endl; }
        obj1(const obj1 &&) { cout << " const obj1 && " << endl; }
};


class obj2
{
 
public:
    obj2() { cout << "obj2 ... " << endl; }
    obj2(const obj2 &)  { cout << " const obj2 & " << endl; }
    obj2(const obj2 &&) noexcept { cout << " const obj2 && " << endl; }   //加noexcept
};

 


int main()
{
   /* map<int, int> test{{1, 1}, {2, 4}, {3, 9}};
    cout << test << endl;
    vector<vector<int>> vv{{7,8},{6,2},{11,25}};
    cout << vv << endl;

    string name;
    cout << "What's your name? ";
    getline(cin, name);
    cout << "Nice to meet you, " << name << "!\n";*/
#if 0
   vector<obj1> v1;
   v1.reserve(2);
   v1.emplace_back();
   v1.emplace_back();
   v1.emplace_back();

  vector<obj1> v3;
   v3.reserve(2);
   v3.emplace_back();
  // v3.push_back(v1);
   v3.emplace_back();
   v3.emplace_back();

   vector<std::string> name;
   name.push_back("name");
   name.push_back("hi");

   cout << name << endl;
   /*
   vector<obj2> v2;
   v2.reserve(2);
   v2.emplace_back();
   v2.emplace_back();
   v2.emplace_back();*/
#endif
    
    list<int> lst{1, 7, 2, 8, 3};
    vector<int> vec{4, 7, 2, 8, 3};

    sort(vec.begin(), vec.end());     
     //sort(lst.begin(), lst.end());  //  会出错
    lst.sort();                        

    cout << vec << endl;
    cout << lst << endl;

    /*std::queue<int> q;  
    q.push(1);  
    q.push(2); 
    q.push(3);  
    while (!q.empty()) {    
        std::cout << q.front()  << std::endl;    q.pop();  }*/

    std::stack<int> s; 
     s.push(1);  
     s.push(2);  
     s.push(3); 
        while (!s.empty()) 
        {  std::cout << s.top()  << std::endl;    
        s.pop();  }
   return 0;
}



