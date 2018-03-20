#include <iostream> //Input and output                              
#include <stdlib.h>                                        
#include <math.h>
#include <cmath> //isnan()
#include <vector>

double aGlobalStart, aGlobalMid, aGlobalEnd;//inputs - x^2
double bGlobalStart, bGlobalEnd;//inputs - sinx

double aIntegralResult;
double bIntegralResult;

std::vector<double> aPoles;

double aFunction(double XPoint){
    double xx=pow(XPoint,2.);
    XPoint = (xx)/((xx-4)*(xx+9));
    return XPoint;
}

void aFuncPoles(std::vector<double>& aPoles, double steps, double stepsize){

    for(int i=0;i<steps;i++){
        if(std::isnan(aFunction(aGlobalStart + (double)i * stepsize))){
            aPoles.push_back(aGlobalStart + (double)i * stepsize);
        }
    }
}


double bFunction(double XPoint){
    XPoint = sin(XPoint)/XPoint;
    return XPoint;
}

double aOddSum(double steps, double GlobalStart, double GlobalEnd, double GlobalMid){
    double SummedOdd = 0.;
    const double StepWidth = (GlobalEnd-GlobalStart)/double(steps);//all steps
    int StepsInit = (GlobalMid - GlobalStart)/StepWidth, StepsFinal = (GlobalEnd-GlobalMid)/StepWidth;

    for(int i = 1; i < StepsInit; i += 2){//change limits so within iterator
        SummedOdd += aFunction(GlobalMid - double(i)*StepWidth);
    }
    for(int i = 1; i < StepsFinal; i += 2){//change limits so within iterator
        SummedOdd += aFunction(GlobalMid + double(i)*StepWidth);
    }
    return SummedOdd;
}

double aEvenSum(double steps, double GlobalStart, double GlobalEnd, double GlobalMid){
    double SummedEven = 0.;
    const double StepWidth = (GlobalEnd-GlobalStart)/double(steps);
    int StepsInit = (GlobalMid - GlobalStart)/StepWidth, StepsFinal = (GlobalEnd-GlobalMid)/StepWidth;

    for(int i = 2; i < StepsInit; i += 2){
        SummedEven += aFunction(GlobalMid - double(i)*StepWidth);
    }
    for(int i = 2; i < StepsFinal; i += 2){
        SummedEven += aFunction(GlobalMid + double(i)*StepWidth);
    }

    return SummedEven;
}

double bOddSum(double steps, double GlobalStart, double GlobalEnd){
    double SummedOdd = 0.;
    const double StepWidth = (GlobalEnd-GlobalStart)/double(steps);

    for(int i = 1; i < steps; i += 2){//change limits so within iterator
        SummedOdd += bFunction(GlobalStart + double(i)*StepWidth);
    }
    return SummedOdd;
}

double bEvenSum(double steps, double GlobalStart, double GlobalEnd){
    
    double SummedEven = 0.;
    const double StepWidth = (GlobalEnd-GlobalStart)/double(steps);

    for(int i = 2; i < steps; i += 2){
        SummedEven += bFunction(GlobalStart + double(i)*StepWidth);
    }
    return SummedEven;
}

void lines(int number, std::string newline){
  if(newline == "bf" || newline == "b") std::cout << "\n";
  for(int i = 0; i < number; i++){
      std::cout << "***********************************************************\n";
  }
  if(newline == "bf" || newline == "f") std::cout << "\n";
}
