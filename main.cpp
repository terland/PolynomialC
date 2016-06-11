#include "linalg/poly.h"
#include "linalg/inner.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


void printPoly(polynomial p)
{
	for(int i = 0; i < p.getDeg(); i++)
	{
		if (i != 0)
		{
			cout << "+ ";
		}
		cout <<  p.getVal(i) << "x^" << i << " ";
	}
	
	cout << endl;
}

int main()
{
	polynomial p(2);
	p.setVals(0,3);
	p.setVals(1,2);
	
	printPoly(p);
	printPoly(polyMul(p,p));
	printPoly(integral(polyMul(p,p)));
	
	cout << std::setprecision(20) << asin(1)*2 << endl;
	
	polynomial q(1);
	q.setVals(0,1);
	
	cout << inner(q,q) << endl;
	//q.setVals
	
	
	
	return 0;
}