/*
 * dcc.h
 *
 * Created: 10/14/2015 6:26:13 PM
 *  Author: martan
 */ 
 
#ifdef __cplusplus
extern "C" {
#endif

#include <avr/io.h>

#ifndef DCC_H_
#define DCC_H_

#define DCCMAXLEN 5
typedef struct
{
    uint8_t Data[DCCMAXLEN];
    uint8_t New;
	uint8_t	Size;
    uint8_t Status;
	
} DCC_MSG ;

void dccInit(void);
uint8_t * getDCC();

#endif /* DCC_H_ */

#ifdef __cplusplus
}
#endif