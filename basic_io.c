#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {

	float	launchHeight;
	int		launchAngle;
	float	launchVelocity;
	float	vertLaunchVelocity;
	float	horizLaunchVelocity;
	float	launchAngleRad;
	float	timeToImpact;
	float	distanceTraveled;
	float	returnToLaunchHeight;
	float	fromLaunchHeightToGround;

	printf("Hello and welcome to the Ballistic Calculator v0.0.2! This program is licensed under the GPL V3.0 and was written by Bryson O'Neill\n\n");
	
	printf("Changelog\n");
	printf("Spelling fixes\n\n");

	/* Launch Height Section */
	do {
		printf("Please enter a height above the ground in meters.\n");
		scanf("%f", &launchHeight);
		printf("\n You entered: %f meters\n", launchHeight);
		if (launchHeight < 0) {
			printf("Input Error: Expected a positive number\n");
		}
	}while( launchHeight < 0);


	/* Launch Angle Section */
	do{
		printf("Please enter a launch angle in degrees \n");
		scanf("%d", &launchAngle);				/* takes user input and stores it in launchAngle's memory address */
		printf("\n You entered: %d degrees\n", launchAngle);
		if (launchAngle > 90 || launchAngle < -90) {
			printf("Input Error: Expected an angle between 90 and -90 degrees\n");
		}
	}while( launchAngle > 90 || launchAngle < -90);


	/* Launch Velocity Section */
	do{
		printf("Please enter an initial launch velocity in m/s\n");
		scanf("%f", &launchVelocity);			/* takes user input and stores it in launchVelocity's memory address */
		printf("\n You entered: %f m/s\n", launchVelocity);
		if (launchVelocity < 0) {
			printf("Input Error: Expected a positive number\n");
		}
	}while( launchVelocity < 0);

//Calculations section
launchAngleRad = launchAngle * 0.0174532925;
// printf("\n %f",launchAngleRad);
 horizLaunchVelocity = launchVelocity * cos(launchAngleRad);
 vertLaunchVelocity= launchVelocity * sin(launchAngleRad);
printf ("\n horiz: %fm/s vert: %fm/s\n", horizLaunchVelocity, vertLaunchVelocity);

// Time for projectile to reach the ground

// check to see if the launch angle is positive or negative
// if positive: time to return to launch height: 2*vertLaunchVelocity/g
//		fall time from launch height to ground is (height*16)/(vertLaunchVelocity*15)
//		total flight time = returntolaunchheight+fromlaunchheighttoground

if (launchAngle >= 0) {
	returnToLaunchHeight = 2 * vertLaunchVelocity / 9.81;
	fromLaunchHeightToGround = (launchHeight * 16) / (vertLaunchVelocity * 15);
}

printf("To launch height: %fs To ground: %fs\n", returnToLaunchHeight, fromLaunchHeightToGround);
timeToImpact = returnToLaunchHeight + fromLaunchHeightToGround;
distanceTraveled = timeToImpact * horizLaunchVelocity;
//printing stuff

printf("launch height: %fm \n", launchHeight);
printf("launch angle: %d degrees\n", launchAngle);
printf("launch velocity: %fm/s \n", launchVelocity);
printf("time to impact: %fs \n", timeToImpact);
printf("distance travelled: %fm \n", distanceTraveled);









	return 0;
}
