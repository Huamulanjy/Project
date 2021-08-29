
/*
// bind example
#include <iostream>     // std::cout
#include <functional>   // std::bind
// using namespace std;
// a function: (also works with function object: std::divides<double> my_divide;)
double my_divide (double x, double y) {return x/y;}

struct MyPair {
  double a,b;
  double multiply() {return a*b;}
};


int main () {
  using namespace std::placeholders;    // adds visibility of _1, _2, _3,...

  // binding functions:
  auto fn_five = std::bind (my_divide,10,2);               // returns 10/2
  std::cout << fn_five() << '\n';                          // 5

  auto fn_half = std::bind (my_divide,_1,2);               // returns x/2
  std::cout << fn_half(10) << '\n';                        // 5

  auto fn_invert = std::bind (my_divide,_2,_1);            // returns y/x
  std::cout << fn_invert(10,2) << '\n';                    // 0.2

  auto fn_rounding = std::bind<int> (my_divide,_1,_2);     // returns int(x/y)
  std::cout << fn_rounding(10,3) << '\n';                  // 3

  MyPair ten_two {10,2};

  // binding members:
  auto bound_member_fn = std::bind (&MyPair::multiply,_1); // returns x.multiply()
  std::cout << bound_member_fn(ten_two) << '\n';           // 20

  auto bound_member_data = std::bind (&MyPair::a,ten_two); // returns ten_two.a
  std::cout << bound_member_data() << '\n';                // 10

  return 0;
}*/
/*
#include <iostream>     // std::cout
using namespace std;

class ActMove
{
public:
//     struct Args
//     {
//         Args() : linear_vel(0.0), distance(0.0), angle(0.0), angle_mode(kRelativeAngle), need_fadeout(false){};
//         Args(float linear_vel, float distance, float angle, AngleMode angle_mode, bool need_fadeout)
//             : linear_vel(linear_vel)
//             , distance(distance)
//             , angle(angle)
//             , angle_mode(angle_mode)
//             , need_fadeout(need_fadeout){};
// 
//         float     linear_vel;   // 米/秒，最大线速度，不可为负
//         float     distance;     // 米，移动距离，正为前进，负为倒车
//         float     angle;        // 弧度，直行过程需要维持的角度，正为逆时针，负为顺时针
//         AngleMode angle_mode;   // 维持的角度是相对还是绝对角度
//         bool      need_fadeout; // 接近设定距离时减速
//     };

/*     ActMove(const std::string &name, Chassis *chassis, const ActionArgs *arg);
    ActMove(){};
//     kMinTimeoutMs(kMinTimeoutMs), 
//     kLinearAlpha(kLinearAlpha), 
//     kLinearVelLim(kLinearVelLim), 
//     kAngularAlpha(kAngularAlpha),
//     kAngularVelLim(kAngularVelLim){}
//     void SetTarget(const ActionArgs *arg);
    void Update() ;
    void CheckTarget() ;

// private:
    void SetTargetAfterPoseInit();

//     Args     target_;
    float    accu_distance_;
    float    linear_vel_lim_;
    float    angular_vel_lim_;
    uint32_t exec_timeout_ms_;

   int   kMinTimeoutMs     =1;
     float kLinearAlpha     =2;
    float kLinearVelLim    =3 ;
    float kAngularAlpha     =4;
    float kAngularVelLim    =5;
};


int main () {
//   int *p = new int(10);
//   printf("address of 10:%X\n", p);
//   std::cout << *p<< '\n';                // 10

//   ActMove * actptr;
  ActMove move;
//   int16_t tmp = 
  move.kLinearAlpha = 6;
  cout<<move.kMinTimeoutMs<<endl;
  cout<<move.kLinearAlpha<<endl;
  
//   cout<< actpt
  return 0;
}*/
/*
#include <iostream>// std::cout
#include <vector>
using namespace std;

int main()
{
  std::vector<int> myvect;
  for(int i = 1; i < 9; i++)
    myvect.push_back(i);
  
cout<<"遍历vector";
//   1
  cout<<endl<<"method1:use .at     myvect: ";
  for (int i = 0; i < myvect.size(); i++)
    cout<<myvect.at(i)<<" ";
//   2
  cout<<endl<<"method2:use iterator:     myvect: ";
//   for(auto it = myvect.begin(); it < myvect.end(); it++)
  for(auto it = myvect.begin(); it < myvect.end(); ++it)
    cout<<*it<<" ";
//   3
  cout<<endl<<"method3:use for(auto:)    myvect: ";
  for(auto a:myvect)
    cout<<a<<" ";
//   4
  cout<<endl<<"method3:use for(auto &:)  myvect: ";
  for(auto &b:myvect)
    cout<<b<<" ";
    

    return 0;
}*/

//*************functional

