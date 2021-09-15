//函数
/*
#include <iostream>
using namespace std;

//95函数默认参数(某个位置及以后的参数都必须有默认值)1、声明和实现只能一个有默认参数。
int AddFun(int a, int b = 20, int c = 30)
{
    return a + b + c;
}
//96 函数占位参数(也可以带默认参数)
void func(int a, int = 10)
{
    cout << "call func" << endl;
}
//97 函数重载（条件：1、同一个作用域下2、函数名同3、函数参数类型，个数，顺序不同）
void funcOverload()
{
    cout << "call func" << endl;
}
void funcOverload(double a, int b)
{
    cout << "call func(double a, int b)" << endl;
}
void funcOverload(int a)
{
    cout << "call func(int a)" << endl;
}

//98 函数重载注意事项（1、引用作为重载的条件2、碰到默认参数）
void funcRef(int &a)
{
    cout << "call funcRef(int &a)" << endl;
}
void funcRef(const int &a)
{
    cout << "call funcRef(const int &a)" << endl;
}
//2、碰到默认参数
void func2(int a)
{
    cout << "call func2(int a)" << endl;
}

void func2(int a, int b = 10)
{
    cout << "call func2(int a)" << endl;
}

int main()
{
//    p95
    int x = 1;
    int y = 2;
    int z = 3;
    int sum = AddFun(x, y, z);
    cout << "sum= " << sum << endl;

    cout << "use 2 default parameter sum= " << AddFun(10) << endl;
    cout << "overwrite default parameter sum= " << AddFun(10, 11, 12) << endl;
//96
    func(x);
//    97
    funcOverload();
    funcOverload(x);
    funcOverload(3.14, y);
//    98
    funcRef(x);
    funcRef(10);
//    func2(10);  //error


    return 0;
}
*/
//函数模板
/*
#include <iostream>
using namespace std;

template <typename T> void myswap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

int main()
{
    int s = 1;
    int s2 = 2;

    myswap(s, s2);
    cout << s << " " << s2 <<endl;

    long a = 2;
    long b = 3;
    myswap<long>(a, b);
    cout << a << " " << b <<endl;

    string m = "aaa";
    string n = "bbb";
    myswap<string>(m, n);
    cout << m << " " << n <<endl;

//    int x = 1;
//    char y = 2;
//    myswap(x, y);//类型不匹配error
//    cout << m << " " << n <<endl;

    return 0;
}
 */
//class object 1、封装（属性和行为、权限控制）2、继承 3、多态
/*
#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14;

class Circle
{
public:
    int m_r;
//    double
    double CalculateZhouChang()
    {
        return 2 * PI * m_r;
    }
};
class Student
{
public:
    void ShowStudent()
    {
        cout << "name: " << stu_name << "  ID: "<< stu_id << endl;
    }

    void AccessInClass()
    {
        stu_name = "sam";
        m_car = "lex";
        m_password = 1234;
    }
public:
    string stu_name;
    int stu_id;
protected:
    string m_car;
private:
    int m_password;
};
class Cube
{
public:
    void SetData(int len, int wid, int height)
    {
        m_L = len;
        m_W = wid;
        m_H = height;
    }
    int GetLength()
    {
        return m_L;
    }
    int GetWidth()
    {
        return m_W;
    }
    int GetHeight()
    {
        return m_H;
    }
    int GetArea()
    {
        return 2 * (m_L * m_H + m_L * m_W + m_H * m_W);
    }
    int GetVolume()
    {
        return m_W * m_H * m_L;
    }
    bool IsSameInClass(Cube &c)
    {
        return m_L == c.GetLength() && m_H == c.GetHeight() && m_W == c.GetWidth();
    }
private:
    int m_L;
    int m_W;
    int m_H;

};

bool IsSameCube(Cube &c1, Cube &c2)
{
    return c1.GetLength() == c2.GetLength() && c1.GetWidth() == c2.GetWidth() && c1.GetHeight() == c2.GetHeight();
}

int main()
{
    //Instance  实例化，由类创建一个对象
    Circle cir1{};
    cir1.m_r = 10;
    cout << "zhouchang= " << cir1.CalculateZhouChang() <<endl;

    Student s1;
    s1.stu_name = "Tom";
    s1.stu_id = 118;
    s1.ShowStudent();

    Student stu2;
    stu2.stu_name = "bob";
//    stu2.m_car = "benchi"; //cannot access
    s1.ShowStudent();

    Cube c1{};
    c1.SetData(10, 10, 10);
    cout << "area: " << c1.GetArea() << endl;
    cout << "volume: " << c1.GetVolume() << endl;
    Cube c2;
    c2.SetData(10, 20,10);
    bool ret = IsSameCube(c1,c2);
    if(ret)
    {
        cout << "same cube" << endl;
    }else{
        cout << "not same" << endl;
    }
    bool ret2 = c1.IsSameInClass(c2);
    if(ret2)
    {
        cout << "m_fun same cube" << endl;
    }else{
        cout << "m_fun not same" << endl;
    }
    return 0;
}
 */
