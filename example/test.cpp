#include <stdio.h>

#include "Remote_Data_Parser.h"

RemoteControllerData rcdata ; 

int main(void)
{
	unsigned char can_data[8] = {0xD2, 0x00, 0x00, 0x00, 0x64, 0x64, 0x64, 0x64} ;

	RemoteControllerData rcdata = Remote_Data_Parser(can_data, 8) ;
		
    return 0 ;
}