// 3.1 使用std::bind()和std::function来实现
// std::function是通用的多态函数封装器，它的实例可以存储、复制以及调用任何可以调用的目标：函数，lambda表达式/bind表达式或其他函数对象，还有指向成员函数指针和指向数据成员指针；
// std::bind接受一个函数（或者函数对象），生成一个重新组织的函数对象；
// 看下面一个例子，classA提供了一个注册函数，用来注册一个回调函数
// #include <iostream>// std::cout
// #include <vector>
// #include <functional>
// class classA
// {
//   typedef std::function<void(int i)> callback_t;
// 
//     void registCb(callback_t func)
//     {cbHandle = std::move(func);}
// private:
//     callback_t cbHandle;
// };
// // 另一个类classB需要注册自己的一个成员函数作为回调函数到classA中，这里就可以使用std::bind函数来实现，
// 
// class classB
// {
// public:
//     classB(classA& cA) 
//     {       
//         cA.registCb(std::bind(&classB::handle, this, std::placeholders::_1));
//     }
// };
// // bind函数中显示的传递classB的this指针作为第一个参数给回调函数；
// // std::placeholders:_1代表一个占位符，用于回调函数显式的入参；
/*

#include <iostream>
#include <functional>
#include <memory>
 
class classA
{
// typedef std::function<void(int i)> callback_t;
// same as:
using callback_t = std::function<void(int i)> ;
 
public:
    classA() {}
    ~classA() {}
    
    void handle(int i)
    {
        std::cout << "classA::handle" << std::endl;
        
        cbHandle(i);
    }
 
    void registCb(callback_t func)
    {cbHandle = std::move(func);}
private:
    callback_t cbHandle;
};
 
class classB
{
public:
    classB(classA& cA) 
    {       
//         cA.registCb([this](int i){classB::handle(i);});
	cA.registCb(std::bind(&classB::handle, this, std::placeholders::_1));
    }
    ~classB() {}
    
    void handle(int i)
    {
        std::cout << "classB, handle message" << i << std::endl;
    }
};
 
int main()
{
    classA testa;
    classB testb(testa);
 
    testa.handle(10);
}

// lambda表达式中捕获了classB的this指针
// 使用std::move的方式保存function对象到classA中
 */
/*
#include <functional>
#include <iostream>
#include <string>
using namespace std;

std::function<int(int)> Functional;
std::function<void(int a)> fun1;
std::function<void(string str)> fun2;
std::function<string(int a, int b)> fun3;
// 普通函数
int TestFunc(int a)
{
    cout << "normal_function" <<endl;
    return a;
}

// Lambda表达式
auto lambda = [](int a)->int{ return a; };
auto lambda1 = [](int a, int b)->string{ int c = a + b;return "hello"; };

// 仿函数(functor)
class Functor
{
public:
    int operator()(int a)
    {
        return a;
    }
};

// 1.类成员函数
// 2.类静态函数
class TestClass
{
public:
    int ClassMemberFunc(int a) { return a; }
    static int StaticMember(int a) { return a; }
};


int main()
{
    // 普通函数
    Functional = TestFunc;
    int result = Functional(10);
    cout << "普通函数："<< result << endl;

    // Lambda表达式
    Functional = lambda;
    result = Functional(20);
    cout << "Lambda表达式："<< result << endl;

    // 仿函数
    Functor testFunctor;
    Functional = testFunctor;
    result = Functional(30);
    cout << "仿函数："<< result << endl;

    // 类成员函数
    TestClass testObj;     //定义对象
    Functional = std::bind(&TestClass::ClassMemberFunc, testObj, std::placeholders::_1);    //绑定
    result = Functional(40);
    cout << "类成员函数："<< result << endl;

    // 类静态函数
    Functional = TestClass::StaticMember;
    result = Functional(50);
    cout << "类静态函数："<< result << endl;

    fun1 = TestFunc;
    fun1(1);

    fun3 = lambda1;
    cout << fun3(2, 3) <<endl;
    return 0;
}
*/
//bubblesort
/*
#include <iostream>
using namespace std;

void bubblesort(int *arr, int length)
{
  int temp;
  for(int i = 0; i < length; i++)
  {
    for(int j = 0; j< length-1-i; j++)
    {
      if(arr[j] >= arr[j+1])
      {
      temp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1] = temp;
      }
    }
  }
 return; 
}

void printarry(int *arr, int length)
{
  for(int i = 0; i < length; i++)
    cout<<arr[i];
  return;
}



int main()
{
  int a[] = {2,3,4,5,6,7,8};
  int len = sizeof(a)/sizeof(a[0]);
  
  cout<<"origin arry: ";
  printarry(a, len);
  bubblesort(a, len);
  cout<<endl;
  cout<<"bubblesort arry: ";
  printarry(a, len);
  
  return 0;
}*/


