#include"sdk_project_config.h"
#include <stdint.h>
#include "interior_light_model.h"
<<<<<<< HEAD

flexcan_state_t canState;
flexcan_data_info_t rx_info = {.msg_id_type = FLEXCAN_MSG_ID_STD,.data_length = 1,.is_remote = false};

void door_process(const flexcan_msgbuff_t *rxData){

	if((rxData->msgId == 0x100)&&((rxData->dataLen >= 1U))){

		uint8_t door_status=rxData->data[0];

		interior_light_model_U.FL=(door_status>>0u)&1u;
		interior_light_model_U.FR=(door_status>>1u)&1u;
		interior_light_model_U.RL=(door_status>>2u)&1u;
		interior_light_model_U.RR=(door_status>>3u)&1u;

	}
	else{
		return ;
	}
}
int main(void){

	CLOCK_DRV_Init(&clockMan1_InitConfig0);
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0,g_pin_mux_InitConfigArr0);
	FLEXCAN_DRV_Init(INST_FLEXCAN_CONFIG_1, &flexcanState0, &flexcanInitConfig0);

	flexcan_msgbuff_t rxData;

	FLEXCAN_DRV_ConfigRxMb(INST_FLEXCAN_CONFIG_1, 0, &rx_info,0x100);

	while(1){

		FLEXCAN_DRV_Receive(INST_FLEXCAN_CONFIG_1, 0, &rxData);
		door_process(&rxData);
		interior_light_model_step();

		if(interior_light_model_Y.light==1){
			PINS_DRV_ClearPins(PTD, 1<<15);
		}
		else{
			PINS_DRV_SetPins(PTD, 1<<15);
		}
=======

flexcan_state_t canState;
flexcan_data_info_t rx_info = {.msg_id_type = FLEXCAN_MSG_ID_STD,.data_length = 1,.is_remote = false};

volatile uint8_t current_duty=0;
uint8_t target_duty;
int8_t direction=1;

void door_process(const flexcan_msgbuff_t *rxData){

	if((rxData->msgId == 0x100)&&((rxData->dataLen >= 1U))){

		uint8_t door_status=rxData->data[0];

		interior_light_model_U.FL=(door_status>>0u)&1u;
		interior_light_model_U.FR=(door_status>>1u)&1u;
		interior_light_model_U.RL=(door_status>>2u)&1u;
		interior_light_model_U.RR=(door_status>>3u)&1u;

	}

	else{
		return ;
>>>>>>> 848f3a0 (final_commit)
	}

}

int main(void){

	CLOCK_DRV_Init(&clockMan1_InitConfig0);
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0,g_pin_mux_InitConfigArr0);
	PWM_Init(&pwm_pal_1_instance, &pwm_pal_1_configs);
	FLEXCAN_DRV_Init(INST_FLEXCAN_CONFIG_1, &flexcanState0, &flexcanInitConfig0);

	flexcan_msgbuff_t rxData;

	FLEXCAN_DRV_ConfigRxMb(INST_FLEXCAN_CONFIG_1, 0, &rx_info,0x100);

	while(1){

		FLEXCAN_DRV_Receive(INST_FLEXCAN_CONFIG_1, 0, &rxData);
		door_process(&rxData);
		interior_light_model_step();

		if(interior_light_model_Y.light==1){

			target_duty=100;
			for(int i=current_duty;i<=target_duty;i+=5){
				PWM_UpdateDuty(&pwm_pal_1_instance, 0u, i);
				current_duty=i;
				OSIF_TimeDelay(100);
			}
		}
		else{

			target_duty=0;
			for(int i=current_duty;i>=target_duty;i-=5){
				PWM_UpdateDuty(&pwm_pal_1_instance, 0u, i);
				current_duty=i;
				OSIF_TimeDelay(100);
			}
		}
	}
}
