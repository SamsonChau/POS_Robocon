#include "CanBusMsg.h"
#include "QEI.h"
#include <cstdint>

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
//Encoder parameter setup
//Encoder X pin
#define EncoderX_A PB_0
#define EncoderX_B PB_7
//Encoder Y pin
#define EncoderY_A PB_6
#define EncoderY_B PB_1

const int Encoder_PPR = 512;
const float Encoder_Omni_Wheel_Radius = 25.4; //Radius of the Omni Wheel 
const float omni_wheel = 2 * M_PI * Encoder_Omni_Wheel_Radius;

QEI EncoderX(EncoderX_A, EncoderX_B, NC, Encoder_PPR);
QEI EncoderY(EncoderY_A, EncoderY_B, NC, Encoder_PPR);
Timer t1; 

int main()
{
    int32_t prev_x = 0;
    int32_t prev_y = 0;
    int32_t dt = 0; 

    t1.start();
    while (true) { 
        //calculat the Encoder distance in mm
        x = (int32_t) ceil(EncoderX.getPulses() * omni_wheel / Encoder_PPR);
        y = (int32_t) ceil(EncoderX.getPulses() * omni_wheel / Encoder_PPR);
        
        //calculate the Encoder distance in mm/s
        t1.stop();
        dt = (int32_t)t1.elapsed_time().count();
        Vx = (int32_t)(x - prev_x) / dt;
        Vy = (int32_t)(y - prev_y) / dt;
        t1.start();

        CAN_Send_Msg1();
        CAN_Send_Msg2();
    }
}