//构造函数的分类和调用。有参构造和无参数默认构造；普通构造和拷贝构造。调用1、括号法2、显示法3、隐式转换法
/*
#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "call Person default constructor fun " << endl;
    }
    explicit Person(int a)
    {
        age = a;
        cout << "call Person constructor fun " << endl;
    }
//    拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        cout << "copy constructor " << endl;
    }

    ~Person()
    {
        cout << "call Person destructor fun " << endl;
    }

//private:
    int age;
};

void CallConstruc()
{
//    括号法
    Person p;    //default. 注意：不加（）
    Person p2(10); //有参数
    Person p3(p2); //copy

//    cout << "p2 age: " << p2.age << endl;
//    cout << "p3 age: " << p3.age << endl;
//    显示法
    Person p4;    //default
    Person p5 = Person(10); //有参数
    Person p6 = Person(p2); //copy
//    Person(10) 是创建的匿名对象。特点：当前行执行万后，系统立即回收掉匿名对象
//注意2、不要利用拷贝构造函数初始化匿名对象。因为编译器会认为Person(p3) == Person p3;redecl
//    Person(p3);

//    隐士转换法
//    Person p7 = 10;
//    Person p8 = p4;
}

int main()
{
    CallConstruc();
    return 0;
}
*/

//this 1、当形参和数据成员同名时，区分 2、非静态成员函数返回对象本身return *this
/*
#include <iostream>
#include <string>
using namespace std;


class Student
{
public:
    Student(string name, int age): m_name(std::move(name)), n_age(age){};
    ~Student() = default;
    void ShowAge()
    {

        cout << "this: "<< this <<endl;
        cout << "age via this: "<< this->n_age <<endl;
        cout << "name via this: "<< this->m_name <<endl;
    }

public:
    string m_name;
    int n_age;
};


int main()
{
    Student Mike("Mike", 18);  //init
    Student Bob("Bob", 20);   //init

//    Mike.n_age = 22;
//    Mike.m_name = "sss";  //modify
    cout << "memory addr. of object Mike: " << &Mike << endl;
    Mike.ShowAge();
    cout << "memory addr. of object Bob: " << &Bob << endl;
    Bob.ShowAge();
    return 0;
}
*/

