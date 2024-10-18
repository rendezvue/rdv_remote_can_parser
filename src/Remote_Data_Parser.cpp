#include "Remote_Data_Parser.h"

RemoteControllerData Remote_Data_Parser(unsigned char* data, const int length)
{
    RemoteControllerData rcdata ;

	//8bye 길이 확인
	if( length != 8 ) return rcdata;

	//1 : left_horizontal
	unsigned char left_horizontal = data[0] ;
	rcdata.joystick_left_horizontal = (int)left_horizontal - 100 ;

	//2 : left_vertical
	unsigned char left_vertical = data[1] ;
	rcdata.joystick_left_vertical = (int)left_vertical - 100  ;

	//3 : right_horizontal
	unsigned char right_horizontal = data[2] ;
	rcdata.joystick_right_horizontal = (int)right_horizontal - 100 ;

	//4 : right_vertical
	unsigned char right_vertical = data[3] ;
	rcdata.joystick_right_vertical = (int)right_vertical - 100 ;

	//5 : button
	unsigned char button = data[4] ;
	//a
	if( button & 0x01 ) rcdata.button_a = BUTTON_ON ;
	else				rcdata.button_a = BUTTON_OFF ;
	//b
	if( button & 0x02 ) rcdata.button_b = BUTTON_ON ;
	else				rcdata.button_b = BUTTON_OFF ;
	//c
	if( button & 0x04 ) rcdata.button_c = BUTTON_ON ;
	else				rcdata.button_c = BUTTON_OFF ;
	//d
	if( button & 0x08 ) rcdata.button_d = BUTTON_ON ;
	else				rcdata.button_d = BUTTON_OFF ;

	//6 : slide
	unsigned char slide = data[5] ;
	//center
	unsigned char slide_data = (slide >> 4) & 0x03 ;
	if( slide_data == 0x00  ) 		rcdata.slide_center = SLIDE_CENTER ;		
	else if( slide_data == 0x02  ) 	rcdata.slide_center = SLIDE_UP ;		
	else if( slide_data == 0x01  ) 	rcdata.slide_center = SLIDE_DOWN ;		
	//left
	slide_data = (slide >> 2) & 0x03 ;
	if( slide_data == 0x00  ) 		rcdata.slide_left = SLIDE_CENTER ;		
	else if( slide_data == 0x02  ) 	rcdata.slide_left = SLIDE_UP ;		
	else if( slide_data == 0x01  ) 	rcdata.slide_left = SLIDE_DOWN ;		
	//right
	slide_data = (slide >> 0) & 0x03 ;
	if( slide_data == 0x00  ) 		rcdata.slide_right = SLIDE_CENTER ;		
	else if( slide_data == 0x02  ) 	rcdata.slide_right = SLIDE_UP ;		
	else if( slide_data == 0x01  ) 	rcdata.slide_right = SLIDE_DOWN ;		

	//7 : dial
	unsigned char dial = data[6] ;
	//left
	unsigned char dial_data = (dial >> 2) & 0x03 ;
	if( dial_data == 0x00  ) 		rcdata.dial_left = DIAL_CENTER ;		
	else if( dial_data == 0x02  ) 	rcdata.dial_left = DIAL_UP ;		
	else if( dial_data == 0x01  ) 	rcdata.dial_left = DIAL_DOWN ;		
	//right
	dial_data = (dial >> 0) & 0x03 ;
	if( dial_data == 0x00  ) 		rcdata.dial_right = DIAL_CENTER ;		
	else if( dial_data == 0x02  ) 	rcdata.dial_right = DIAL_UP ;		
	else if( dial_data == 0x01  ) 	rcdata.dial_right = DIAL_DOWN ;		

	//count
	rcdata.count = data[7]  ; 

    return rcdata ;
}