#include "CanBusMsg.h"
#include "QEI.h"
#include <cstdint>

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
//Encoder parameter setup
//Encoder 1 pin
#define EncoderL_A PB_0
#define EncoderL_B PB_7
//Encoder 2 pin
#define EncoderR_A PB_6
#define EncoderR_B PB_1

//Encoder 3 pin
#define EncoderAUX_A PB_5
#define EncoderAUX_B PB_4

const int Encoder_PPR = 512;
const float Encoder_Omni_Wheel_Radius = 25.4; //Radius of the Omni Wheel 
const float omni_wheel = 2 * M_PI * Encoder_Omni_Wheel_Radius;

QEI EncoderL(EncoderL_A, EncoderL_B, NC, Encoder_PPR);
QEI EncoderR(EncoderR_A, EncoderR_B, NC, Encoder_PPR);
QEI EncoderAUX(EncoderAUX_A, EncoderAUX_B, NC, Encoder_PPR);
Timer t1; 

int main()
{
    int32_t prev_L = 0;
    int32_t prev_R = 0;
    int32_t dt = 0; 

    t1.start();
    while (true) { 
        //calculat the Encoder distance in mm
        L = (int32_t) ceil(EncoderL.getPulses() * omni_wheel / Encoder_PPR);
        R = (int32_t) ceil(EncoderR.getPulses() * omni_wheel / Encoder_PPR);
        AUX = (int32_t) ceil(EncoderAUX.getPulses() * omni_wheel / Encoder_PPR);

        CAN_Send_Msg1();
        CAN_Send_Msg2();
    }
}


