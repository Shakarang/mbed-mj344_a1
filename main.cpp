/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T12:20:06+00:00
*/

#include "mbed-os/mbed.h"
#include "LM75B.h"
//#include "C12832.h"

#include <sstream>

#include "IOManager/Outputs/AOutput.hh"
#include "IOManager/Outputs/Screen.hh"
#include "IOManager/Outputs/Host.hh"
#include "IOManager/IOManager.hh"
#include "IOManager/Inputs/UserInput/Switch.hh"
#include "IOManager/Inputs/UserInput/UserInput.hh"
#include "IOManager/Inputs/UserInput/Joystick.hh"
#include "IOManager/Outputs/Light.hh"
//DigitalOut h(LED1);
// DigitalOut red(LED3);
//DigitalOut green(LED2);
//DigitalIn sw(SW2);


AnalogIn pot(A0);

LM75B sensor(I2C_SDA, I2C_SCL);

Light lol(Light::SHIELD);

//Serial pc(USBTX, USBRX);

// C12832 shld_lcd (D11, D13, D12, D7, D10);   /* LCD */
//
void hello(const UserInput::Type tp) {
	lol.updateState((Light::Color)tp);
}

int main() {

    int i;
	Joystick jst(&hello);


    // Screen scr;
    // std::string str("Saluuuutloluzebduyizebyeurfreyugferuyfgreyufg");
    //shld_lcd.locate (0 , 10);
      //  shld_lcd.printf ("Eh salut \n");
    // Host pc;
    //
    //IOManager manager;


	//Switch sw(SW2, &hello);

    //
     while (1) {

		//  for (int i = 0; i < 8; i++) {
		//  	lol.updateState((Light::Color)i);
		// 	wait(0.5);
		//  }

	// 	// shld_lcd.cls();
	// 	// shld_lcd.locate(0, 10);
	// 	// shld_lcd.printf("LOL\n");
	// 	// std::ostringstream ss;
	// 	// ss << pot;
	// 	// //str = pot;
	// 	//
    //     // // pc.print(str);
    //     // // scr.print(str);
    //     manager.log("Saluuuuuuuuuuut");
	// 	manager.display("OK");
	// 	// manager.printOnAllOutputs(ss.str());
    //     // if (sw) {
    //     //     red = 0;
    //     //     green = 1;
    //     // }
    //     // else {
    //     //     red = 1;
    //     //     green = 0;
    //     // }
	//
         wait(0.5);
     }
}
