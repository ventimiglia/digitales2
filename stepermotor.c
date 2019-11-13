#include "chip.h"
#include "board.h"
#include <cr_section_macros.h>
#define port 0
#define output 1
#define pGPIO LPC_GPIO

bool dir = 1;
uint8_t _step = 0;
uint8_t tiempo=0;

void InitHardware(void);
void InitSetOutput (void);
void Girar (void);
void delay (void);

int main(void) {

	InitHardware();
	InitSetOutput();

    while(1) {
    	if(tiempo==100){
    	Girar();
    	tiempo=0;
    	}
    }
    return 0 ;
}

void InitHardware (void) {
    SystemCoreClockUpdate();
    Board_Init();
    Board_LED_Set(0, true);
    SysTick_Config(SystemCoreClock/1000);
}

void InitSetOutput (void) {
	Chip_GPIO_SetPinDIROutput(pGPIO, port, 6);
	//Chip_GPIO_SetPinOutLow(LPC_GPIO, 1, 6);
	Chip_GPIO_SetPinDIROutput(pGPIO, port, 7);
	//Chip_GPIO_SetPinOutLow(LPC_GPIO, 1, 7);
	Chip_GPIO_SetPinDIROutput(pGPIO, port, 8);
	//Chip_GPIO_SetPinOutLow(LPC_GPIO, 1, 8);
	Chip_GPIO_SetPinDIROutput(pGPIO, port, 9);
	//Chip_GPIO_SetPinOutLow(LPC_GPIO, 1, 9);
}

void SysTick_Handler (void) {
	tiempo++;
}
void Girar (void) {
	switch (_step){
	case 0:
		Chip_GPIO_SetPinOutLow(pGPIO,port,6);
		Chip_GPIO_SetPinOutLow(pGPIO,port,7);
		Chip_GPIO_SetPinOutLow(pGPIO,port,8);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,9);
	break;
	case 1:
		Chip_GPIO_SetPinOutLow(pGPIO,port,6);
		Chip_GPIO_SetPinOutLow(pGPIO,port,7);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,8);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,9);
	break;
	case 2:
		Chip_GPIO_SetPinOutLow(pGPIO,port,6);
		Chip_GPIO_SetPinOutLow(pGPIO,port,7);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,8);
		Chip_GPIO_SetPinOutLow(pGPIO,port,9);
	break;
	case 3:
		Chip_GPIO_SetPinOutLow(pGPIO,port,6);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,7);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,8);
		Chip_GPIO_SetPinOutLow(pGPIO,port,9);
	break;
	case 4:
		Chip_GPIO_SetPinOutLow(pGPIO,port,6);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,7);
		Chip_GPIO_SetPinOutLow(pGPIO,port,8);
		Chip_GPIO_SetPinOutLow(pGPIO,port,9);
	break;
	case 5:
		Chip_GPIO_SetPinOutHigh(pGPIO,port,6);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,7);
		Chip_GPIO_SetPinOutLow(pGPIO,port,8);
		Chip_GPIO_SetPinOutLow(pGPIO,port,9);
	break;
	case 6:
		Chip_GPIO_SetPinOutHigh(pGPIO,port,6);
		Chip_GPIO_SetPinOutLow(pGPIO,port,7);
		Chip_GPIO_SetPinOutLow(pGPIO,port,8);
		Chip_GPIO_SetPinOutLow(pGPIO,port,9);
	break;
	case 7:
		Chip_GPIO_SetPinOutHigh(pGPIO,port,6);
		Chip_GPIO_SetPinOutLow(pGPIO,port,7);
		Chip_GPIO_SetPinOutLow(pGPIO,port,8);
		Chip_GPIO_SetPinOutHigh(pGPIO,port,9);
	break;
	default:
		Chip_GPIO_SetPinOutLow(pGPIO,port,6);
		Chip_GPIO_SetPinOutLow(pGPIO,port,7);
		Chip_GPIO_SetPinOutLow(pGPIO,port,8);
		Chip_GPIO_SetPinOutLow(pGPIO,port,9);
	break;
	}

	if(dir)
	{
		_step++;
	}else
		{
			_step--;
		}
	if(_step>7) {
			_step=0;
	}
	if(_step<0) {
			_step=7;
		}
}

