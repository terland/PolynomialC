#include "linalg/poly.h"
#include "linalg/inner.h"
#include "linalg/sine.h"
#include "linalg/ortho.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath> // for exp function

using namespace std;

void printPoly(polynomial p)
{
	for(int i = 0; i < p.getDeg(); i++)
	{
		if (i != 0)
		{
			cout << "+ ";
		}
		cout <<  std::setprecision(25) << p.getVal(i) << "x^" << i << " ";
	}
	
	cout << endl;
}


int main()
{
	polynomial p(2);
	p.setVals(0,3);
	p.setVals(1,2);
	
	vector<polynomial> polyV(5);
	
	vector<polynomial> ortBasis = orthoBasis(6);
	
	
	polynomial polka = integral(polyMul(ortBasis[0],ortBasis[1]));
	
	
	int acc = 14;
	polynomial bestApproximation(10);
	
	for(int i = 0; i < ortBasis.size(); i++)
	{
		bestApproximation = bestApproximation + proj(est(acc),ortBasis[i]);
	}
	
	printPoly(bestApproximation);
	
	
	return 0;
}