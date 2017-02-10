/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T19:29:57+00:00
*/

#include "mj344/ServiceManager.hh"

#include "mbed.h"

/**
 * The goal of this application is to collect data from multiple
 * sensors and to provide a user-friendly way of interacting with it.

The user can directly interact with the two switches, the SW2 to
change the data rate for collecting data and the SW3 to resume/pause
the program and can use the joystick to use the control menu.

The joystick is used this way:
- UP/DOWN : select which sensor we want to collect data from
- LEFT/RIGHT : select in what unit the data will be displayed (e.g. Celsius, Fahrenheit, …)
- FIRE : used to select our choice

The information are displayed on the LCD screen and reported by the serial link.

Currently, it collects data from two sensors, temperature and accelerometer.
The accelerometer updates the LED colour according to its position.

The main component of the application is the ServiceManager,
it contains most of the logic. Another useful component is
the IOManager, it is making information management easier
by allowing us to easily create sensors, inputs and outputs.

Youtube video : https://youtu.be/8CvWJ0T3Wcw

 */
int main() {


	ServiceManager sm;

	sm.start();

	while (1) {
		wait(10);
	}
}
