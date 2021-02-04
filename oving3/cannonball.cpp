#include "cannonball.h"
#include "utilities.h"

double acclY(){
    return g;
}

double velY(double initVelocityY, double time){
    return initVelocityY + acclY()*time;
}

double posY(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time + acclY()*(pow(time,2)/2);
} 

double posX(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time;
}

void printTime(double time){
    int hours = static_cast<int>(time) / 3600;
	int minutes = (static_cast<int>(time) % 3600) / 60;
	int seconds = static_cast<int>(time) % 60;
	cout << hours << ":" << minutes << ":" << seconds;
}

double flightTime(double initVelocityY){
    return (-2*initVelocityY)/acclY();
}


double getUserInputTheta(){
    double theta;
    cout << "Theta: ";
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity(){
    double absVelocity;
    cout << "absVel: ";
    cin >> absVelocity;
    return absVelocity;
}

double degToRad(double deg){
    double rads = (deg/180.0)*pi;
    return rads;
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity*cos(theta);
}

double getVelocityY(double theta, double absVelocity){
    return absVelocity*sin(theta);
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velVector(2);
    velVector.push_back(getVelocityX(theta, absVelocity));
    velVector.push_back(getVelocityY(theta, absVelocity));
    return velVector;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double flight_time = flightTime(velocityY);
    double dist = posX(0, velocityX, flight_time);
    return dist;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double distance_target = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
    return distance_target;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	if(abs(compareOperand - toOperand) <= maxError){
		cout << name << " is within the limit\n";
	}
    else{
		cout << name << " is not within the limit\n";
	}
}

void playTargetPractise(){
    cout << "Hit target game. Input angle and velocity and hit the target. 10 tries. \n";
    double tolerance = 5;
    int distTarget = randomWithLimits(100,1000);
    cout << "Distance to target: " << distTarget << "\n";
    for(int i =0; i < 10; ++i){
        cout << "Try: " << i+1 << "\n";
        double deg = getUserInputTheta();
        double theta = degToRad(deg);
        double absVel = getUserInputAbsVelocity();
        double velX = getVelocityX(theta, absVel);
        double velY = getVelocityY(theta, absVel);
        double dist_target = targetPractice(distTarget, velX, velY);
        double flight_time = flightTime(velY);
        if(abs(dist_target) <= tolerance){
            cout << "hit!" << dist_target << "\nFlight time: \n";
            printTime(flight_time);
            break;
        }

        else if(dist_target < 0){
            cout << "Shot went past target: " << abs(dist_target);
        }
        else{
            cout << "Shot was short: " << abs(dist_target);
        }
        cout << "\nFlight time: \n";
        printTime(flight_time);
        cout << "\n";  
    }
}