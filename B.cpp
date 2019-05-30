#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>

/*
 * Run camera method:
 * Creates array of pixels of a certain color.
 * 
 * Get Error method:
 * Returns a double which describes how far to the left/right the black line is from the centre of the camera.
 * 
 * */
class Camera{ //updated class to most recent version
	public:
	double runCamera(int col){	
		
		int countc=0;
		//int main(){
		int i;
		int pix [320];
		int max=0;
		int min=0;
		double midValue;
		double errorRate=0;
		double finalError=0;
		int blackCount;
		
		
					while(countc <320)
						{pix [countc] = (int)get_pixel(120,countc,col);
							countc++;
							}

					
					for(i=0;i<320;i++){ 
						if(pix[i]>max){max=pix[i];}
						if(pix[i]<min){min=pix[i];}
						}
					midValue=(max-min)/2;
				for(i=0;i<320;i++){
					if(pix[i]>midValue){
						pix[i]=0;
						}
					else{pix[i]=1;}
					}
					
					for(i=0;i<320;i++){
						errorRate=(i-160)*pix[i];
						finalError=finalError+errorRate;
						if(pix[i]==1){
							blackCount++;
						}
						
						}
						finalError=finalError/blackCount;
						
						for(i=0;i<320;i+=32){
	//printf(" %d",pix[i]);
	}//printf("\n");
						return finalError;
						};
	/*public:
	int countc=0;
    int i;
    int pix [320];
    int max=0;
    int min=0;
    double midValue;
    double errorRate=0;
    double finalError=0;
    int blackCount;
    double totpix=0;*/
        //public:
//double                
/*double runCamera(int colour){
	
	
       totpix=0; //reset field 
       while(countc <320){
       pix [countc] = (int)get_pixel(120,countc,colour);
       countc++;
       }
       totpix+=pix[i];
       return totpix; */
       
							//};
                                                        
/*double getError(){
       for(i=0;i<320;i++){
               if(pix[i]>max){max=pix[i];}
               if(pix[i]<min){min=pix[i];}
                         }
                                                
		midValue=(max-min)/2;
		
              for(i=0;i<320;i++){
					if(pix[i]>midValue){
                            pix[i]=0;
                     }else{
							pix[i]=1;}
                                 }

 for(i=0;i<320;i++){
	errorRate=(i-160)*pix[i];
	finalError=finalError+errorRate;
			if(pix[i]==1){
					blackCount++;
                          }
                    }
                    
	finalError=finalError/blackCount;

	for(i=0;i<320;i+=32){
        printf(" %d",pix[i]);
        }printf("\n");
  return finalError;
 };*/

};

/*
 * Has one method:
 * openGate() opens the gate.
 * */	
class GateOpen{
	//fields here
	private:	
	char serverAddress[15] = { '1','3','0','.','1','9','5','.','6','.','1','9','6' };	//char server_addr[15] = { '1','2','7','.','0','0','1','.','0','0','1','.','0','0','1' }; TEST THE ADDRESS15
	int port = 1024;																				//need to find what the port number is0
	char message[24] = { "Please" };																	//find what the message should b1024

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
		
		return 2; //update to sector 2 (line section)

	};
	
	};
	
	
	
class Wheels{
	//fields here
	private:
        Camera a;
        int leftW=50; //48+2 = 50, speed = 2
        int rightW=46; //48-2 = 46, speed = 2
        double kp=0.1;
        
	public:
				int speedDiff;
                double errorRate=0;
                double finalError;
/*
 * Changes the speed of the motor, to keep the robot following the line.
 * DOES NOT update the motor speed.
 * */                
void setSpeed(){
        a.runCamera(3);
        finalError=a.runCamera(3);
        speedDiff=(finalError*kp);
        //printf("motor %d",speedDiff);
        //printf(" %f",finalError);
		set_motors(1,leftW+speedDiff);
		set_motors(5,rightW+speedDiff);
};
/*
 * Calling this method will stop the robot.
 * */
void stop(){
		//set the motor speed to stop the robot
		set_motors(1, 48);
		set_motors(5, 48);
		//update_hardware(); <--needs to be called eslewhere
	};
/*
 * Reverses the robot, stops reversing when get error method returns non-zero value.
 * */
void reverse(){
		//call when the line is 'lost'
		//setting motors to reverse
		
		set_motors(1,48-3);
		set_motors(5,48+3);
		//update_hardware();
		while (true) {
			a.runCamera(3);
			double error = a.runCamera(3);
			if (error != 0) { //line regained
				break;
			}
		sleep1(10); //sleep 10 ms
		}
		//this.stop();
		stop();
	};
};
	
	



	

	
	
