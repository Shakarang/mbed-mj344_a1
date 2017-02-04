/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-04T14:59:45+00:00
*/

#include "mbed-os/mbed.h"
#include "LM75B.h"
//#include "C12832.h"

#include <sstream>

#include "IOManager/Outputs/AOutput.hh"
#include "IOManager/Outputs/Screen.hh"
#include "IOManager/Outputs/Host.hh"
#include "IOManager/IOManager.hh"
#include "IOManager/Inputs/Switch.hh"
#include "IOManager/Inputs/UserInput.hh"

DigitalOut red(LED3);
//DigitalOut green(LED2);
//DigitalIn sw(SW2);


AnalogIn pot(A0);

LM75B sensor(I2C_SDA, I2C_SCL);

//Serial pc(USBTX, USBRX);

C12832 shld_lcd (D11, D13, D12, D7, D10);   /* LCD */

void hello(const UserInput::Type tp) {
	red = !red;
	shld_lcd.cls();
	shld_lcd.locate(0, 10);
	shld_lcd.printf("Triggered\n");
}

int main() {

    int i;

    // Screen scr;
    std::string str("Saluuuutloluzebduyizebyeurfreyugferuyfgreyufg");
    //shld_lcd.locate (0 , 10);
      //  shld_lcd.printf ("Eh salut \n");
    // Host pc;
    //
    IOManager manager;


	Switch sw(SW2, &hello);

    //
    while (1) {
		shld_lcd.cls();
		shld_lcd.locate(0, 10);
		shld_lcd.printf("LOL\n");
		// std::ostringstream ss;
		// ss << pot;
		// //str = pot;
		//
        // // pc.print(str);
        // // scr.print(str);
		// manager.printOnAllOutputs(ss.str());
        // if (sw) {
        //     red = 0;
        //     green = 1;
        // }
        // else {
        //     red = 1;
        //     green = 0;
        // }

        wait(0.2);
    }
}
