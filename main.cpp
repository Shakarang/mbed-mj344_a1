/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-06T20:09:46+00:00
*/

#include "mj344/ServiceManager.hh"

#include "mbed-os/mbed.h"


//PwmOut r(D5);
//PwmOut g(D9);
//PwmOut b(D8);



int main() {


	ServiceManager sm;

	sm.start();

	while (1);

	// while (1){
	// 	for (float f = 0.0f; f < 1.0f; f += 0.1f) {
	// 		r.write(1.0 - f);
	// 		g.write(f);
	// 		//b.write(f);
	// 		wait(0.5);
	// 	}
	// }
}
