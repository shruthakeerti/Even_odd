
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "Board_LED.h"                  // ::Board Support:LED

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_LED': LED thread
 *---------------------------------------------------------------------------*/
 
void Thread_LED (void const *argument);                 // thread function
osThreadId tid_Thread_LED;                              // thread id
osThreadDef(Thread_LED, osPriorityNormal, 1, 0);        // thread object


void Thread_LED1 (void const *argument);                 // thread function
osThreadId tid_Thread_LED1;                              // thread id
osThreadDef(Thread_LED1, osPriorityNormal, 1, 0);        // thread object


osSemaphoreDef(sem1);
osSemaphoreId sem1ID;

int Init_Thread_LED (void) {

  
	sem1ID = osSemaphoreCreate(osSemaphore(sem1),1);
	tid_Thread_LED = osThreadCreate(osThread(Thread_LED), NULL);
	tid_Thread_LED1 = osThreadCreate(osThread(Thread_LED1), NULL);
}

void Thread_LED (void const *argument) {
  
	for(;;)
	{
		osSemaphoreWait(sem1ID,osWaitForever);
		LED_On(3);
		osDelay(3000);
		LED_Off(3);
		osDelay(100);
		osSemaphoreRelease(sem1ID);
	}

	
}


void Thread_LED1 (void const *argument) {
  
	for(;;)
	{
		osSemaphoreWait(sem1ID,osWaitForever);
		LED_On(2);
		osDelay(200);
		LED_Off(2);
		osDelay(1000);
		osSemaphoreRelease(sem1ID);
	}

	
}