//****************vector************
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Myprint(int val)
{
    cout << val <<endl;
}
void test01()
{
  std::vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
//method 1
  std::vector<int>::iterator itBegin = v.begin();
  auto itEnd = v.end();
  while(itBegin != itEnd)
  {
    cout<<*itBegin<<endl;
    itBegin++;
  }
  //method 2
  for(auto it = v.begin(); it != v.end(); it++)
      cout<<*it<<endl;
  //method 3 :stl support algorithm
  for_each(v.begin(), v.end(), Myprint);//利用回调函数Myprint
}



int main()
{
  test01();
  return 0;
}*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//vector中存放自定义的数据类型
class Person
{
public:
    Person(string name, int age):m_Name(name), m_Age(age){};

    string m_Name;
    int m_Age;
};


void Myprint(int val)
{
    cout << val <<endl;
}
void test01()
{
    std::vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);
//向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for(vector<Person>::iterator it = v.begin();it !=v.end(); it++)
    {
        cout<<"name: "<<(*it).m_Name<<" age: "<< it->m_Age<<endl;
    }
}
//vector中存放自定义的数据类型--pointer
void testPointerType()
{
    std::vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);
//向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
//    遍历容器
    for(vector<Person*>::iterator it = v.begin();it !=v.end(); it++)
    {
        cout<<"name: "<<(*it)->m_Name<<" age: "<< (*it)->m_Age<<endl;
        cout<<"name: "<<(**it).m_Name<<" age: "<< (*it)->m_Age<<endl;
    }
}

int main()
{
    test01();
    testPointerType();
    return 0;
}
*/
/*
//容器中嵌套容器
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void test01()
{
    std::vector<vector<int>> v;
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;


//向容器中添加数据
for(int i = 0; i < 4; i++) {
    v1.push_back(i + 1);
    v2.push_back(i + 2);
    v3.push_back(i + 3);
    v4.push_back(i + 4);
}
v.push_back(v1);
v.push_back(v2);
v.push_back(v3);
v.push_back(v4);

    for(vector<vector<int>>::iterator it = v.begin();it !=v.end(); it++)
    {
        for(auto smallIt = (*it).begin(); smallIt != (*it).end(); smallIt++)
        {
            cout << *smallIt<<" " ;
        }
        cout << endl;
    }
}

int main()
{
    test01();
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
//#include <algorithm>
//#include <string>
using namespace std;


void PrintVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v1;//无参构造
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVector(v1);
    //通过区间方式进行构造
    vector<int> v2(v1.begin(),v1.end());
    PrintVector(v2);
    //n个elem方式构造
    vector<int>v3(10, 100);
    PrintVector(v3);
    //拷贝构造
    vector<int>v4(v3);
    PrintVector(v4);
}

int main()
    {
        test01();

        return 0;
    }
    */
/*
#include <iostream>
#include <vector>
//#include <algorithm>
//#include <string>
using namespace std;

//vector 赋值
void PrintVec(vector<int>& v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int>v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVec(v1);
    //赋值
    vector<int>v2;
    v2 = v1;
    PrintVec(v2);
    //assign
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    PrintVec(v3);
    vector<int>v4;
    v4.assign(5, 10);
    PrintVec(v4);

    if(v1.empty())
    {
        cout << "v1 is empty"<< endl;
    }
    else
    {
        cout << "v1 is not empty"<< endl;
        cout << "capacity of v1: "<< v1.capacity() << endl;
        cout << "size of v1:"<< v1.size()<< endl;
    }
    v1.resize(15, 66);
    PrintVec(v1);

    v1.pop_back();
    PrintVec(v1);

    v1.insert(v1.begin(),100);
    PrintVec(v1);

    v1.insert(v1.begin(),2,20);
    PrintVec(v1);

    v1.at(2);
}

int main()
{
    test01();
    return 0;
}
 */
/*
//swap()
#include <iostream>
#include <vector>
using namespace std;



void PrintVec(vector<int>& v)
{
    for(auto it = v. begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int>v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "origin v1: "<<endl;
    PrintVec(v1);
    vector<int>v2;
    for(int i = 10; i < 20; i++)
    {
        v2.push_back(i);
    }
    cout << "origin v2: "<<endl;
    PrintVec(v2);

    cout << "swap: "<<endl;
//    v1.swap(v2);
    swap(v1, v2);
    cout << "v1: "<<endl;
    PrintVec(v1);
    cout << "v2: "<<endl;
    PrintVec(v2);
}

void test02()
{
    vector<int>v;
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "capacity v: "<<v.capacity()<< endl;
    cout << "size v: "<<v.size()<< endl;

    v.resize(3);
    cout << "capacity v: "<<v.capacity()<< endl;//容量未变化
    cout << "size v: "<<v.size()<< endl;

    //swap()收缩内存
    vector<int>(v).swap(v);
    cout << "capacity v: "<<v.capacity()<< endl;//容量未变化
    cout << "size v: "<<v.size()<< endl;


}

void test03()
{
    vector<int>v;
    int num = 0;
    int * p = nullptr;
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if(p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "alloc memory number:" << num << " times"<<endl;
}

void test04()
{
    vector<int>v;
    int num = 0;
    int * p = nullptr;
    v.reserve(200000);
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if(p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "alloc memory number:" << num << " times"<< endl;
}
int main()
{
//    test01();
//    test02();
    test03();
    test04();
    return 0;

}
 */

