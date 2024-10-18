#include <stdio.h>

#include "Remote_Data_Parser.h"

RemoteControllerData rcdata ; 

int main(void)
{
	unsigned char can_data[8] = {0x64, 0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00} ;

	RemoteControllerData rcdata = Remote_Data_Parser(can_data, 8) ;

	printf("----\n") ;
	printf("RDV Remote can data pserser\n") ;
	printf("[1] Left Joystick : %d(V), %d(H)\n", rcdata.joystick_left_vertical, rcdata.joystick_left_horizontal) ;
	printf("[2] Right Joystick : %d(V), %d(H)\n", rcdata.joystick_right_vertical, rcdata.joystick_right_horizontal) ;
	printf("[3] Push Button : A(%d), B(%d), C(%d), D(%d)\n", rcdata.button_a, rcdata.button_b, rcdata.button_c, rcdata.button_d) ;
	printf("[4] Slide Button : Center(%d), Left(%d), Right(%d)\n", rcdata.slide_center, rcdata.slide_left, rcdata.slide_right) ;
	printf("[4] Dial Button : Left(%d), Right(%d)\n", rcdata.dial_left, rcdata.dial_right) ;
	printf("\n\n") ;
		
    return 0 ;
}