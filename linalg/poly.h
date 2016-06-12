// Polynomial C - polynomial class; working with polynomials

#include <vector>
#include <string>
#include <cmath> // for exp function

using namespace std;


class polynomial
{
	private:
	vector<double> v; // vector containing coefficients
	int deg; // degree of polynomial
	
	public:
	polynomial(int degree = 0)
	{
		deg = degree;
		
		v = vector<double>(degree);
	}
	
	void setDegree(int degree)
	{
		deg = degree;
		while(v.size() <= degree)
		{
			v.push_back(0);
		}
	}
	
	int getDeg()
	{
		return deg;
	}
	
	void setVals(int pow, double val)
	{
		v[pow] = val;
	}
	
	void addTo(int pow, double val)
	{
		v[pow] += val;
	}
	
	double getVal(int pow)
	{
		return v[pow];
	}
	
	
	polynomial operator+ (polynomial added)
	{
		polynomial result(max(added.getDeg(),deg));
		
		for(int i = 0; i < deg; i++)
		{
			result.setVals(i,v[i]);
		}
		
		for(int i = 0; i < added.getDeg(); i++)
		{
			result.addTo(i,added.getVal(i));
		}
		
		return result;
	}
	
	polynomial operator+= (polynomial added)
	{
		setDegree(max(added.getDeg(),deg));
		
		for(int i = 0; i < added.getDeg(); i++)
		{
			addTo(i,added.getVal(i));
		}
	}
	
	
	polynomial operator- (polynomial added)
	{
		polynomial result(max(added.getDeg(),deg));
		
		for(int i = 0; i < deg; i++)
		{
			result.setVals(i,v[i]);
		}
		
		for(int i = 0; i < added.getDeg(); i++)
		{
			result.addTo(i,-added.getVal(i));
		}
		
		return result;
	}
	
	void operator*= (double val)
	{
		//cout << val << " :)" << endl;
		for(int i = 0; i < deg; i++)
		{
			v[i] *= val;
		}
	}
	
	polynomial operator*(double val)
	{
		polynomial result(deg);
		
		for(int i = 0; i < deg; i++)
		{
			result.setVals(i,v[i]*val);
		}
		
		return result;
	}
	
	
};

polynomial polyMul(polynomial a, polynomial b) // Multiply two polynomials
{
	int nd = a.getDeg() + b.getDeg()-1;
	polynomial ans = polynomial(nd);
	
	
	
	for(int i = 0; i < a.getDeg(); i++)
	{
		for(int j = 0; j < b.getDeg(); j++)
		{
			ans.addTo(i+j,a.getVal(i)*b.getVal(j));
		}
	}
	
	return ans;
}

polynomial integral(polynomial a)
{
	polynomial ans(a.getDeg()+1);
	
	for(int i = 0; i < a.getDeg(); i++)
	{
		ans.setVals(i+1,a.getVal(i)/(i+1));
	}
	
	return ans;
}

double eval(polynomial pol, double x)
{
	double ans = 0;
	
	for(int i = 0; i < pol.getDeg(); i++)
	{
		ans += pow(x,i)*pol.getVal(i);
	}
	
	return ans;
}





