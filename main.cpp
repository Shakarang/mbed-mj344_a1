/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T21:07:38+00:00
*/

#include "mbed-os/mbed.h"
#include "LM75B.h"
//#include "C12832.h"

#include "IOManager/Outputs/AOutput.hh"
#include "IOManager/Outputs/screen.hh"

DigitalOut red(LED1);
DigitalOut green(LED2);
DigitalIn sw(SW2);

LM75B sensor(I2C_SDA, I2C_SCL);

//C12832 shld_lcd (D11, D13, D12, D7, D10);   /* LCD */

int main() {

    int i;

    Screen scr;
    std::string str("Saluuuutloluzebduyizebyeurfreyugferuyfgreyufg");
    //shld_lcd.locate (0 , 10);
      //  shld_lcd.printf ("Eh salut \n");

    while (1) {

        scr.print(str);

        if (sw) {
            red = 0;
            green = 1;
        }
        else {
            red = 1;
            green = 0;
        }

        wait(0.2);
    }
}
