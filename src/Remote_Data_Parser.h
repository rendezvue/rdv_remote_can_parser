#define BUTTON_OFF	false
#define BUTTON_ON	true

#define SLIDE_CENTER	0
#define SLIDE_UP		1
#define SLIDE_DOWN		2

#define DIAL_CENTER		0
#define DIAL_UP			1
#define DIAL_DOWN		2

typedef struct RemoteControllerData_
{
	//joystick
	int joystick_left_horizontal = 0 ;
	int joystick_left_vertical = 0 ;
	int joystick_right_horizontal = 0 ;
	int joystick_right_vertical = 0 ;

	//button
	bool button_a = BUTTON_OFF ;
	bool button_b = BUTTON_OFF ;
	bool button_c = BUTTON_OFF ;
	bool button_d = BUTTON_OFF ;

	//slide
	int slide_center = SLIDE_CENTER ;
	int slide_left = SLIDE_CENTER ;
	int slide_right = SLIDE_CENTER ;

	//dial
	int dial_left = DIAL_CENTER ;
	int dial_right = DIAL_CENTER ;

	//count
	int count = 0 ;
	
} RemoteControllerData ;
RemoteControllerData Remote_Data_Parser(unsigned char* data, const int length) ;