//内存的开辟，类型占用的大小字节
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 10;  //占用4字节Byte
    int b = 22;
    char c = 'a';

    cout << "addr. a: " << &a ;
    cout << "int字节数" << sizeof(a) << endl;
    cout << "addr. b: " << &b << endl;
    cout << "char字节数" << sizeof(char) << endl;
    cout << "addr. c: " << &c << endl;
    printf("char c address: %p\n", &c);

    return 0;
}
*/
//lambda f = [catpured= & this](函数参数列表)mutable throw(类型) ->返回值类型 {函数语句};
/*#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 1;
    int y = 1;
    int z;
    cout << "初始x: " << x << " 初始y: " << y <<endl;

    cout << "&变量以引用传递的方式被捕获" << endl;
    z = [&x, &y] () mutable -> int { int n = x + y;
    ++x;
    ++y;
    cout << "xneibu=" << x << " yneibu=" << y <<endl;
    return n;
    }();
    cout << "xwaibu=" << x << " y-waibu=" << y <<endl;
    cout << "z=" << z <<endl;

    cout << "初始x: " << x << " 初始y: " << y <<endl;
    cout << "=变量以值传递的方式被捕获" << endl;
    z = [=] () mutable -> int { int n = x + y;
    ++x;
    ++y;
    cout << "xneibu=" << x << " yneibu=" << y <<endl;
    return n;
    }();
    cout << "xwaibu=" << x << " y-waibu=" << y <<endl;
    cout << "z=" << z <<endl;


    return 0;
}//mutable 在lambda内部改变值，这种改变不能传递到外部

*/

// bind example
/*
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
/*
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

 */

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
    classA() = default;
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
//         cA.registCb([this](int i){classB::handle(i);});      //lambda
//         same as follows
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

//**************std::shared_ptr<>
/*
  // shared_ptr::get() example
#include <iostream>
#include <memory>
#include <string>
void output(std::string msg, int const* pInt)
{
    std::cout << msg << *pInt << " in " << pInt << "\n";
}

int main()
{
    int* pInt = new int(42);
    std::shared_ptr<int> pShared = std::make_shared<int>(42);

    output("Naked pointer ", pInt);//裸指针
//     output("Shared pointer ", pShared); // compiler error
    output("Shared pointer with get() ", pShared.get());

    delete pInt;
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

//引用  数据类型 &别名 = 原名.  本质：操作同一块内存. ==指针常量
/*
#include <iostream>
using namespace std;

//swap func  值传递：！！！形参不会修饰实参
void MySwapzhi(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
//形参会修饰实参
void MySwapPoint(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//形参会修饰实参
void MySwapUseyinyong(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//    p92 引用做函数返回值（1、不要返回局部变量的引用 2、函数的调用可以作为左值）
//int& test01()
//{
//    int a = 10;//in satck在该函数执行完后 内存就释放掉了
//    return a;
//}
//2、函数的调用可以作为左值）
int& test02()
{
    static int a = 20;//a是静态变量，存放在全局区，全局去的数据在程序结束后系统释放
    return a;
}

//p94
void ShowValueNotModify(const int &val)
{
//    val = 3000;
    cout << "val = " << val << endl;
}
int main()
{
//    p89
    int a = 10;
    int c = 20;
    int &b = a;

    cout << "addr. a=" << &a << "   a=" << a << endl;
    cout << "addr. b=" << &b << "   b=" << b << endl;

    b = 100;//通过引用修改原变量
    cout << "addr. a=" << &a << "   a=" << a << endl;
    cout << "addr. b=" << &b << "   b=" << b << endl;
//    p90 引用必须初始化； 之后不可改变。本质是类似于指针常量，指向不可改变
//    p91 引用做函数参数（让形参修饰实参，可以简化指针修改实参）
    cout << "值传递" << endl;
    cout << "origin a " << a << "  origin c= " << c << endl;
    MySwapzhi(a, c);
    cout << "a " << a << "  c= " << c << "!!!swap failed" << endl;

    cout << "地址传递" << endl;
    cout << "origin a " << a << "  origin c= " << c << endl;
    MySwapPoint(&a, &c);
    cout << "a " << a << "  c= " << c << "swap success" << endl;

    cout << "引用传递" << endl;
    cout << "origin a " << a << "  origin c= " << c << endl;
    MySwapUseyinyong(a, c);
    cout << "a " << a << "  c= " << c << "swap success" << endl;

//    p92 引用做函数返回值（1、不要返回局部变量的引用 2、函数的调用可以作为左值）
//    int &ref = test01();
//    cout << "ref= " << ref << endl;
//    cout << "ref= " << ref << endl;
         int &ref2 = test02();
    cout << "ref2= " << ref2 << endl;
    cout << "ref2= " << ref2 << endl;
//    2、函数的调用可以作为左值
    test02() = 1000;

    cout << "ref2= " << ref2 << endl;
    cout << "ref2= " << ref2 << endl;

//    p93引用的本质：是一个指针常量。也就是为什么引用不可更改
    int &refer = a;//== int * const refer = &a;
//    p94 常量引用：用来修饰形参，防止误操作改变数据。相当于常量指针。
    const int & ref = 10;//引用必须引一块合法的内存空间
//    use const ==
//    int temp = 10; const int & ref = temp;
    ShowValueNotModify(a);

    return 0;
}
*/
//8.5 cubes.cpp  函数的形参尽可能只用常引用（理由：1、防修改数据2、接受const和非const实参3、临时变量）
/*
#include <iostream>
using namespace std;

double cube(double a)
{
    a *= a * a;
    return a;
}

double RefCube(double &ra)
{
    ra *= ra * ra;
    return ra;
}

//double RefCube1(const double &ra)
//{
//    ra *= ra * ra;   //ra  x 不允许被修改
//    return ra;
//}
//
 double RefCube2(const double &ra)
{
    return ra * ra * ra;
}

void Swapr(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    double x = 3.0;
    cout << cube(x) ;
    cout << " = cube of " << x << endl;
    cout << RefCube(x) ;
    cout << " = cube of " << x << "   x==ra, x changed"<< endl;

    long m = 3;
    long n = 5;
//    Swapr(m, n);

    return 0;
}


//TODO: 右值引用。实现移动语义
 */
