#include <iostream>
using namespace std;

void myFunction() {
    cout<<"I just got executed"<<endl;
}

void swap(int &x, int &y) {
    int z = x;
    x = y;
    y = z;
}

int main() {
    int x = 10;
    int y = 20;
    swap(x, y);

    cout<<x<<endl;
    cout<<y<<endl;


        // references
    int a=10;
    const int &b=a+2;
    int c;
    int *f = &c;

    // cout<<&a<<endl;
    // cout<<&b<<endl;
    // cout<<&c<<endl;
    // cout<<a<<endl;
    // cout<<b<<endl;
    // cout<<f<<endl;
    // cout<<*f<<endl;
    // cout<<c<<endl;
    
    return 0;
}