#include <bits/stdc++.h>

template <typename T> 
T myMax(T x, T y) 
{ 
   return (x > y)? x: y; 
} 


template <typename T> 
class Array { 
private: 
    T *ptr; 
    int size; 
public: 
    Array(T arr[], int s); 
    void print(); 
}; 
  
template <typename T> 
Array<T>::Array(T arr[], int s) { 
    ptr = new T[s]; 
    size = s; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 
  
template <typename T> 
void Array<T>::print() { 
    for (int i = 0; i < size; i++) 
        std::cout<<" "<<*(ptr + i); 
    std::cout<<std::endl; 
} 


template <class T, int max> 
int arrMin(T arr[], int n) 
{ 
   int m = max; 
   for (int i = 0; i < n; i++) 
      if (arr[i] < m) 
         m = arr[i]; 
   
   return m; 
} 


void printDistinctSubStrs(std::string str) 
{ 
    std::map<std::pair<char,char>, int> dPairs; 
  
    for (int i=0; i<str.size()-1; i++) 
        dPairs[std::make_pair(str[i], str[i+1])]++; 
  
    std::cout << "Distinct sub-strings with counts:\n"; 
    for (auto it=dPairs.begin(); it!=dPairs.end(); it++) 
        std::cout << it->first.first << it->first.second 
             << "-" << it->second << " "; 
} 

inline int cube(int s) 
{ 
    return s*s*s; 
} 

std::tuple<int, int, char> foo(int n1, int n2) 
{ 
    return std::make_tuple(n2, n1, 'a');              
} 
  
std::pair<int, int> foo1(int num1, int num2) 
{ 
    return std::make_pair(num2, num1);             
} 

int increment(int x) {  return (x+1); } 


class Test { 
    int value; 
public: 
    Test(int v = 0) {value = v;} 
      
    int getValue() const {return value;}   
}; 


namespace ns1 
{ 
    int value()    { return 5; } 
} 
namespace ns2  
{ 
    const double x = 100; 
    double value() {  return 2*x; } 
} 


class SmartPtr { 
    int* ptr; // Actual pointer 
public: 
    
    explicit SmartPtr(int* p = NULL) { ptr = p; } 
  
    // Destructor 
    ~SmartPtr() { delete (ptr); } 
  
    int& operator*() { return *ptr; } 
}; 

void sorting(int b[], int n) 
{ 
    int i, c = 0; 
    for (i = 0; i < n; i++) { 
        if (b[i] % 2 == 0) { 
            c++; 
        } 
    } 
    std::cout << "The total even numbers are:  " << c << std::endl; 
    std::cout << "original array :"<< " "; 
    std::cout << "\n"; 
    for (i = 0; i < 10; i++) { 
        std::cout << b[i] << " "; 
    } 
    std::cout << "\n"; 
    std::pair<int*, ptrdiff_t> p = std::get_temporary_buffer<int>(10); 
    std::uninitialized_copy(b, b + p.second, p.first); 
    std::sort(p.first, p.first + p.second); 
    std::cout << "sorted array :" << std::endl; 
    for (i = 0; i < p.second; i++) { 
        std::cout << p.first[i] << " "; 
    } 
    std::cout<<"\n";
} 




class Complex { 
private: 
    int real, imag; 
public: 
    Complex(int r = 0, int i =0)  {real = r;   imag = i;} 
      
    Complex operator + (Complex const &obj) { 
         Complex res; 
         res.real = real + obj.real; 
         res.imag = imag + obj.imag; 
         return res; 
    } 
    void print() { std::cout << real << " + i" << imag << std::endl; } 
};

namespace ns 
{ 
    
    class geek; 
} 
   
class ns::geek 
{ 
public: 
    void display() 
    { 
        std::cout << "ns::geek::display()\n"; 
    } 
}; 


class A 
{ 
public: 
  A()  { std::cout << "A's constructor called" << std::endl; } 
}; 
  
class B 
{ 
public: 
  B()  { std::cout << "B's constructor called" << std::endl; } 
}; 
  
class C: public B, public A  // Note the order 
{ 
public: 
  C()  { std::cout << "C's constructor called" << std::endl; } 
}; 




int main() {

    std::vector<int> vect =  {10,20,30};
    for(int &i:vect){
        std::cout<<i<<std::endl;
    }

    std::set<std::string> st; 
    st.insert({ "geeks", "for", "geeks", "org" }); 
    for(auto it = st.begin(); it != st.end(); it++){
        std::cout<< *it<<std::endl;
    }

    std::cout << myMax<int>(3, 7) << std::endl;  
    std::cout << myMax<double>(3.0, 7.0) << std::endl;  
    std::cout << myMax<char>('g', 'e') << std::endl; 


    int arr[5] = {1, 2, 3, 4, 5}; 
    Array<int> a(arr, 5); 
    a.print();


    int arr1[]  = {10, 20, 15, 12}; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]); 
    char arr2[] = {1, 2, 3}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    std::cout << arrMin<int, 10000>(arr1, n1) << std::endl; 
    std::cout << arrMin<char, 256>(arr2, n2) <<std::endl;  


    std::fstream file; 
    file.open("res/cout.txt", std::ios::out); 
    std::string line; 
    std::streambuf* stream_buffer_cout = std::cout.rdbuf(); 
    std::streambuf* stream_buffer_cin = std::cin.rdbuf();
    std::streambuf* stream_buffer_file = file.rdbuf();
    std::cout.rdbuf(stream_buffer_file); 
    std::cout << "This line written to file" << std::endl; 
    std::cout.rdbuf(stream_buffer_cout); 
    std::cout << "This line is written to screen" << std::endl; 
    file.close(); 


    std::string str = "abcacdcacabacaassddssklac"; 
    printDistinctSubStrs(str); 
    std::cout << "\nThe cube of 3 is: " << cube(3) << "\n";  
    
    int a1,b1; 
    char cc;       
    std::tie(a1, b1, cc) = foo(5, 10);             
    std::pair<int, int> p = foo1(5,2);   
    std::cout << "Values returned by tuple: "; 
    std::cout << a1 << " " << b1 << " " << cc << std::endl; 
    std::cout << "Values returned by Pair: "; 
    std::cout << p.first << " " << p.second << std::endl; 


    int arr5[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr5)/sizeof(arr5[0]); 
    std::transform(arr5, arr5+n, arr5, increment); 
    for (int i=0; i<n; i++) 
        std::cout << arr5[i] <<" "; 
    std::cout<<" "<<std::endl;

    Test t(20); 
    std::cout<<t.getValue(); 


    std::cout << ns1::value() << '\n';  
    std::cout << ns2::value() << '\n';  
    std::cout << ns2::x << '\n';  

    SmartPtr ptr(new int()); 
    *ptr = 20; 
    std::cout << *ptr;  

    int b[] = { 8, 9, 2, 1, 10, 14, 37, 18, 17, 5 }; 
    int ns = sizeof(b) / sizeof(b[0]); 
    sorting(b, ns); 

    Complex c1(10, 5), c2(2, 4); 
    Complex c3 = c1 + c2; // An example call to "operator+" 
    c3.print(); 


    int x = -1; 
    std::cout << "Before try \n"; 
    try { 
      std::cout << "Inside try \n"; 
      if (x < 0) 
      { 
         throw x; 
         std::cout << "After throw (Never executed) \n"; 
      } 
    } 
    catch (int x ) { 
      std::cout << "Exception Caught \n"; 
    }     
  
    std::cout << "After catch (Will be executed) \n";


    ns::geek obj; 
    obj.display();  

    std::pair <int, char> PAIR1 ; 
    PAIR1.first = 100; 
    PAIR1.second = 'G' ; 
    std::cout << PAIR1.first << " " ; 
    std::cout << PAIR1.second << std::endl ; 


    std::pair <std::string, double> PAIR3 = std::make_pair ("GeeksForGeeks is Best",4.56); 


    std::vector<int> g1; 
  
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    std::cout << "Output of begin and end: "; 
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        std::cout << *i << " "; 

    

    std::vector< std::pair <int,int> > vecti;
    int arrs[] = {5, 20, 10, 40 };
    int arrs1[] = {30, 60, 20, 50};
    int ns1 = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<ns1; i++)
        vecti.push_back(std::make_pair(arrs[i],arrs1[i]) );
 
    std::cout << "The vector before applying sort is:\n" ;
    for (int i=0; i<ns1; i++)
    {
        std::cout << vecti[i].first << " "<< vecti[i].second << std::endl; 
    }
    sort(vecti.rbegin(), vecti.rend());
    std::cout << "The vector after applying sort is:\n" ;
    for (int i=0; i<ns1; i++)
    {
        std::cout << vecti[i].first << " "<< vecti[i].second << std::endl;
    }


    std::list<int> gqlist; 
    std::list<int>::iterator it= gqlist.begin(); 
    for (int i=1; i<=5; i++) 
    gqlist.emplace_back(i); 
    std::cout << "List after emplace_back operation is : "; 
    for (int &x : gqlist) 
        std::cout << x << " "; 
    std::cout << std::endl; 
    for (int i=10; i<=50; i+=10) 
        gqlist.emplace_front(i); 
    std::cout << "List after emplace_front operation is : "; 
    for (int &x : gqlist) 
        std::cout << x << " "; 
    std::cout << std::endl; 
    std::advance(it,2); 
    gqlist.emplace(it,100); 
    std::cout << "List after emplace operation is : "; 
    for (int &x : gqlist) 
        std::cout << x << " "; 
    std::cout << std::endl; 

    std::forward_list<int> flist1; 
    std::forward_list<int> flist2; 
    flist1.assign({1, 2, 3}); 
    flist2.assign(5, 10); 
    std::cout << "The elements of first forward list are : "; 
    for (int&a : flist1) 
        std::cout << a << " "; 
    std::cout << std::endl;       
    std::cout << "The elements of second forward list are : "; 
    for (int&b : flist2) 
        std::cout << b << " "; 
    std::cout << std::endl; 

    std::string as = "GeeksForGeeks"; 
  
    std::regex bs("(Geek)(.*)"); // Geeks followed by any character 
  
    if ( std::regex_match(as, bs) ) 
        std::cout << "String 'a' matches regular expression 'b' \n"; 
  
    if ( std::regex_match(as.begin(), as.end(), bs) ) 
        std::cout << "String 'a' matches with regular expression "
                "'b' in the range from 0 to string end\n";

    C c; 


     


    return 0;
}