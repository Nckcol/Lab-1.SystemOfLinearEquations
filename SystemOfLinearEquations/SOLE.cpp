#include "stdafx.h"
#include "SOLE.h"

SOLE::SOLE(unsigned char dimention) : 
    _dimention(dimention) 
{
    resize(dimention);
    for (int i = 0; i < dimention; i++)
        at(i).resize(dimention + 1);
}

SOLE::~SOLE()
{
}

vector<double> SOLE::evaluate()
{
    vector<double> roots(_dimention);

    for (unsigned int k = 0; k < _dimention; k++) {
        for (unsigned int n = k + 1; n < _dimention; n++) {
            double d = sqrt(at(k).at(k) * at(k).at(k) + at(n).at(k) * at(n).at(k));
            double c = at(k).at(k) / d;
            double s = at(n).at(k) / d;
            for (unsigned int m = 0; m < _dimention + 1; m++) 
            {
                double tmp = at(k).at(m);
                at(k).at(m) = c*tmp + s*at(n).at(m);
                at(n).at(m) = -s*tmp + c*at(n).at(m);
            }
        }
    }

    for (int i = _dimention - 1; i >= 0; i--)
    {
        double summ = 0.;
        for (int j = i + 1; j < _dimention; j++)
        {
            summ += at(i).at(j) * roots.at(j);
        }
        summ = at(i).back() - summ;
        if (at(i).at(i) == 0)
        {
            //error
            return vector<double> ();
        }
        roots.at(i) = summ / at(i).at(i);
    }

    return roots;
}

vector<double> SOLE::generate()
{
    srand(time(NULL));

    vector<double> roots(_dimention);

    for (int i = 0; i < _dimention; i++)
        roots[i] = (rand() % 2100 - 1000) / 100;

    generate(roots);

    return roots;
}

void SOLE::generate(vector<double> roots)
{
    srand(time(NULL));

    for (int i = 0; i < _dimention; i++)
    {
        int sum = 0;
        for (int j = 0; j < _dimention; j++)
        {
            at(i).at(j) = (rand() % 2100 - 1000) / 100;
            sum += at(i).at(j) * roots.at(j);
        }
        at(i).at(_dimention) = sum;
    }
}

ostream & operator<<(ostream & os, const SOLE & sole)
{
    for (int i = 0; i < sole._dimention; i++)
    {
        for (int j = 0; j < sole._dimention + 1; j++)
        {
            os << sole.at(i).at(j) << " ";
        }
        os << endl;
    }

    return os;
}