//**********************string*************

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test01()
{
    string s1;
    const char * str = "hello world";
    string s2(str);

    cout << "s2= "<< s2 <<endl;

    string s3(s2);
    cout << "s3= "<< s3 <<endl;

}

void test02()
{
    string str1;
    str1 = "hello world";
    cout << "str1: "<< str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2: "<< str2 << endl;

    string str3;
    str3 = 'h';
    cout << "str3: "<< str3 << endl;

    string str4;
    str4.assign("hello c++");
    cout << "str4: "<< str4 << endl;

    string str5;
    str5.assign("hello c++", 4);
    cout << "str5: "<< str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6: "<< str6 << endl;

    string str7;
    str7.assign(6,'b');
    cout << "str7: "<< str7 << endl;

}

void TestStrPlus03()
{
    string str1 = "I ";
    cout << "original str1：" << str1 <<endl;
    str1 += "like ";
    cout << "string overload operator+=() 拼接：" << str1 <<endl;

    str1 += 'h';
    cout << "string overload operator+=() 拼接：" << str1 << endl;
    string str2 = "playing game";
    cout << "original str2：" << str2 << endl;
    str1 += str2;
    cout << "string overload operator+=() 拼接：" << str1 << endl;

    string str3 = "TOM";
    cout << "original str3：" << str3 << endl;
    str3.append(" love ");
    cout << "append：" << str3 << endl;

    str3.append("game adsfsdf",6);
    cout << "append, str3 is: " << str3 << endl;


    str3.append(str2);
    cout << "append str2 to str3：" << str3 << endl;

    str3.append(str2, 0, 4);
    cout << "str3：" << str3 << endl;




}
//string :find();   replace();
void TestFind04()
{
    string str1 = "asdfghjklfg";
    int pos = str1.find("fg");

    if(pos == -1)
    {
        cout << "not find!!" <<endl;

    } else{
        cout << "find str position: ";
    }
    cout << "pos = " << pos <<endl;

//    rfind
    pos = str1.rfind("fg");
    cout << "pos = " << pos <<endl;
}

void TestReplace05()
{
    string str1 = "abcdefg";
    str1.replace(1, 3, "1111");

    cout << "str1 = " << str1 <<endl;
}

void StrCompare() {
    string str1 = "hello";
    string str2 = "hello";
//    str2.append("world");
    if (str1 == str2)
    {
        cout << "compare: str1 == str2" <<endl;
    }
}

//    string access
void CharAccessOfStr()
{
    string str = "hello";
//    cout << "str: " << str <<endl;

//    for (int i = 0; i < str.size(); i++)//same as follows
    cout << "access char of str: " <<endl;
    cout << "1.access str via []: ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout <<endl;
    cout << "2.access str via at: ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout <<endl;
    cout << "3.access str via range-based for loop: ";
//    for (char i :str)
    for (char &i : str)
    {
        cout << i << " ";
    }
    cout << endl;
}

//str.insert();erase();

//substr()

void Substr()
{
    string str = "abcdef";
    string substr = str.substr(1,3);
    cout << "substr: " << substr << endl;

    string email = "zhangsan@sina.com";
    int pos = email.find('@');//8

    string usrName = email.substr(0,pos);
    cout << "get usrName from email: " << usrName <<endl;
}

