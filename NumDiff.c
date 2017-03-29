#include "math.h"
#include "stdio.h"

//Function to be differentiate. Assume to be one variable
float InputFunction(float x)
{
 return exp(x*x);
}

float InputFunctionD(float x)
{
 return 2*x*exp(x*x);
}

//Finding Derivateive using center difference approach of exp(x^2)
void CenterDifference(float x,float h,float *result,float *error)
{
	*result=0;
	*error=0;
 	*result=(InputFunction(x+h)-InputFunction(x-h))/(2*h);
	*error=(*result - InputFunctionD(x));
}


//Compare the result using different values of h
int main()
{
  float result=0;
  float err=0;
  float x=0;
  float h=0;

  printf("Input Value x:");
  scanf("%f",&x);
  printf("Input Interval h:");
  scanf("%f",&h);
  CenterDifference(x,h,&result,&err);
  printf("The numerical first differential is: %.3f and the absolute error is %.3f",result,err);
}

