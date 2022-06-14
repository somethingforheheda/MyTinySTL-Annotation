#ifdef _MSC_VER
#define _SCL_SECURE_NO_WARNINGS
#endif

#if defined(_MSC_VER) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif // check memory leaks

#include "algorithm_performance_test.h"
#include "algorithm_test.h"
#include "vector_test.h"
//#include "list_test.h"
//#include "deque_test.h"
//#include "queue_test.h"
//#include "stack_test.h"
//#include "map_test.h"
//#include "set_test.h"
//#include "unordered_map_test.h"
//#include "unordered_set_test.h"
//#include "string_test.h"
#include "../MyTinySTL/vector.h"
#include "iostream"
using namespace std;

class Test
{
private:
    int m_a;
    float m_b;
    string m_str;
public:
    void show() { cout << "m_a = " << m_a << " m_b = " << m_b << " m_str = " << m_str << endl; }
    friend ostream & operator<<(ostream &out, const Test &c);


    Test(int m_a,float m_b,string m_str)
    {
        this->m_a=m_a;
        this->m_b=m_b;
        this->m_str=std::move(m_str);
    }
};

ostream & operator<<(ostream &out, const Test &c)
{
    out << c.m_a << "," << c.m_b << c.m_str;
    return out;
}

int main()
{
    using namespace mystl::test;//测试1


    Test *c=new Test(2,2.1,"str");
    Test t1(3,3.1,"str111");

//    mystl::vector<int> vec_a;
//    vec_a.push_back(1);
    mystl::vector<Test*> mm;
    mm.push_back(c);

    mystl::vector<int> int_vec;
    int_vec.push_back(1);
    cout << int_vec.at(0) <<endl;
    mm.at(0)->show();
    //cout << mm.at(0) <<endl;

//  std::cout.sync_with_stdio(false);
//
//  RUN_ALL_TESTS();
//  algorithm_performance_test::algorithm_performance_test();
//  vector_test::vector_test();
//
//
//  list_test::list_test();
//  deque_test::deque_test();
//  queue_test::queue_test();
//  queue_test::priority_test();
//  stack_test::stack_test();
//  map_test::map_test();
//  map_test::multimap_test();
//  set_test::set_test();
//  set_test::multiset_test();
//  unordered_map_test::unordered_map_test();
//  unordered_map_test::unordered_multimap_test();
//  unordered_set_test::unordered_set_test();
//  unordered_set_test::unordered_multiset_test();
//  string_test::string_test();

#if defined(_MSC_VER) && defined(_DEBUG)
    _CrtDumpMemoryLeaks();
#endif // check memory leaks

}