//8.6 structref.cpp  2、为何返回引用？--》避免了将结构或对象复制到一个临时的位置，节省时间和内存。3、不要返回局部变量的引用。4、将const用于引用返回类型:防止赋值等修改数据操作
/*
#include <iostream>
#include <string>
using namespace std;

struct free_throws
{
    std::string name;
    int made;
    float attempts;
    float percent;
};

void Display(const free_throws & ft)
{
    cout << "Name: " << ft.name << '\n';
    cout << "Made: " << ft.made << '\t';
    cout << "Attempt: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;

}

free_throws & accumulate(free_throws &target, const free_throws &source)   //来源数据不能被改变，用const修饰
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return  target;//返回引用
}

int main()
{
    free_throws one = {"IB", 13, 14};
    free_throws two = {"AK", 10, 16};
    free_throws three = {"MM", 7, 9};
    free_throws four = {"ML", 5, 9};
    free_throws five = {"LL", 6, 14};
    free_throws team = {"ThrowGoods", 0 , 0};

    free_throws dup;

    set_pc(one);
    Display(one);
    accumulate(team, one);
    Display(team);

    Display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    Display(team);

    dup = accumulate(team, five);

    cout << "Displaying team: \n";
    Display(team);

    cout << "displaying duq after assignment:\n";
    Display(dup);
    set_pc(four);

    //ill-advised assigment  病态的分配
    accumulate(dup, five) = four;
    cout << "displaying duq after ill-advised assigment" << endl;
    Display(dup);

    return 0;
}
*/
//8.7 strquote.cpp 引用用于类对象。1、函数形参多用引用传入对象本体，高效，加const表示不可修改传入对象的数据 2、实参形参类型不匹配：程序创建正确的临时变量，用转换后的实参值初始化临时量，然后传递一个指向该变量的引用
/*#include <iostream>
#include <string>
using namespace std;

std::string version1(const string & s1, const string & s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

const string & version2HasSideEffe(string & s1, const string & s2)
{
    s1 = s2 + s1 + s2;
    return s1;    //s1不是临时变量，将s1作为引用返回是安全的。
}

const string & version3Bad(string & s1, const string & s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;     //不能返回局部变量的引用！！！
}

int main()
{
    string input;
    string copy;
    string result;

    cout << "enter a string: " ;
    getline(cin, input);
    copy = input;
    cout << "your str as entered: " << input << endl;
    result = version1(input, "***");
    cout << "your str enhanced: " << result << endl;
    cout << "original str: " << input << endl;

    result = version2HasSideEffe(input, "###");  //引用传入，则直接修改的是input本身， string & s1 = input  s1是input的引用。 s1和input操作同一块内存
    cout << "your str enhanced: " << result << endl;
    cout << "original str: " << input << endl;

//    cout << "resetting original str\n";
//    input = copy;
////    result = version3Bad(input, "@@@");      //调用函数结束，临时变量temp内存被释放。 程序试图引用已经释放的内存空间，崩溃！！！
//    cout << "your str enhanced: " << result << endl;
//    cout << "original str: " << input << endl;

    return 0;
}
 */
