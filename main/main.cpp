#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "Button.h"
#include "Led.h"
#include "Lights.h"

#ifdef __cplusplus
extern "C" {
#endif

#define taskDelay_ms(ms)	vTaskDelay(ms / portTICK_PERIOD_MS )

void task (void * pvParameters){
	Lights * pLights = (Lights *) pvParameters;

	for(;;){
		pLights->executeModePhase();
	}
}

void app_main(void)
{
	printf("Zacina main\n");

	Button button = Button(GPIO_NUM_4, Button::INTERNAL_PULL_UP);
	Led ledBlue(GPIO_NUM_2, Led::ACTIVE_HIGH, false);
	Led ledRed(GPIO_NUM_5, Led::ACTIVE_HIGH, false);

	Lights lights(ledBlue, ledRed);

	TaskHandle_t xHandle = NULL;
	xTaskCreate( task, "task", 1000, &lights, 2, &xHandle );


    while (true) {
    	if(button.isPressed()){
    		lights.nextMode();
    		taskDelay_ms(10);

    		while(button.isPressed());
    	}

    	taskDelay_ms(10);
    }

    if( xHandle != NULL )
	{
	 vTaskDelete( xHandle );
	}
}


#ifdef __cplusplus
}
#endif

