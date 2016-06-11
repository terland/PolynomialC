#include "poly.cpp"

using namespace std;

int main()
{
	polynomial p(2);
	p.setVals(0,0);
	p.setVals(1,3);
	
	cout << eval(p,3) << endl;
	
	cout << p.getVal(0) << endl;
	
	cout << (p + p + p*2).getVal(0) << endl;
	
	
	
	return 0;
}