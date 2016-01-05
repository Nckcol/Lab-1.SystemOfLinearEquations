// SystemOfLinearEquations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SOLE.h"

using namespace std;

#define DIMENTION 5

int main()
{

    SOLE sole(DIMENTION);
    vector<double> roots = sole.generate();
    vector<double> result = sole.evaluate();

    cout << "System of linear equations:" << endl;
    cout << sole << endl << endl;

    cout << "Roots:" << endl;

    for (int i = 0; i < DIMENTION; i++)
    {
        if (abs(roots[i] - result[i]) < 0.001)
        {
            cout << "PASSED: ";
        }
        else
        {
            cout << "FAILED: ";
        }
        cout << roots[i] << " " << result[i] << endl;
    }

    return 0;
}

