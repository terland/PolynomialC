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
		cout <<  std::setprecision(10) << p.getVal(i) << "x^" << i << " ";
	}
	
	cout << endl;
}


int main()
{		
	int d;
	cin >> d;
	
	polynomial tof(d);
	
	for(int i = 0; i < d; i++)
	{
		int x;
		cin >> x;
		tof.setVals(i,x);
	}
	
	int app;
	cin >> app;
	
	vector<polynomial> ortBasis = orthoBasis(app);
	
	polynomial bestApproximation(app);
	
	for(int i = 0; i < ortBasis.size(); i++)
	{
		bestApproximation = bestApproximation + proj(tof,ortBasis[i]);
	}
	
	printPoly(bestApproximation);
	
	cout << "Error: " << sqrt(inner(bestApproximation - tof,bestApproximation - tof));
	int k;
	cin >> k;
	
	cout << "Bye!" << endl;
	
	
	return 0;
}