//This class is no longer needed.
//The main method does exactly the same thing.
/*class DoRobot {
	//fields here
	private:
	bool cameraPosition = true; //true if facing ground
	int currentQuadrant = 0; //area 1 is the gate, initial position
	public:
	//methods here
	void changeCameraPos(){
		if(cameraPosition){ //true means facing ground
			//set the motor to a speed for a certain time to make it look up (90 degree rotation)
		
		}else{
			//set the motor to a speed for a certain time to make it look down (90 degree rotation)
		
		}
			cameraPosition = !cameraPosition;
	};
	
	void followLine(Camera a , Wheels wheel){
		//the method for quadrant one
		//follow the curvy line on the ground (for how long? testing needed)
		//returns 1 when section is complete
		
		
			for(int i = 0; i < 500; i++){//testing if robot can follow line - loop runs 500 times
				//check for line
				double err = a.getError();
				if(err == 0){
					wheel.reverse();
					}
			wheel.setSpeed();
			}
			wheel.stop();
			//this.navMaze(a,wheel);
		currentQuadrant = 2;
	};
	
	void navMaze(Camera a , Wheels wheel) {
		//the method for quadrant two
		//follow right angle turns
		
		currentQuadrant = 3;
	};

	void startRobot(){
		//the first method to be called, opens the gate and calls follow line
		GateOpen open;
		Camera a;
		Wheels wheel;
		currentQuadrant = 0;
		currentQuadrant = open.openGate();
		this.followLine(a,wheel);
	};

};
*/


int main(){
	init(0);
    double sector=1; //sector one = behind gate
	int debug = 1;
    open_screen_stream();
    Wheels wheels;
    Camera on;
    GateOpen open;
    if(debug == 0){            
    while(sector==1){
        sector = open.openGate(); //gate open method returns a number (2) when it completes
        //sector++;
    }
				//sector==1 <-- sector 2 is the line section
        while(sector==2){
                //on.runCamera(3); <-- already called in setSpeed() method
                wheels.setSpeed();
                hardware_exchange();
                take_picture(); 
                update_screen();
                printf("%0f",on.runCamera(1));
                
                //we should check if the line is even present to begin with here? If no: call reverse method
                
                //sleep1(0,500); //sleep, robot does not need to update every milisecond
                sleep1(500);
                if(on.runCamera(1)>10000){
					sector++;
					} //what is this for?
		}
				
        while(sector==3){
        //set up maze (sector 3)
        int direction=0;
			int leftW=50;
			int rightW=46;
			wheels.setSpeed();
       
        
			if(on.runCamera(3)<1000){
				if(direction==1 ||direction==2||direction==5||direction==7){
				set_motors(1,leftW+10);
				set_motors(5,46);
				}
				if(direction==3 ||direction==4||direction==6){
					set_motors(5,rightW-10);
					set_motors(1,50);
				}
				sleep1(1000);
				direction++;
			}
        
			hardware_exchange();take_picture(); update_screen();
       }
        
        
        
        
        
        //when sector 3 (maze) is complete, change the camera position
        
        while(sector == 4){
		//drive towards the first 'duck tower' (colour: Red)
		//drive towards the second tower (Color: Green)
		//drive towards final tower (Color: Blue)
			
		}     
	}
	if(debug == 1){
		
		for(int tst = 0; tst < 30 ; tst++){
		//get the robot to move faster
		
        take_picture(); 
        update_screen();
        
        wheels.setSpeed();
        
        hardware_exchange();
        
        printf("%0f",on.runCamera(1));
        
        //sleep1(500);
		  }  
             
                
             
                sleep1(500);
		//test reverse func
		wheels.stop();
		for(int tst = 0; tst < 10; tst++){
		double err = on.runCamera(3);
		printf("%0f",err);
		wheels.reverse();
			}
		}
        close_screen_stream();
        return 0;
        };