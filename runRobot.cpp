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
	
	}
	
class GateOpen{
	//fields here
	private:	
	char[15] serverAddress = { '1','3','0','.','1','9','5','.','0','0','6','.','1','6','6' };	//char server_addr[15] = { '1','2','7','.','0','0','1','.','0','0','1','.','0','0','1' }; TEST THE ADDRESS
	int port = 1024;																				//need to find what the port number is0
	char[24] message = { 'P','l','e','a','s','e' };																	//find what the message should b1024

	public:
	//methods here
	void openGate(){
		//connect to the server
		int isConnected = 0;
		while (isConnected == 0) {
			isConnected = connect_to_server(serverAddress,port);
		}
		
		//send message to server
		send_to_server(message);
			
		int msg_recieved = 0;
		while (msg_recieved == 0) { 
			//wait for response, returns 0 when false???
			msg_recieved = receive_from_server(message);
		}
		
		
		
		

		send_to_server(message);
		//gate opens, mission accomplished

	};
	
	}
	
	
	
class Wheels{
	private:
	//fields here
	public:
	//methods here
	
	}

class RunRobot{
	private:
	//fields here
	public:
	//methods here
	
	}



int main(){
	//example code
		//make a new object
	GateOpen open;
		//call a method on the object
	open.openGate();
	return 0;
	}
