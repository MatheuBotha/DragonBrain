#include <iostream>

using namespace std;

int main() {
    double *h;

    h=new double[2];

    h[0]=1;
    h[1]=2;

    cout << "Hello, PSO World!" << h[1]<<endl;

    delete h;

    h=new double[2];

    h[0]=2;
    h[1]=1;

    cout << "Hello, PSO World!" << h[1]<<endl;

    delete h;


    return 0;
}