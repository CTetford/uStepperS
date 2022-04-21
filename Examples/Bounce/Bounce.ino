/********************************************************************************************
* 	    	File:  LimitDetection.ino                                                         *
*		    Version:    2.3.0                                          						    *
*      	Date: 		December 27th, 2021  	                                    			*
*       Author:  Thomas Hørring Olsen                                                       *
*  Description:  Bounce Example Sketch!                                                     *
*                                                                                           *
* This example demonstrates how the library can be used to move the motor a specific angle, *
* Set the acceleration/velocity and read out the angle moved !                              *            *
*                                                                                           *
* For more information, check out the documentation:                                        * 
*                http://ustepper.com/docs/usteppers/html/index.html                         *
*                                                                                           *
*********************************************************************************************
*	(C) 2020                                                                                  *
*                                                                                           *
*	uStepper ApS                                                                              *
*	www.ustepper.com                                                                          *
*	administration@ustepper.com                                                               *
*                                                                                           *
*	The code contained in this file is released under the following open source license:      *
*                                                                                           *
*			Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International               *
*                                                                                           *
* 	The code in this file is provided without warranty of any kind - use at own risk!       *
* 	neither uStepper ApS nor the author, can be held responsible for any damage             *
* 	caused by the use of the code contained in this file !                                  *
*                                                                                           *
*                                                                                           *
********************************************************************************************/

#include <uStepperS.h>

uStepperS stepper;
float angle = 360.0;      //amount of degrees to move
void setup() {
  // put your setup code here, to run once:
  stepper.setup();        //Initialisation of the uStepper S
  stepper.setMaxAcceleration(2000);     //use an acceleration of 2000 fullsteps/s^2
  stepper.setMaxVelocity(500);          //Max velocity of 500 fullsteps/s
  stepper.checkOrientation(30.0);       //Check orientation of motor connector with +/- 30 microsteps movement
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!stepper.getMotorState())          //If motor is at standstill
  {
    delay(1000);
    stepper.moveAngle(angle);           //start new movement
    angle = -angle;                     //invert angle variable, so the next move is in opposite direction
  }
   Serial.print("Angle: ");
   Serial.print(stepper.encoder.getAngleMoved());       //print out angle moved since last reset
   Serial.println(" Degrees");
}
