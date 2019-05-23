#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>

//run robot needs fields for
//current quadrant
//camera position

//rubRobot needs to create new 
//camera object
//network object
//wheel objects

//main method

class Camera{
	//fields here
	private:
	int speedDiff;
 	double errorRate=0;
 	double finalError=0;
	int countc=0;
	int main(){ //main???
	int i;
	int pix [320];
	init(0);

public:
void doCamera{
	open_screen_stream();
	while(true){
         hardware_exchange();take_picture(); update_screen(); int countc=0;
	while(countc <320)
	{pix [countc] = (int)get_pixel(120,countc,3);
 	countc++;}

	int max=0;
	int min=10000000;
 	for(i=0;i<320;i++){ if(pix[i]>max){max=pix[i];}}
 	for(i=0;i<320;i++){if(pix[i]<min){min=pix[i];}}

 	int midValue=(max+min)/2;
 	for(i=0;i<320;i++){if(pix[i]>midValue){pix[i]=0;}
 	else{pix[i]=1;}
	};
		

double getError(){ //should probably return an Int
	errorRate=0;
	finalError=0;
	for(i=0;i<320;i++){
	errorRate=(i-160)*pix[i];
	finalError=finalError+errorRate;}
	return finalError;
	}; //once you call return the method will exit. -- calling return on a void method, changed to double
		close_screen_stream();
	
		//return 0;
	
}
}
}
	
class GateOpen{
	//fields here
	private:	
	char[15] serverAddress = { '1','3','0','.','1','9','5','.','6','.','1','9','6' };	//char server_addr[15] = { '1','2','7','.','0','0','1','.','0','0','1','.','0','0','1' }; TEST THE ADDRESS
	int port = 1024;																				//need to find what the port number is0
	char[24] message = { "Please" };																	//find what the message should b1024

	public:
	//methods here
	int openGate(){
		//connect to the server
		connect_to_server(serverAddress,port);
		//send message to server
		send_to_server(message);
		//get message from server
		receive_from_server(message);
		//send server response back to server
		send_to_server(message);
		//gate opens, mission accomplished
		
		return 1;

	};
	
	};
	
	
	
class Wheels{
	//fields here
	private:
	double finalError;
	public:
	//methods here
	void setSpeed(){
		
		camera a;
		finalError=a.getError;
		speedDiff=(finalError/1000);
		set_motors(1,48+speedDiff);
		set_motors(5,48-speedDiff);}
	};
	
	void reverse(){
	//reverse the robot
		//call when the line is 'lost'
	//call the get error method
		//if line is found, set the motors to neurtral and exit
		//if no, set the motor speed to reverse and check again
	};
	
	void stop(){
	//set the motor speed to stop the robot
	};
	
	};

class RunRobot{
	//fields here
	bool cameraPosition; //true if facing ground
	int currentQuadrant;
	public:
	//methods here
	void changeCameraPos(){
	//change the camera motor speed to change its position
	if(cameraPosition){ //true means facing ground
		//set the motor to a speed for a certain time to make it look up (90 degree rotation)
	}else{
		//set the motor to a speed for a certain time to make it look down (90 degree rotation)
	}
		cameraPosition = !cameraPosition;
	};
	
	void followLine(){
		//the method for quadrant one
		//follow the curvy line on the ground (for how long? testing needed)
	};
	
	void startRobot(){
		//the first method to be called, opens the gate and calls follow line
	};
	    //what does the robot need to do in each area?
		//if in quadrant 0
		//call gate open and move forwards
	
		//if in quadrant 1
		//
	
		//if in quadrant 2
		//
	
		//if in quadrant 3
		//
	};



int main(){
	//example code
		//make a new object
	GateOpen open;
		//call a method on the object
	open.openGate();
	
	camera on;
	on.runCamera();
	
	return 0;
	}
