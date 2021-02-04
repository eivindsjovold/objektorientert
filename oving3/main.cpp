#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

int main(){
	srand(static_cast<unsigned int>(time(nullptr)));
	/*
	double maxError = 0.01;
	testDeviation(acclY(), g, maxError, "accelY()");
	testDeviation(velY(25.0, 2.5), 0.475, maxError, "velY(25.0, 2.5)");
	testDeviation(posX(0.0, 50.0, 2.5), 125.0, maxError, "posX(0.0, 50.0, 2.5)");
	testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0, 25.0, 2.5)");
	testDeviation(flightTime(30.0), 6.116, maxError, "flightTime(30.0)");
	*/
	playTargetPractise();
}
