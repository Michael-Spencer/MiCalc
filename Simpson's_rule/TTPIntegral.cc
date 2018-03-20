#include "TTPIntegral.hh"

int main(){

    //declaring some variables
    const double pi = 4.*atan(1.);//I define instead of using a module
    const int steps = 100000000;//0.1 billion steps for now

    //for the x^2 one - pole in middle
    aGlobalStart = 0.;
    aGlobalMid = 2.;
    aGlobalEnd = 1E4;
    //for the sinx one
    bGlobalStart = 1e-20;
    bGlobalEnd = 1e4;

    //find poles
    const double aStepWidth = (bGlobalEnd-bGlobalStart)/double(steps);
    aFuncPoles(aPoles, steps, aStepWidth);
    for(int i =0; i < aPoles.size(); i++){std::cout << aPoles[i] << std::endl;}


    //Integral uses Simpsons throughout 
    //h/3 * [f(a) + f(b) + 4*sum_j(f(a + jh) + 2*sum_j(f(a + jh)]
    double aESum = aEvenSum(steps, aGlobalStart, aGlobalEnd, aGlobalMid), aOSum = aOddSum(steps, aGlobalStart, aGlobalEnd, aGlobalMid);
    double bESum = bEvenSum(steps, bGlobalStart, bGlobalEnd), bOSum = bOddSum(steps, bGlobalStart, bGlobalEnd);


    aIntegralResult = (aStepWidth/3.)*(aFunction(aGlobalStart) + aFunction(aGlobalEnd) + 4.*aOSum + 2.*aESum);

    lines(2, "bf");//display
    std::cout << "Integral a = (x^2.)/((x^2.-4)*(x^2.+9))" << "\n";
    std::cout << "Integral a (numerical solution) = " << aIntegralResult << "\n";
    std::cout << "Integral a (analytic solution) = (3.*pi)/26. = " << (3.*pi)/26. << "\n";
    std::cout << "Error = " << (3.*pi)/26. - aIntegralResult << "\n";

    const double bStepWidth = (bGlobalEnd-bGlobalStart)/double(steps);
    bIntegralResult = (bStepWidth/3.)*(bFunction(bGlobalStart) + bFunction(bGlobalEnd) + 4.*bOSum + 2.*bESum);

    lines(1, "bf");
    std::cout << "Integral b = sin(x)/x" << "\n";
    std::cout << "Integral b (numerical solution) = " << bIntegralResult << "\n";
    std::cout << "Integral b (analytic solution) = pi/2. = " << pi/2. << "\n";
    std::cout << "Error = " << pi/2 - bIntegralResult << "\n";
    lines(2, "bf");

    return 0;
}
