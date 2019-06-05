#include <stdio.h> 
#include "E101.h" 
#include <unistd.h> 
#include <time.h>
//run robot needs fields for //current quadrant //camera position 
//rubRobot needs to create new //camera object //network object //wheel 
//objects main method 
class Camera{
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
                                                {pix [countc] = 
(int)get_pixel(120,countc,col);
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
        }printf("\n");
                                                return finalError;
                                                };
                                                
                                                
                                                
                                                int returnColour(int colour){
													int totalColour=0;
													int countc =0;
													while(countc <320){
													totalColour+=(int)get_pixel(120,countc,colour);
                                                        countc++;}
                                                        
													return totalColour;
												};
};
class GateOpen{
        //fields here
        private:
        char serverAddress[15] = { '1','3','0','.','1','9','5','.','6','.','1','9','6' }; //char 
		char server_addr[15] = { '1','2','7','.','0','0','1','.','0','0','1','.','0','0','1' }; //TEST THE  ADDRESS
        int port = 1024; //need to find what the port number is0
        char message[24] = { "Please" }; //find what the message should 
//b1024
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
		set_motors(1,51);
		set_motors(5,42);
		hardware_exchange();
		sleep1(3500);
                return 2;
        }; 
	};
class Wheels{
        //fields here
        private:
        Camera a;
        int leftW=50; //48+2 = 50, speed = 2 -- curent spped is 4
        int rightW=46; //48-2 = 46, speed = 2
        double kp=0.06;
        public:
                               // int speedDiff;
                double errorRate=0;
                double finalError; /*
 * Changes the speed of the motor, to keep the robot following the line.
 * DOES NOT update the motor speed.
 * */ void setSpeed(){
	int speedDiff = 0;
errorRate = 0;
finalError = 0;
        a.runCamera(3);
        finalError=a.runCamera(3);
        printf("%f finalError \n",finalError);
        speedDiff=0+(finalError*kp);
	if(speedDiff > 4){speedDiff = 3;}else if(speedDiff < -4){speedDiff = -3;};
        printf("speedDiff %d ",speedDiff);
       // printf(" %f",finalError);
	
                set_motors(1,leftW+speedDiff);
                set_motors(5,rightW+speedDiff);
};
void stop(){
                set_motors(1, 48);
                set_motors(5, 48);
        };
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
/*class RunRobot{
        //fields here
        public:
        //methods here
        };*/
int main(){
        init(0);
    //double sector=2; //sector one = behind gate
    double sector=1; //sector one = behind gate
        int debug = 0;
        int direction=0;
    open_screen_stream();
    Wheels wheels;
    Camera on;
    GateOpen open;
    if(debug == 0){
    while(sector==1){
                wheels.stop();
                hardware_exchange();
        open.openGate(); //gate open method returns a number (2) when it completes
        sector++;
        printf("Gate opened");
        
    }
        /*If stuff breaks, just comment this while loop out*/                        
        while(sector==2){
								/*on.runCamera(3);
								take_picture();
								update_screen();
								wheels.setSpeed(); hardware_exchange();
								//printf("%0f",on.runCamera(1));
								//we should check if the line is even present to begin with here? If no: call reverse method
								//sleep1(0,500); //sleep, robot does not need to update every milisecond
								sleep1(100);
								printf("redness %d",on.returnColour(1));
								if(on.returnColour(1)<35000){
                                        sector++;
                                        } //what is this for?*/

    wheels.setSpeed();
    hardware_exchange();
    take_picture(); 
	update_screen();
	
	sleep1(100);
	
	//When the robot drives over the red square, exit this loop -- threshold is not configured
	printf("redness %d green %d blue %d R-G diff: %d",on.returnColour(0),on.returnColour(1),on.returnColour(2),on.returnColour(0)-on.returnColour(1));
	if(on.returnColour(0)-on.returnColour(1) > 10000){ //If the difference between the amount of green & red exceeds the threshold, increment the sector -- This works reliably
     // sector++;
      
             }
        }
        while(sector==3){
        //set up maze (sector 3)
        
                        int leftW=50;
                        int rightW=46;
                        wheels.setSpeed();
                        //printf("black value %0d \n",on.returnColour(3));
                        printf("black value %0d \n",on.returnColour(1));
                        //if(on.returnColour(3)<15000){//changed threshld from 15,000 to 40,000
                        if(on.returnColour(1)<32000 && on.returnColour(1) > 20000){
                                if(direction==3 ||direction==5||direction==8||direction==10){
                                set_motors(1,leftW+10);
                                set_motors(5,46);
                                //maybe this will fix it, set_motor needs hardware_exchange to actually change the speed
									hardware_exchange();
                                sleep1(1000);
                        }
                        
                                if(direction==6 ||direction==7||direction==9){
                                        set_motors(5,rightW-10);
                                        set_motors(1,50);
                                        //maybe this will fix it, set_motor needs hardware_exchange to actually change the speed
											hardware_exchange();
                                sleep1(1000);
                                }
                                
                                direction++;
                                if(direction > 11){
									wheels.stop();
									return 0;
									}
                        
}
                        hardware_exchange();take_picture(); 
update_screen();
printf("direction %0d \n",direction);
       }
        //when sector 3 (maze) is complete, change the camera position
        while(sector == 4){
                //drive towards the first 'duck tower' (colour: Red)
                //drive towards the second tower (Color: Green)
                //drive towards final tower (Color: Blue)
                }
        }
        return 0;
        };
        
