#include <iostream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

vector<double> read_polynomial (const string str, const double at) {
    vector<double> FILE;
    stringstream ss;
    
    ss << str;                                                                                                                                                                                                                                                                                                                                         
    
    while(!ss.eof()) {
        double a;
        string temp;
        
        ss >> temp;
        
        if(stringstream(temp) >> a)
            FILE.push_back(a);
    }
    
    cout << "Your input function is read as: ";
    for(int i = 0; i < FILE.size() ;i++) {
        
        if(FILE.at(i) > 0 && i != 0) 
            cout << "+";
        
        if((FILE.size()-1-i) != 0) 
            cout << FILE.at(i) << "x^" << FILE.size()-1-i;
        else 
            cout << FILE.at(i);
    }
    
    cout << " at " << at << endl;
    
    return FILE;
};

vector<double> calc_polynomial (const vector<double> l, const double at) {
    vector<double> FILE;
    double a = at;
    
    double temp = 0;
    for(int i = 0; i < l.size(); i++) {
        cout << l.at(i) << " + " << temp << "*" << a << " = "; 
        temp = l.at(i) + temp*a;
        cout << temp << endl;
        
        FILE.push_back(temp);
    }
    
    return FILE;
};

void displayFinal (const vector<double> l, const double at) {
    cout << "Your input function is read as: ";
    
    // (x-a) 
    cout << "(x";
    if(at < 0) {
        cout << "+";
    }
    else {
        cout << "-";
    }
    cout << at << ")";
    
    // (ax^n + bx^n-1 ... + c) + d 
    int size = l.size();
    cout << "(";
    for(int i = 0; i < size ;i++) {

        if(i == (size-1)) {
                cout << ")";
        }

        if(l.at(i) > 0 && i != 0) {
            cout << "+";
        }
        
        if(i < (size-2)) {
            cout << l.at(i) << "x^" << l.size()-2-i;
        }
        else {
            cout << l.at(i);
        }
    }
    
    cout << " which p(" << at << ")=" << l.back() << "." << endl; 
};

int main() {
    
    string input;
    double at;
    
    cout << "input your function: ";
    
    getline(cin,input);
    cout << "Your input is: " << input << endl;
    
    cout << "At value: ";
    cin >> at;
    
    vector<double> polyList = read_polynomial(input,at);
    vector<double> fixedList = calc_polynomial(polyList,at);
    displayFinal(fixedList, at);
    
    return 0;
}