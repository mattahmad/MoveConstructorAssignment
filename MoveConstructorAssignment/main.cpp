#include <iostream>
#include <string>
using namespace std;

class Example {
        string* ptr;
    public:
    Example (const string& str) : ptr(new string(str)) {}
    ~Example () {delete ptr;}
    Example (Example&& x) : ptr(x.ptr) {x.ptr=nullptr;}
    Example& operator= (Example&& x) {
        delete ptr;
        ptr = x.ptr;
        x.ptr=nullptr;
        return *this;
    }
    const string& content() const {return *ptr;}
    Example operator+(const Example& rhs){
        return Example(content()+rhs.content());
    }
};

int main(int argc, const char * argv[]) {

    Example foo ("Exam");
    Example bar = Example("ple");
    
    foo = foo + bar;
    
    cout << "foo's content: " << foo.content() << '\n';
    return 0;
}
