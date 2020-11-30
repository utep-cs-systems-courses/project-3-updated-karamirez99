COMMON_OBJECTS =
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../../h
LDFLAGS	       = -L../../lib -L/opt/ti/msp430_gcc/include
CC	       = msp430-elf-gcc
AS 	       = msp430-elf-as -mmcu=${CPU} -c

all: lab3.elf

lab3.elf: ${COMMON_OBJECTS} main.o buzzer.o handler.o led.o switches.o p2_interrupt_handler.o game.o snake.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lShape -lCircle

load: lab3.elf
	msp430loader.sh lab3.elf

clean:
	rm -f *.o *.elf



buzzer.o: buzzer.h
#InterruptHandler.o: song.h stateMachine.h buzzer.h
led.o: led.h
switches.o: switches.h
snake.o: snake.h
game.o: game.h snake.h