int main()
{
//    test01();
//    test02();
//    TestStrPlus03();
//    TestFind04();
//    TestReplace05();
//    StrCompare();
//    CharAccessOfStr();
    Substr();
    return 0;
}
*/
//**********************deque*************
/*
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void PrintDeque(const deque<int>&d)
{
     //   use range_based for loop
    for (int it : d)
    {
        cout << it <<" ";
    }
    cout << endl;
    //normal

//    for (auto it = d.begin(); it != d.end(); it++)
//    {
//        cout << *it <<" ";
//    }
//    cout << endl;

}

void DequeConstructorFun()
{
    deque<int>dq;
    for (int i = 0; i < 10; i++)
    {
        dq.push_back(i);
    }
    cout << "dq: " << endl;
    PrintDeque(dq);
//operator=()
    deque<int>d2;
    d2 = dq;
    cout << "d2: " << endl;
    PrintDeque(d2);
//    assign
    deque<int>d4;
   d4.assign(dq.begin(), dq.end());
    cout << "d4: " << endl;
    PrintDeque(d4);
    deque<int>d5;
    d5.assign(10,3);
    cout << "d5: " << endl;
    PrintDeque(d5);
//copy-construc
    deque<int>d3(dq);
    cout << "d3: " << endl;
    PrintDeque(d3);
}

void InsertPushPop()
{
    deque<int>d1;
    d1.push_back(9);
    d1.push_back(11);
    d1.push_front(2);
    d1.push_front(1);
    PrintDeque(d1);//1 2 9 11

    d1.insert(d1.begin(), 0);
    PrintDeque(d1);
    d1.insert(d1.begin(), 2,100);
    PrintDeque(d1);

    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    PrintDeque(d1);
}

void DequeSort()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
//    300 200 100 10 20 30
    cout << "original d1: " << endl;
    PrintDeque(d1);
    cout << "after sort(): " << endl;
    sort(d1.begin(), d1.end());
    PrintDeque(d1);
}
int main()
{
    DequeConstructorFun();
    InsertPushPop();
    DequeSort();
    return 0;
}
 */

//STL-example1
/*
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

class Person
{
public:
    Person(string name, int score) : m_Name(std::move(name)), m_Score(score) {};

    string m_Name;
    int m_Score{};
};

void CreatPerson2Vector(vector<Person>&v)
{
    string nameSeed = "ABCDE";
//    string name;
    for (int i = 0; i < 5; i++)
    {
        string name = "person ";
                name += nameSeed[i];
//        cout << name << endl;
        int score = 0;//默认平均分数为0

        Person p(name, score);//用构造函数初始化对象。
//        放入容器中
        v.push_back(p);
    }
}
//
void SetScore(vector<Person>&v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;//[60,100]生成伪随机数
            d.push_back(score);
        }
//        显示打分结果.遍历容器deque
        cout << "person: " << it->m_Name << " score: " <<endl;
        for (auto & i : d)
        {
            cout << i <<" ";
        }
        cout << endl;

//        排序默认小到大
        sort(d.begin(), d.end());
//        去除最高最低分
        d.pop_back();
        d.pop_front();
//        求和
        u_int32_t sum = 0;
        for (auto dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        u_int32_t avg = sum / d.size();
//        将平均分赋值给选手
        it->m_Score = avg;
    }
}

void ShowScore(vector<Person>&v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << it->m_Name << " aver_score: " << it->m_Score << endl;
    }
}

int main()
{
//    随机数种子。使得每次运行结果不一样。随机
    srand((unsigned int)time(nullptr));
//设置对象
    vector<Person> v;
    CreatPerson2Vector(v);
//10个评委打分
    SetScore(v);
//输出分数
    ShowScore(v);
    return 0;
}
*/
//*************stack**************
/*
#include <iostream>
#include <stack>
using namespace std;

void TestStack()
{
    std::stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "size of stack: " << st.size() <<endl;

    while (!st.empty())
    {
        cout << "top elem: " << st.top() << endl;
        st.pop();
    }
    cout << "size of stack after pop: " << st.size() <<endl;
}
int main()
{
    TestStack();
    return 0;
}
 */




//程序的内存模型：代码区、全局区（全局变量、静态变量、常量--字符串常量，const全局变量）； 栈区（局部变量，不要返回局部变量的地址！！！）
//、堆区
/*
#include <iostream>
using namespace std;
int* fun()
{
    int a = 10;//存放在栈区，函数执行完后内存已经释放，找不到地址。
    return &a;
}

int main()
{
    int *p = fun();

    cout << *p << endl;
    return 0;
}
 */

//*********给定成绩输出成绩等级
#include <iostream>
#include <vector>
#include <deque>
#include <iostream>
#include <random>
using namespace std;

class Person
{
public:
    Person(int score, int grade) : m_Score(score), m_grade(grade) {};

//    string m_Name;
    int m_Score;
    int m_grade;
};

