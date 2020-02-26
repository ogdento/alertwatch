// *************************************************************************************************
//
//	Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
//	 
//	 
//	  Redistribution and use in source and binary forms, with or without 
//	  modification, are permitted provided that the following conditions 
//	  are met:
//	
//	    Redistributions of source code must retain the above copyright 
//	    notice, this list of conditions and the following disclaimer.
//	 
//	    Redistributions in binary form must reproduce the above copyright
//	    notice, this list of conditions and the following disclaimer in the 
//	    documentation and/or other materials provided with the   
//	    distribution.
//	 
//	    Neither the name of Texas Instruments Incorporated nor the names of
//	    its contributors may be used to endorse or promote products derived
//	    from this software without specific prior written permission.
//	
//	  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//	  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//	  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//	  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//	  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//	  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//	  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//	  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//	  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//	  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//	  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *************************************************************************************************
// Help functions.
// *************************************************************************************************


// *************************************************************************************************
// Include section

// system
#include "project.h"
#include <string.h>

// driver
#include "help.h"
#include "ports.h"
#include "display.h"
#include "timer.h"
#include "buzzer.h"
#include "rfsimpliciti.h"

// logic
#include "menu.h"


// *************************************************************************************************
// Prototypes section
void mx_help(u8 line);
void sx_help(u8 line);
void display_help(u8 line, u8 update);


// *************************************************************************************************
// Defines section


// *************************************************************************************************
// Global Variable section


// *************************************************************************************************
// Extern section


// *************************************************************************************************
// @fn          mx_help
// @brief       Long press Help alert routine. Called when * is held 3 secs.
// @param       u8 line	LINE1
// @return      none
// *************************************************************************************************
void mx_help(u8 line)
{
	// unused for now
	display_help(line, DISPLAY_LINE_UPDATE_FULL);
}


// *************************************************************************************************
// @fn          sx_help
// @brief       Help direct function. Called when UP is pressed.
//				beep, send help alert, and return to time
// @param       u8 line	LINE1
// @return      none
// *************************************************************************************************
void sx_help(u8 line)
{
	// send alert
	sx_ppt(2);
	
	// beep 5 times
	start_buzzer(5, CONV_MS_TO_TICKS(20), CONV_MS_TO_TICKS(150));
	// return to time
	button.all_flags = 1;
	button.flag.star = 1;

}


// *************************************************************************************************
// @fn          display_help /stopwatch
// @brief       Stopwatch user routine. Sx starts/stops stopwatch, but does not reset count.
// @param       u8 line	LINE2
//				u8 update	DISPLAY_LINE_UPDATE_PARTIAL, DISPLAY_LINE_UPDATE_FULL
// @return      none
// *************************************************************************************************
void display_help(u8 line, u8 update)
{
	if (update == DISPLAY_LINE_UPDATE_FULL)	
	{
		display_chars(LCD_SEG_L1_3_0, (u8 *)"HELP", SEG_ON);
	}
}
