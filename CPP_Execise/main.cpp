
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

///*     ActMove(const std::string &name, Chassis *chassis, const ActionArgs *arg);
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


/*
//STL
//****************vector************
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
//**********************string*************8
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

int main()
{
//    test01();
    test02();
    return 0;
}