void Set1GirlJumpScore()
{
    std::deque<int>d;
    std::vector<double>run;
    for (int i = 0; i < 19; i++)
    {
        int score = rand() % 25 + 119;//生成伪随机数 119  143     143-119+1
        d.push_back(score);

//        double e;
//        uniform_real_distribution<double> u(6.1, 6.4);
//        run.push_back(u(e));
    }
    cout << "一年级女生跳远成绩" << endl;
    for(auto &it : d)
    {
        cout << it << endl;
    }
        cout << "对应的grade" << endl;
        for(int & it : d) {
            if (it >= 119 && it < 123) {
                cout << "70" << endl;
            } else if (it >= 123 && it < 127) {
                cout << "75" << endl;
            } else if (it >= 127 && it < 131) {
                cout << "80" << endl;
            } else if (it >= 131 && it < 135) {
                cout << "85" << endl;
            } else if (it >= 135 && it < 139) {
                cout << "90" << endl;
            } else if (it >= 139 && it < 143) {
                cout << "95" << endl;
            } else if (it >= 143) {
                cout << "100" << endl;
            }
        }
       /* cout << "一年级女生30Mrun成绩" << endl;
        for(auto &iteme : run)
        {
            cout << iteme << endl;
        }
        cout << "对应的grade" << endl;
        for(int & item : d)
        {
            if(item <= 6.1)
            {
                cout << "100" << endl;
            } else if(item > 6.1 && item <= 6.2)
            {
                cout << "95" << endl;
            }else if(item > 6.2 && item <= 6.3)
            {
                cout << "90" << endl;
            }else if(item >= 6.3 && item < 6.4)
            {
                cout << "85" << endl;
            }
//        cout << deq << " ";
    }
    cout << endl;*/
}

void Set1BoyJumpScore() {
    std::deque<int> d;
    cout << "一年级boy跳远成绩" << endl;
    for (int i = 0; i < 23; i++) {
        int score = rand() % 25 + 129;//生成伪随机数 129  153
        d.push_back(score);
    }

    /*for (int &it : d) {
        if (it >= 129 && it < 133) {
            cout << it << " " << "70" << endl;
        } else if (it >= 133 && it < 137) {
            cout << it << " " << "75" << endl;
        } else if (it >= 137 && it < 141) {
            cout << it << " " << "80" << endl;
        } else if (it >= 141 && it < 145) {
            cout << it << " " << "85" << endl;
        } else if (it >= 145 && it < 149) {
            cout << it << " " << "90" << endl;
        } else if (it >= 149 && it < 153) {
            cout << it << " " << "95" << endl;
        } else if (it >= 153) {
            cout << it << " " << "100" << endl;
        }
//    cout << endl;*/
    for (auto &it : d) {
        cout << it << endl;
    }
    cout << "对应的grade" << endl;
    for (int &it : d) {
        if (it >= 129 && it < 133) {
            cout << "70" << endl;
        } else if (it >= 133 && it < 137) {
            cout << "75" << endl;
        } else if (it >= 137 && it < 141) {
            cout << "80" << endl;
        } else if (it >= 141 && it < 145) {
            cout << "85" << endl;
        } else if (it >= 145 && it < 149) {
            cout << "90" << endl;
        } else if (it >= 149 && it < 153) {
            cout << "95" << endl;
        } else if (it >= 153) {
            cout << "100" << endl;
        }
//    cout << endl;*/
    }
}

void Set1GirlboyboolAndticaoScore()
{
    std::deque<int>d;
    for (int i = 0; i < 44; i++)
    {
        int score = rand() % 16 + 85;//生成伪随机数 85,100
        d.push_back(score);
    }
    cout << "一年级女生bool&ticao成绩" << endl;
    for(auto &it : d)
    {
        cout << it << endl;
    }
    cout << endl;
}

void Set1Girl30sTiaoShenScore()
{
    std::deque<int>d;
    for (int i = 0; i < 19; i++)
    {
        int score = rand() % 13 + 60;//生成伪随机数 60~72
        d.push_back(score);
    }
    cout << "一年级女生跳shen成绩" << endl;
    for(auto &it : d)
    {
        cout << it << endl;
    }
    /* for(auto it = d.begin(); it != d.end(); it++)
     {
         if(*it >= 119 && *it < 123)
         {
             cout << *it << " " << "70" << endl;
         } else if(*it >= 123 && *it < 127)
         {
             cout << *it << " " << "75" << endl;
         }else if(*it >= 127 && *it < 131)
         {
             cout << *it << " " << "80" << endl;
         }else if(*it >= 131 && *it < 135)
         {
             cout << *it << " " << "85" << endl;
         }else if(*it >= 135 && *it < 139)
         {
             cout << *it << " " << "90" << endl;
         }else if(*it >= 139 && *it < 143)
         {
             cout << *it << " " << "95" << endl;
         }else if(*it >= 143 )
         {
             cout << *it << " " << "100" << endl;
         } */
    cout << "对应的grade" << endl;
    for(int & it : d)
    {
        if(it >= 60 && it < 63)
        {
            cout << "80" << endl;
        } else if(it >= 63 && it < 66)
        {
            cout << "85" << endl;
        }else if(it >= 66 && it < 69)
        {
            cout << "90" << endl;
        }else if(it >= 69 && it < 72)
        {
            cout << "95" << endl;
        }else if(it >= 72 )
        {
            cout << "100" << endl;
        }
//        cout << deq << " ";
    }
    cout << endl;
}
void Set1Boy30sTiaoShenScore() {
    std::deque<int> d;
    cout << "一年级boy跳shen成绩" << endl;
    for (int i = 0; i < 23; i++) {
        int score = rand() % 13 + 55;//生成伪随机数 55,67
        d.push_back(score);
    }
//    cout << endl;*/
    for (auto &it : d) {
        cout << it << endl;
    }
    cout << "对应的grade" << endl;
    for (int &it : d) {
        if(it >= 55 && it < 58)
        {
            cout << "80" << endl;
        } else if(it >= 58 && it < 61)
        {
            cout << "85" << endl;
        }else if(it >= 61 && it < 64)
        {
            cout << "90" << endl;
        }else if(it >= 64 && it < 67)
        {
            cout << "95" << endl;
        }else if(it >= 67 )
        {
            cout << "100" << endl;
        }
//    cout << endl;*/
    }
}

