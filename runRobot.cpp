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

class Camera{		//Ben: reformatted code to make it easier to read - didn't change any code
	//fields here
	private:
	int speedDiff;
 	double errorRate=0;
 	double finalError=0;
	int countc=0;
	//main(){ //main???
	int i;
	int pix [320];
	init(0);

	public:
	void doCamera{	//what is this method suppossed to do?
		open_screen_stream();
		while (true) {	//this loop never exits, runs forever.
			hardware_exchange();
			take_picture();
			update_screen();
			int countc = 0;

			while (countc < 320) {
				pix[countc] = (int)get_pixel(120, countc, 3);
				countc++;
			}

			int max = 0;
			int min = 10000000;
			for (i = 0; i < 320; i++) { if (pix[i] > max) { max = pix[i]; } }
			for (i = 0; i < 320; i++) { if (pix[i] < min) { min = pix[i]; } }

			int midValue = (max + min) / 2;
			for (i = 0; i < 320; i++) {
				if (pix[i] > midValue) {
					pix[i] = 0;
				}
				else {
					pix[i] = 1;
				}

			}

		}
		//close_screen_stream();
	};
		

	double getError(){ //should probably return an Int
	
		errorRate=0;
		finalError=0;
		for(i=0;i<320;i++){
			errorRate=(i-160)*pix[i];
			finalError=finalError+errorRate;
		}
		close_screen_stream();
		return finalError;
	}; //once you call return the method will exit. -- calling return on a void method, changed to double
		//close_screen_stream();
	
		//return 0;
	
};
//}
//}
	
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
	//shouldnt speedDiff be declared here?
	public:
	//methods here
	void setSpeed(){
		
		camera a;
		finalError=a.getError();			
		speedDiff=(finalError/1000);
		set_motors(1,48+speedDiff);
		set_motors(5,48-speedDiff);}
		//hardware exchange method is never called
		//update_hardware();
	};
	
	
	void stop(){
		//set the motor speed to stop the robot
		set_motors(1, 48);
		set_motors(5, 48);
		update_hardware();
	};

	/*
		Reverses the robot, stops reversing when get error method returns non-zero value.
	*/
	void reverse(){
		//call when the line is 'lost'
		camera a;
		//setting motors to reverse
		set_motors(1,48-3);
		set_motors(5,48+3);
		update_hardware();
		while (true) {
			double error = a.getError();
			if (error != 0) { //line regained
				break;
			}
			sleep1(10); //sleep 10 ms
		}
		this.stop();
	};
	

	
	};

class RunRobot{
	//fields here
	private:
	bool cameraPosition = true; //true if facing ground
	int currentQuadrant = 1; //area 1 is the gate, initial position
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
	
	int followLine(){
		//the method for quadrant one
		//follow the curvy line on the ground (for how long? testing needed)
		//returns 1 when section is complete
		return 2;
	};
	
	int navMaze() {
		//the method for quadrant one
		//follow the curvy line on the ground (for how long? testing needed)
		//returns 1 when section is complete
		return 3;
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
	on.runCamera();	//this method does not exist
	
	return 0;
	}
