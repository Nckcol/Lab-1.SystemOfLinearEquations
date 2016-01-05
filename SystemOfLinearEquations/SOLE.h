#pragma once
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

class SOLE :
    public vector<vector<double>>
{
    unsigned char _dimention;
public:
    SOLE(unsigned char dimention);;
    ~SOLE();

    vector<double> evaluate();
    vector<double> generate();
    void generate(vector<double> roots);
    
    friend ostream & operator<<(ostream & os, const SOLE & sole);
};