//8.8 filefunc,cpp 对象、继承和引用 1、函数的一个形参定义为基类引用类型，调用该函数时，实参可以为基类对象也可以是派生类对象。因为继承的一个特性： 基类引用可以指向派生类对象，而无需进行强制类型转换。
/*
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
const int LIMIT = 5;

void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed);//
    os.precision(0);
    os << "focal length of objective: " << fo << "mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.1 eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for(int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial); //restore
}

int main()
{
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "enter the focal length of your"
            "telescope objective in mm";
    cin >> objective;
    double eps[LIMIT];
    cout << "enter the focal length, in mm, of " << LIMIT
        <<" eyepiece:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i+1 << ":";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";
    return 0;
}
 */
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




//程序的内存模型：代码区、全局区（全局变量、静态变量、常量--字符串常量，const全局变量）； 栈区（局部变量，不要返回局部变量的地址！！！）、堆区
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
/*
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
}

void Set1BoyJumpScore() {
    std::deque<int> d;
    cout << "一年级boy跳远成绩" << endl;
    for (int i = 0; i < 23; i++) {
        int score = rand() % 25 + 129;//生成伪随机数 129  153
        d.push_back(score);
    }


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
//    cout << endl;
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
//    cout << endl;
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
//    cout << endl
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
//    cout << endl;
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
//    cout << endl;
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
//    cout << endl;
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
//    cout << endl;
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
//    cout << endl;
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
*/

//********C++17*****optional，C++ 的函数如何返回多个值？

/*

#include <iostream>
//TODO:add c++17
//#include <optional>

using namespace std;

struct Out {
    string out1 { "" };
    string out2 { "" };
};

boost::optional<Out> func(const string& in) {
    Out o;
    if (in.size() == 0)
        return nullopt;
    o.out1 = "hello";
    o.out2 = "world";
    return { o };
}

int main() {
    if (auto ret = func("hi"); ret.has_value()) {
        cout << ret->out1 << endl;
        cout << ret->out2 << endl;
    }
    return 0;
}
 */

