/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-04T13:35:20+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-04T14:13:31+00:00
*/

#include "UserInput.hh"

UserInput::UserInput(void (*fptr)(const UserInput::Type)) {
	this->inputCallback = fptr;
}