void Set4Girl30sTiaoShenScore()
{
    std::deque<int>d;
    for (int i = 0; i < 20; i++)
    {
        int score = rand() % 13 + 60;//生成伪随机数 60~72
        d.push_back(score);
    }
    cout << "一年级女生跳shen成绩" << endl;
    for(auto &it : d)
    {
        cout << it << endl;
    }
    /* for(auto it = d.begin(); it != d.end(); it++)
     {
         if(*it >= 119 && *it < 123)
         {
             cout << *it << " " << "70" << endl;
         } else if(*it >= 123 && *it < 127)
         {
             cout << *it << " " << "75" << endl;
         }else if(*it >= 127 && *it < 131)
         {
             cout << *it << " " << "80" << endl;
         }else if(*it >= 131 && *it < 135)
         {
             cout << *it << " " << "85" << endl;
         }else if(*it >= 135 && *it < 139)
         {
             cout << *it << " " << "90" << endl;
         }else if(*it >= 139 && *it < 143)
         {
             cout << *it << " " << "95" << endl;
         }else if(*it >= 143 )
         {
             cout << *it << " " << "100" << endl;
         } */
    cout << "对应的grade" << endl;
    for(int & it : d)
    {
        if(it >= 60 && it < 63)
        {
            cout << "80" << endl;
        } else if(it >= 63 && it < 66)
        {
            cout << "85" << endl;
        }else if(it >= 66 && it < 69)
        {
            cout << "90" << endl;
        }else if(it >= 69 && it < 72)
        {
            cout << "95" << endl;
        }else if(it >= 72 )
        {
            cout << "100" << endl;
        }
//        cout << deq << " ";
    }
    cout << endl;
}
void Set4Boy30sTiaoShenScore() {
    std::deque<int> d;
    cout << "一年级boy跳shen成绩" << endl;
    for (int i = 0; i < 22; i++) {
        int score = rand() % 13 + 55;//生成伪随机数 55,67
        d.push_back(score);
    }
//    cout << endl;*/
    for (auto &it : d) {
        cout << it << endl;
    }
    cout << "对应的grade" << endl;
    for (int &it : d) {
        if(it >= 55 && it < 58)
        {
            cout << "80" << endl;
        } else if(it >= 58 && it < 61)
        {
            cout << "85" << endl;
        }else if(it >= 61 && it < 64)
        {
            cout << "90" << endl;
        }else if(it >= 64 && it < 67)
        {
            cout << "95" << endl;
        }else if(it >= 67 )
        {
            cout << "100" << endl;
        }
//    cout << endl;*/
    }
}

void Set10Girl30sTiaoShenScore()
{
    std::deque<int>d;
    for (int i = 0; i < 20; i++)
    {
        int score = rand() % 13 + 60;//生成伪随机数 60~72
        d.push_back(score);
    }
    cout << "一年级女生跳shen成绩" << endl;
    for(auto &it : d)
    {
        cout << it << endl;
    }
    /* for(auto it = d.begin(); it != d.end(); it++)
     {
         if(*it >= 119 && *it < 123)
         {
             cout << *it << " " << "70" << endl;
         } else if(*it >= 123 && *it < 127)
         {
             cout << *it << " " << "75" << endl;
         }else if(*it >= 127 && *it < 131)
         {
             cout << *it << " " << "80" << endl;
         }else if(*it >= 131 && *it < 135)
         {
             cout << *it << " " << "85" << endl;
         }else if(*it >= 135 && *it < 139)
         {
             cout << *it << " " << "90" << endl;
         }else if(*it >= 139 && *it < 143)
         {
             cout << *it << " " << "95" << endl;
         }else if(*it >= 143 )
         {
             cout << *it << " " << "100" << endl;
         } */
    cout << "对应的grade" << endl;
    for(int & it : d)
    {
        if(it >= 60 && it < 63)
        {
            cout << "80" << endl;
        } else if(it >= 63 && it < 66)
        {
            cout << "85" << endl;
        }else if(it >= 66 && it < 69)
        {
            cout << "90" << endl;
        }else if(it >= 69 && it < 72)
        {
            cout << "95" << endl;
        }else if(it >= 72 )
        {
            cout << "100" << endl;
        }
//        cout << deq << " ";
    }
    cout << endl;
}
void Set10Boy30sTiaoShenScore() {
    std::deque<int> d;
    cout << "一年级boy跳shen成绩" << endl;
    for (int i = 0; i < 23; i++) {
        int score = rand() % 13 + 55;//生成伪随机数 55,67
        d.push_back(score);
    }
//    cout << endl;*/
    for (auto &it : d) {
        cout << it << endl;
    }
    cout << "对应的grade" << endl;
    for (int &it : d) {
        if(it >= 55 && it < 58)
        {
            cout << "80" << endl;
        } else if(it >= 58 && it < 61)
        {
            cout << "85" << endl;
        }else if(it >= 61 && it < 64)
        {
            cout << "90" << endl;
        }else if(it >= 64 && it < 67)
        {
            cout << "95" << endl;
        }else if(it >= 67 )
        {
            cout << "100" << endl;
        }
//    cout << endl;*/
    }
}

