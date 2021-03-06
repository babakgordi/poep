#include "BrickPi3.h"
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <iomanip>

using namespace std;

BrickPi3 BP;

void exit_signal_handler(int signo);

void stop(void){
	BP.set_motor_power(PORT_B, 0);
	BP.set_motor_power(PORT_C, 0);
}


int main(){
	signal(SIGINT, exit_signal_handler);
	
	BP.detect();
	
	int error;
	
	BP.set_sensor_type(PORT_2, SENSOR_TYPE_NXT_ULTRASONIC);
	BP.offset_motor_encoder(PORT_B, BP.get_motor_encoder(PORT_B));
	BP.offset_motor_encoder(PORT_C, BP.get_motor_encoder(PORT_C));
	
	sensor_ultrasonic_t Ultrasonic2;
	
	while(true){
		error = 0;
		int32_t EncoderB = BP.get_motor_encoder(PORT_B);
		int32_t EncoderC = BP.get_motor_encoder(PORT_C);
		
		if(BP.get_sensor(PORT_2, Ultrasonic2) == 0){
			cout << "Afstand met object: " << Ultrasonic2.cm << "cm" << "\n";
			float range = Ultrasonic2.cm;
			cout << range;
			if(range > 10){
				BP.set_motor_position_relative(PORT_B, 360);
				BP.set_motor_position_relative(PORT_C, 360);
				usleep(500000);
			}
		}
		sleep(2);
	}
}

void exit_signal_handler(int signo){
	if(signo == SIGINT){
		BP.reset_all();
		exit(-2);
	}
}