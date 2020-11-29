COMMON_OBJECTS =
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include
CC	       = msp430-elf-gcc
AS 	       = msp430-elf-as

all: lab3.elf

lab3.elf: ${COMMON_OBJECTS} buzzer.o wdInterruptHandler.o led.o switches.o p2_interrupt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lShape -lCircle

load: lab3.elf
	msp430loader.sh lab3.elf

clean:
	rm -f *.o *.elf



buzzer.c: buzzer.h
#InterruptHandler.o: song.h stateMachine.h buzzer.h
led.c: led.h
switches.o: switches.h
