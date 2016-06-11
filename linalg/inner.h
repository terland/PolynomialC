// Linalg

#include <vector>
#include <string>
#include <cmath>

using namespace std;

double PI = asin(1)*2;

double inner(polynomial a, polynomial b)
{
	polynomial ny = integral(polyMul(a,b));
	
	return eval(ny,PI) - eval(ny,-1*PI);
}