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
	int speedDiff;
 double errorRate=0;
 double finalError=0;
int countc=0;
int main(){
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
 else{pix[i]=1;}}
void getError(){
errorRate=0;
finalError=0;
for(i=0;i<320;i++){
errorRate=(i-160)*pix[i];
finalError=finalError+errorRate;}
	return finalError;}
close_screen_stream();
return 0;
}
}
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
	double finalError
	public:
	void setSpeed(){
	//methods here
	camera a;
	finalError=a.getError;
	speedDiff=(finalError/1000);
set_motors(1,48+speedDiff);
set_motors(5,48-speedDiff);}
}
	
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
	
	camera on;
	on.runCamera();
	
	return 0;
	}
