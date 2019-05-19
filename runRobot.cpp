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
	public:
	//methods here
	
	}
	
class GateOpen{
	//fields here
	private:	
	char[15] serverAddress = { '1','2','7','.','0','0','1','.','0','0','1','.','0','0','1' };	//char server_addr[15] = { '1','2','7','.','0','0','1','.','0','0','1','.','0','0','1' }; TEST THE ADDRESS
	int port = 0;																				//need to find what the port number is
	char[24] message = { '' };																	//find what the message should be

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
			msg_recieved = receive_from_server();
		}
		
		//where does response go???
			//create password

		send_to_server(password);
		//gate opens, mission accomplished

	};
	
	}
	
	
	
class Wheels{
	//fields here
	public:
	//methods here
	
	}

class RunRobot{
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
