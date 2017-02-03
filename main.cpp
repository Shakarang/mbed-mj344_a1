/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T16:38:56+00:00
*/

#include "mbed-os/mbed.h"

DigitalOut red(LED1);
DigitalOut green(LED2);
DigitalIn sw(SW2);

int main() {

    int i;

    while (1) {

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
