// Basis for Polynomial space
#include <vector>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cmath> // for exp function

using namespace std;

polynomial gramSchmidt(vector<polynomial> v, polynomial poly);
vector<polynomial> getBasis(int dimension);
vector<polynomial> orthoBasis(int dimension);
polynomial gramSchmidt(vector<polynomial> v, polynomial poly);

vector<polynomial> getBasis(int dimension)
{
	vector<polynomial> basis(dimension);
	
	for(int i = 0; i < dimension; i++)
	{
		polynomial cur(dimension);
		cur.setVals(i,1);
		basis[i] = cur;
	}
	
	return basis;
}

vector<polynomial> orthoBasis(int dimension)
{
	vector<polynomial> oldbasis = getBasis(dimension);
	vector<polynomial> basis;
	
	for(int i = 0; i < dimension; i++)
	{
		basis.push_back(gramSchmidt(basis,oldbasis[i]));
	}
	
	return basis;
	
}

polynomial proj(polynomial a, polynomial line)
{
	polynomial ans = line*(inner(a,line)/inner(line,line));
	return ans;
}

polynomial projSpace(polynomial a,vector<polynomial> subspace)
{
	polynomial ans = proj(a,subspace[0]);
	
	for(int i = 1; i < subspace.size(); i++)
	{
		ans += proj(a,subspace[i]);
	}
	
	return ans;
}

polynomial gramSchmidt(vector<polynomial> v, polynomial poly)
{
	polynomial ans = poly;
	
	for(int i = 0; i < v.size(); i++)
	{
		ans = ans - proj(ans,v[i]);
	}
	
	ans *= ((1/sqrt((inner(ans,ans)))));
	return ans;
}