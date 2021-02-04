#include "std_lib_facilities.h"
#include "utilities.h"

int randomWithLimits(int lower, int upper){
    upper = upper + 1;
    int random = rand() % (upper-lower) + lower;
    return random;
}