void Set11Girl30sTiaoShenScore()
{
    std::deque<int>d;
    for (int i = 0; i < 20; i++)
    {
        int score = rand() % 13 + 60;//生成伪随机数 60~72
        d.push_back(score);
    }
    cout << "一年级女生跳shen成绩" << endl;
    for(auto &it : d)
    {
        cout << it << endl;
    }
    /* for(auto it = d.begin(); it != d.end(); it++)
     {
         if(*it >= 119 && *it < 123)
         {
             cout << *it << " " << "70" << endl;
         } else if(*it >= 123 && *it < 127)
         {
             cout << *it << " " << "75" << endl;
         }else if(*it >= 127 && *it < 131)
         {
             cout << *it << " " << "80" << endl;
         }else if(*it >= 131 && *it < 135)
         {
             cout << *it << " " << "85" << endl;
         }else if(*it >= 135 && *it < 139)
         {
             cout << *it << " " << "90" << endl;
         }else if(*it >= 139 && *it < 143)
         {
             cout << *it << " " << "95" << endl;
         }else if(*it >= 143 )
         {
             cout << *it << " " << "100" << endl;
         } */
    cout << "对应的grade" << endl;
    for(int & it : d)
    {
        if(it >= 60 && it < 63)
        {
            cout << "80" << endl;
        } else if(it >= 63 && it < 66)
        {
            cout << "85" << endl;
        }else if(it >= 66 && it < 69)
        {
            cout << "90" << endl;
        }else if(it >= 69 && it < 72)
        {
            cout << "95" << endl;
        }else if(it >= 72 )
        {
            cout << "100" << endl;
        }
//        cout << deq << " ";
    }
    cout << endl;
}
void Set11Boy30sTiaoShenScore() {
    std::deque<int> d;
    cout << "一年级boy跳shen成绩" << endl;
    for (int i = 0; i < 24; i++) {
        int score = rand() % 13 + 55;//生成伪随机数 55,67
        d.push_back(score);
    }
//    cout << endl;*/
    for (auto &it : d) {
        cout << it << endl;
    }
    cout << "对应的grade" << endl;
    for (int &it : d) {
        if(it >= 55 && it < 58)
        {
            cout << "80" << endl;
        } else if(it >= 58 && it < 61)
        {
            cout << "85" << endl;
        }else if(it >= 61 && it < 64)
        {
            cout << "90" << endl;
        }else if(it >= 64 && it < 67)
        {
            cout << "95" << endl;
        }else if(it >= 67 )
        {
            cout << "100" << endl;
        }
//    cout << endl;*/
    }
}


int main()
{
    srand((unsigned int)time(nullptr));//随机数种子。使得每次运行结果不一样。
    std::vector<int> v;

//    Set1GirlJumpScore();
//    Set1BoyJumpScore();
//    Set1GirlboyboolAndticaoScore();
//    Set1Girl30sTiaoShenScore();
//    Set1Boy30sTiaoShenScore();

//    Set4Girl30sTiaoShenScore();
//    Set4Boy30sTiaoShenScore();

//Set10Girl30sTiaoShenScore();
//Set10Boy30sTiaoShenScore();

//Set11Girl30sTiaoShenScore();
//Set11Boy30sTiaoShenScore();
cout << "girl" << endl;
default_random_engine e;
    uniform_real_distribution<double> u(6.1, 6.4);
    for(int i = 0; i < 20; ++i)
{
    cout << u(e) << endl;
}
    cout << "boy" << endl;
    default_random_engine en;
    uniform_real_distribution<double> u1(5.9, 6.2);
    for(int i = 0; i < 24; ++i)
    {
        cout << u1(en) << endl;
    }
    return 0;
}