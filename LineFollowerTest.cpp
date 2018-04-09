#include "BrickPi3.h"
#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

BrickPi3 BP;

void exit_signal_handler(int signo);

uint16_t MIN;
uint16_t MAX;
sensor_color_t mycolor;

int16_t measureLight() {
    
    BP.get_sensor(PORT_1, mycolor);
    uint16_t val = mycolor.reflected_red;
    if (val < MIN) val = MIN;
    if (val > MAX) val = MAX;
    return (100*(val - MIN))/(MAX - MIN);
}

int main(){
    signal(SIGINT, exit_signal_handler);
    BP.detect();
    BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_RED);
    
    string line;
    cout << "Houd de sensors over zwart > A > Enter" << "\n";
    cin >> line;
    BP.get_sensor(PORT_1, mycolor);
    MIN = mycolor.reflected_red;
    cout << "MIN = " << MIN << "\n";
    cout << "Houd de sensors voer wit > B >  Enter" << endl;
    cin >> line;
    BP.get_sensor(PORT_1, mycolor);
    MAX = mycolor.reflected_red;
    cout << "Maxiumum = " << MAX << "\n";
    cout << "> C > ENTER HALF" << endl;
    cin >> line;
    
    int16_t lightval;
    int16_t power = -20;
    while(true){
        lightval = measureLight();
        if (lightval <= 50){
            BP.set_motor_power(PORT_B, lightval*power/50);
            BP.set_motor_power(PORT_C, power);
        }
        if (lightval > 50) {
            BP.set_motor_power(PORT_B, power);
            BP.set_motor_power(PORT_C, (100-lightval)*power/50);
        }
        sleep(0.1);
    }
}
void exit_signal_handler(int signo){
    if(signo == SIGINT){
        BP.reset_all();
        exit(-2);
    }
}
