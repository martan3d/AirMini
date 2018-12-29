#include <dcc.h>
#include <spi.h>
#include <uart.h>
#include <schedule.h>
#include <servotimer.h>


int64_t now;
int64_t then;

uint8_t sendbuffer[sizeof(DCC_MSG)];
uint8_t * dccptr;
uint8_t flag;

#define BACKGROUNDTIME 32000                  // @16Mhz, this is 8ms
#define RXMODE         0x34                   // C1101 modem RX mode
#define OURDCCADDR     3                      // Use default for now

void setup() {

  DDRB |= 1;                                  // Use this for debugging
  initUART(9600);                             // More debugging, send serial data out
  initServoTimer();                           // Master Timer plus servo timer
  initializeSPI();                            // Initialize the SPI interface to the radio
  dccInit();                                  // Enable DCC receive
  startModem(0);                              // Start on Channel zero
  
  sei();                                      // enable interrupts
  
  then = getMsClock();                        // Grab Current Clock value

}


void loop() {

        /* Check High Priority Tasks First */

        switch( masterSchedule() )
         {
             case TASK0:                       // Highest Priority Task goes here

                  clearScheduledTask(TASK0);
                  break;

             case TASK1:                       // Just pick a priority for the DCC packet 
                     dccptr = getDCC();        // a packet has been assembled, get a pointer to our DCC data
                     flag = 0;                 // see if it is a different message than what we already have

                     for (uint8_t j=0;j<5;j++)
                        if (sendbuffer[j] != dccptr[j])
                           flag = 1;           // yes, something is different, it needs to go out
                
                     if (dccptr[0] == 0xff) flag=0;    // this needs to be thought out better for sending, don't send trash

                     if(flag)                     // only send if it's changed since last time
                     {
                      for (uint8_t j=0;j<5;j++)
                         SendByte(dccptr[j]);
                     }
                     
                     clearScheduledTask(TASK1);
                  break;
         }

         /* After checking highest priority stuff, check for the timed tasks */

        now = getMsClock() - then;             //
        
         if( now > BACKGROUNDTIME )            // Check for Time Scheduled Tasks
           { 
              then = getMsClock();             // Grab Clock Value for next time
              sendReceive(RXMODE);      // keep the radio awake in RX mode
              //SendByte('X');            // You are here debug, send X out serial port
              PORTB ^= 1;
          }
}