//*********sweeper
/*
#include <iostream>
#include <functional>
#include <memory>
using namespace std;

class Chassis
{

};

class Hsm
{
public:
    // 状态机事件参数基类
    struct StateArgs
    {
    };
    typedef enum _Event
    {
        kEvt_None = 0,
        kEvt_Init,        // 初始化检查，失败则使用备用转移
        kEvt_Entry,       // 初始化
        kEvt_Exit,        // 离开
        kEvt_Update,      // 定期刷新状态
        kEvt_Suspend,     // 状态机挂起/暂停
        kEvt_Resume,      // 状态机从挂起恢复
        kEvt_Cmd,         // 模式切换/手动控制指令
        kEvt_Collide,     // 不可通行边界，包含碰撞、断崖、磁条虚拟墙
        kEvt_NearDock,    // 充电座附近，检测到充电座信号
        kEvt_IrCollide,   // 红外障碍检测
        kEvt_OutofFence,  // 地图围栏触碰
        kEvt_Closing,     // 接近障碍物减速
        kEvt_IrBeacon,    // 充电座发射的红外信标
        kEvt_AttachPlug,  // 充电口被插入
        kEvt_AttachDock,  // 接触到充电座
        kEvt_Malfunction, // 故障信息更新
        kEvt_Slipping,    // 底盘打滑
        kEvt_Stall,       // 被困
        kEvt_GoHome,      // 回充电座请求
        kEvt_ToIdle,      // 等待时间过长切换到idle模式省电
        kEvt_Wait,        // 需要停车等待其他外部模块
        kEvt_AttachDustDisposal,    //触发集尘
        kEvt_WheelSuspend // 轮子微动开关触发
    } Event;
    typedef std::function<Event(Event, const StateArgs *)> EvtHandler;
public:
    Hsm(std::string name, Chassis *chassis)
            : root_(nullptr)
            , cur_state_(nullptr)
            , is_suspended_(true)
            , hsm_tran_(0)
            , name_(std::move(name))
            , cha_(chassis)
            , cur_evt_(kEvt_None)
            , pending_emergency_()
            , action_stk_()
            , pending_stk_(){};
    ~Hsm() = default;

    // HSM按帧运行
    virtual void Tick();

protected:
    class State
    {
    public:
        State() = delete;
        // 根节点专用构造函数
        State(Hsm::EvtHandler handler, std::string name)
                : name_(std::move(name)), handler_(std::move(handler)), level_(0), parent_(nullptr)
        {
            need_notify_cur_action_ = []() { return true; };
        };
        // 一般节点构造函数
        State(Hsm::EvtHandler handler, State *parent, std::string name)
                : name_(std::move(name)), handler_(std::move(handler)), level_(0), parent_(parent)
        {
            SetLevel(parent_->GetLevel() + 1);
            need_notify_cur_action_ = []() { return true; };
        }
        ~State() = default;

        // 获取父节点指针
        State *GetParent() const { return parent_; }
        // 获取节点的深度
        uint8_t GetLevel() const { return level_; }
        // 设置父节点指针
        void SetParent(State *parent) { parent_ = parent; }
        // 设置节点的深度
        void SetLevel(uint8_t new_level)
        {
            level_ = new_level;
            if (level_ >= HSM_MAX_DEPTH) {
                ctrl_loge("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                ctrl_loge("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                ctrl_loge("level_ larger than HSM_MAX_DEPTH: {}", level_);
                ctrl_loge("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                ctrl_loge("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                level_ = HSM_MAX_DEPTH;
            }
        }

        // 设定这个状态的最后一个动作，一般它完成后表示一个动作循环完成
        void SetFinalAction(const ActPtr &action) { final_action_ = action; }
        // 增加一个动作附属于这个状态，便于离开该状态时统一退出所有属于它的动作请求
        void AddAction(const ActPtr &action) { all_actions_.push_back(action); }
        // 检查给这个状态设定的最后一个动作，是否已经退出，但不调用终止条件判断
        bool GetFinalActionHasExit() const
        {
            if (!final_action_)
                return true;
            return final_action_->HasExit();
        }

        // 退出states的时候，约定取消所有属于它的动作
        void CancelAllAction()
        {
            for (auto &action : all_actions_)
                if (action)
                    action->Cancel();
            all_actions_.clear();
        }

        const std::string name_;
        Hsm::EvtHandler   handler_;
        std::function<bool()> need_notify_cur_action_;

    protected:
        uint8_t    level_;
        State *    parent_;
        ActPtr              final_action_; // 状态设定的最后一个动作
        std::vector<ActPtr> all_actions_;  // 在这个状态时添加的所有动作
    };
};
// 25ms执行一次
void Hsm::Tick()
{
    // 状态机输入信号获取
    std::shared_ptr<StateArgs> evt_args = nullptr;
    cur_evt_ = FetchEvt(evt_args);// return kEvt_Cmd;

    // 更新动作状态，便于接下来HSM内读取
    PopCompletedAction();

    // 内部只能调用SetSuspend()
    Run(cur_evt_, evt_args.get());

    // 状态机挂起不执行后续
    if (GetSuspend())
        return;

    // 模式内进度检查
    if (cur_evt_ != kEvt_Update)
        Run(kEvt_Update, nullptr);

    PopCompletedAction();
    NotifyCurAction();
    FlushPendingAction();
    ExecAction();
    PopCompletedAction();
    FlushPendingAction();
}

class BvHsm : public Hsm, public BASE_ENUM
{
public:


};

class DockHsm : public BvHsm
{
    typedef enum _Mode
    {

    }Mode;

    struct DockArgs : Hsm::StateArgs{};

    struct RecoveryArgs : Hsm::StateArgs{};
    //construct func
    DockHsm(const std::string &name, Chassis *chassis);
};



//运行过程：以回充为例
//app:cmd回充
//获取最新的指令 ，得到设备控制枚举类别。判断是new_cmd-->is_cmd_need_handle = true-->\\
    return kEvt_Cmd  得到当前事件
    run(控制命令事件kEvt_Cmd){
        event = state->handler_(event, param);//事件处理程序回调
    }

Hsm::Event SweeperHsm::DefaultHandler(Event event, const StateArgs *args)
{
    switch (event) {
        case kEvt_Init: {
            // 跳转到默认子状态
            Tran(idle_s_, args, nullptr);
            event = kEvt_None;
            break;
        }
        case kEvt_Cmd:
            if (HandleCmd(((CmdArgs *)args)->cmd))
                event = kEvt_None;
            break;

bool BvHsm::is_cmd_need_handle(std::shared_ptr<StateArgs> &param)
{
    if (disable_ctrl_cmd_ && !GetSuspend())
        return false;


    auto cmd_info = cha_->GetLatestCmd("hsm");
    const auto &new_cmd = cmd_info.cmd;
}
Run(kEvt_Cmd, evt_args.get());//控制命令事件



void BvHsm::Tick()
{

    Hsm::Tick();
}

// 底盘状态变化 > 报警状态 > 控制指令 > 暂停 > 碰撞处理 > 打滑 >
// 低电量请求回充 > 停车等待SLAM计算定位 > 没有意外更新当前状态
//std::shared_ptr<StateArgs> evt_args = nullptr; FetchEvt(evt_args);
Hsm::Event BvHsm::FetchEvt(std::shared_ptr<StateArgs> &param)
{
    // 3. 控制指令
    if (is_cmd_need_handle(param))
        return kEvt_Cmd;
}//得到当前事件kEvt_Cmd
bool BvHsm::is_cmd_need_handle(std::shared_ptr<StateArgs> &param)
{}

Run(cur_evt_, evt_args.get());//Run(kEvt_Cmd, evt_args.get());
void Hsm::Run(Event event, StateArgs *param)




//获取当前状态
State *GetState() const override { return root_hsm_->cur_state_; }
//判断两状态为同一状态
if (!IsStateAInStateB(GetState(), dock_s_))

//    Qusetion
//???绑定构造函数  作为参数传入void BvHsm::Tran(State *next_state, const StateArgs *param, const std::function<bool()>& hook) ？？？
auto towork_hook = std::bind(&SweeperHsm::PrepareToWork, this, GetState(), _1);
Tran(fold_s_, param.get(), std::bind(towork_hook, fold_s_));


Run(kEvt_Cmd, evt_args.get());//控制命令事件
void Hsm::Run(Event event, StateArgs *param)
{
    // This runs the state's event handler and forwards unhandled events to the parent state
    State *state = cur_state_;
    while (event && state) {
        //ctrl_logi("run [{}](evt:{})\r", state->name_, Evt2Str(event));

//        typedef std::function<Event(Event, const StateArgs *)> EvtHandler;
//       Hsm::EvtHandler   handler_;回调函数，调用相对应的事件处理函数
        event = state->handler_(event, param);//？？？
//        回到根状态
        state = state->GetParent();
    }
}

*/