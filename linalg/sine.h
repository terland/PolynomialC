// Define sine function using polynomials;

long long fact(int i) // factorial function
{	
	if (i == 1 || i == 0)
	{
		return 1;
	}
	
	return fact(i-1)*i;
}

polynomial est(int degree)
{
	polynomial ans(degree);
	
	for(int i = 1; i < degree; i+=2)
	{
		ans.setVals(i,pow(-1,i/2)*double(1)/double(fact(i)));
	}
	
	return ans;
}