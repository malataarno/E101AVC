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
	private:
	//fields here
	public:
	//methods here
	
	};
	
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
	private:
	//fields here
	public:
	//methods here
	
	};

class RunRobot{
	private:
	//fields here
	public:
	//methods here
	
	};



int main(){
	//example code
		//make a new object
	GateOpen open;
		//call a method on the object
	int gateIsOpen = open.openGate();
	while(gateIsOpen == 0){
		
		}
		
	return 0;
	}
