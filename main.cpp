/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:27:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T15:52:38+00:00
*/

#include "mj344/ServiceManager.hh"

#include "mbed.h"

int main() {


	ServiceManager sm;

	sm.start();

	while (1) {
		wait(10);
	}
}
