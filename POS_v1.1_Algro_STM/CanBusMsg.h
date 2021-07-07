#include "mbed.h"
#include <cstdint>
//parameter 
int32_t x = 0;
int32_t y = 0;
int32_t Vx = 0;
int32_t Vy = 0;

#define CAN1_RD PA_11
#define CAN1_TD PA_12
#define CAN1_Freq 1000000
CAN can1(CAN1_RD, CAN1_TD,CAN1_Freq);

void CAN_Send_Msg1()
{
    CANMessage TxMessage1;                  //transmit 1 message //
    TxMessage1.id=0x70;                    // Command ID is 0x30
    TxMessage1.format=CANStandard;
    TxMessage1.type=CANData;
    TxMessage1.len=8;                       //Msg length
    
    TxMessage1.data[0] = x >> 24;           //Vx upper 8 bits 
    TxMessage1.data[1] = x >> 16;           //Vx lower 8 bits 
    TxMessage1.data[2] = x >> 8;            //Vy upper 8 bits 
    TxMessage1.data[3] = x;                 //Vy lower 8 bits  
    TxMessage1.data[4] = y >> 24;           //Vz upper 8 bits
    TxMessage1.data[5] = y >> 16;           //Vz lower 8 bits 
    TxMessage1.data[6] = y >> 8;           //Empty 
    TxMessage1.data[7] = y;
    
    if (can1.write(TxMessage1)) {           //Send the Message
        //printf("Sent pos1\r");
    }
     else {
        can1.reset();                        // Reset CANbus if there is a problem
    }
}
void CAN_Send_Msg2()
{
    CANMessage TxMessage1;                  //transmit 1 message //
    TxMessage1.id=0x71;                    // Command ID is 0x30
    TxMessage1.format=CANStandard;
    TxMessage1.type=CANData;
    TxMessage1.len=8;                       //Msg length
    
    TxMessage1.data[0] = Vx >> 24;           //Vx upper 8 bits 
    TxMessage1.data[1] = Vx >> 16;           //Vx lower 8 bits 
    TxMessage1.data[2] = Vx >> 8;            //Vy upper 8 bits 
    TxMessage1.data[3] = Vx;                 //Vy lower 8 bits  
    TxMessage1.data[4] = Vy >> 24;           //Vz upper 8 bits
    TxMessage1.data[5] = Vy >> 16;           //Vz lower 8 bits 
    TxMessage1.data[6] = Vy >> 8;           //Empty 
    TxMessage1.data[7] = Vy;
    
    if (can1.write(TxMessage1)) {           //Send the Message
        //printf("Sent pos1\r");
    }
     else {
        can1.reset();                        // Reset CANbus if there is a problem
    }
}