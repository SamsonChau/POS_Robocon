#include "mbed.h"
#include <cstdint>
//parameter 
int32_t L = 0;
int32_t R = 0;
int32_t AUX = 0;

int32_t DL = 0;
int32_t DR = 0;
int32_t DAUX = 0;

#define CAN1_RD PA_11
#define CAN1_TD PA_12
#define CAN1_Freq 1000000
CAN can1(CAN1_RD, CAN1_TD,CAN1_Freq);

void CAN_Send_Msg1()
{
    CANMessage TxMessage1;                  //transmit 1 message //
    TxMessage1.id=0x80;                    // Command ID 
    TxMessage1.format=CANStandard;
    TxMessage1.type=CANData;
    TxMessage1.len=8;                       //Msg length
    
    TxMessage1.data[0] = L >> 24;           //Vx upper 8 bits 
    TxMessage1.data[1] = L >> 16;           //Vx lower 8 bits 
    TxMessage1.data[2] = L >> 8;            //Vy upper 8 bits 
    TxMessage1.data[3] = L;                 //Vy lower 8 bits  
    TxMessage1.data[4] = R >> 24;           //Vz upper 8 bits
    TxMessage1.data[5] = R >> 16;           //Vz lower 8 bits 
    TxMessage1.data[6] = R >> 8;           //Empty 
    TxMessage1.data[7] = R;
    
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
    TxMessage1.id=0x81;                    // Command ID 
    TxMessage1.format=CANStandard;
    TxMessage1.type=CANData;
    TxMessage1.len=8;                       //Msg length
    
    TxMessage1.data[0] = DL >> 24;           //Vx upper 8 bits 
    TxMessage1.data[1] = DL >> 16;           //Vx lower 8 bits 
    TxMessage1.data[2] = DL >> 8;            //Vy upper 8 bits 
    TxMessage1.data[3] = DL;                 //Vy lower 8 bits  
    TxMessage1.data[4] = DR >> 24;           //Vz upper 8 bits
    TxMessage1.data[5] = DR >> 16;           //Vz lower 8 bits 
    TxMessage1.data[6] = DR >> 8;           //Empty 
    TxMessage1.data[7] = DR;
    
    if (can1.write(TxMessage1)) {           //Send the Message
        //printf("Sent pos1\r");
    }
     else {
        can1.reset();                        // Reset CANbus if there is a problem
    }
}