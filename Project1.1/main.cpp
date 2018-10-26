#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int iter_factorial(int n)
{
    int ret = 1;
    for(int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

double c(double x, int n) {
    
    double temp = 0;
    
    for(int i = 0; i < n; i++) {
        temp += pow(-1,i)*pow(x,(2*i))/iter_factorial(2*i);
    }
    
    return temp;
}

double e(double x, int n) {
    double temp = 0;
    
    for(int i = 0; i < n; i++) {
        temp += pow(-1,i)*pow(x,(i))/iter_factorial(i);
        
    }
    
    return temp;
}

double s(double x, int n) {
    double temp = 0;
    double p = 1;
    
    for(int i = 1; i <= n; i++) {
        temp += pow(-1,i+1) * pow(x,(p)) / iter_factorial(p);
        p = p+2;
    }
    
    return temp;
}

int main() {
    
    double x = 0.008;
    
    double result = (cos(x)-exp(-x))/sin(x);
    
    double w;
    
    int i = 0;
    do {
        i++;
        w = (c(x,i)-e(x,i))/s(x,i);
        
        cout << i << " round: ";
        cout << " w= ";
        printf("%.10lf", w);
        cout << ", result: ";
        printf("%.10lf\n", result);
        
    } while(abs(w-result) >= pow(10.0,-10.0) && i < 20);
    
    cout << i << " terms are needed to get 10 rounds for f(0.008)" << endl;
        
    return 0;
}