#include <iostream> //outputs
#include <vector>   //vectors...
#include <string>   //strings...
#include <random>   //all the random stuff
#include <time.h>   //clock_t, clock, CLOCKS_PER_SEC 


//functions
int main();

//variables
std::vector<int> Gen;

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {
        r=(n%2==0 ? "0":"1")+r;//is remainder of n/2 equal to 0? 0 if yes, 1 if no.
        n/=2;//divide n by 2 for next iteration
    }
    return r;
}

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // specifies random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(1,10); // unbiased int in range specified in uni
std::uniform_real_distribution<> unid(0.,10.); // unbiased real in range specified in uni
