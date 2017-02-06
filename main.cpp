/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T23:07:28+00:00
*/

#include "mbed-os/mbed.h"
#include "LM75B.h"
//#include "C12832.h"
#include <map>
#include <sstream>
#include <stdio.h>

#include "IOManager/Outputs/AOutput.hh"
#include "IOManager/Outputs/Screen.hh"
#include "IOManager/Outputs/Host.hh"
#include "IOManager/IOManager.hh"
#include "IOManager/Inputs/UserInput/Switch.hh"
#include "IOManager/Inputs/UserInput/UserInput.hh"
#include "IOManager/Inputs/UserInput/Joystick.hh"
#include "IOManager/Inputs/SensorInput/Temperature.hh"
#include "IOManager/Outputs/Light.hh"
#include "mj344/ServiceManager.hh"
//DigitalOut h(LED1);
// DigitalOut red(LED3);
//DigitalOut green(LED2);
//DigitalIn sw(SW2);


AnalogIn pot(A0);

//LM75B sensor(I2C_SDA, I2C_SCL);

//Light lol(Light::SHIELD);

//Serial pc(USBTX, USBRX);

// C12832 shld_lcd (D11, D13, D12, D7, D10);   /* LCD */
//
//
// Temperature t;
// IOManager manager;
// void hello(const UserInput::Type tp) {
// 	lol.updateState((Light::Color)tp);
//
// 	if (tp == UserInput::LEFT) {
// 		manager.display(t.getPreviousUnit());
// 	} else if (tp == UserInput::RIGHT) {
// 		manager.display(t.getNextUnit());
// 	}
//
// }

int main() {

    int i;
	//Joystick jst(&hello);
	ServiceManager sm;
	sm.start();

	while (1) {
		wait(1);
	}

    // Screen scr;
    // std::string str("Saluuuutloluzebduyizebyeurfreyugferuyfgreyufg");
    //shld_lcd.locate (0 , 10);
      //  shld_lcd.printf ("Eh salut \n");
    // Host pc;
    //



	//Switch sw(SW2, &hello);

    //
     //while (1) {

		// std::map<std::string, float> map = t.getData();
		//
		// std::ostringstream stringStream;
  // 		stringStream << map["temp"];

		// std::vector<std::string> hello = t.getUnits();
		//
		// for (std::vector<std::string>::iterator it = hello.begin() ; it != hello.end(); ++it) {
		// 	manager.display(*it);
		// 	wait(0.5);
		// }

//		 manager.display(stringStream.str());

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
    //      wait(0.5);
    //  }
}
