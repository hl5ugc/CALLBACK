
#ifndef _SIO_INCLUDED_
#define _SIO_INCLUDED_

#pragma used+

#ifndef NULL
#define NULL 0
#endif

#define DATA_REGISTER_EMPTY (1<<UDRE0)
#define RX_COMPLETE (1<<RXC0)
#define FRAMING_ERROR (1<<FE0)
#define PARITY_ERROR (1<<UPE0)
#define DATA_OVERRUN (1<<DOR0)

void System_Init(void);
void canSetCallback(unsigned char ch, void (*callBack)(void));
#pragma used-
#endif

