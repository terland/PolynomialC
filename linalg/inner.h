// Inner product


double PI = asin(1)*2;

double inner(polynomial a, polynomial b)
{
	polynomial mul = polyMul(a,b);
	polynomial ny = integral(polyMul(a,b));
	
	return eval(ny,PI) - eval(ny,-PI);
}