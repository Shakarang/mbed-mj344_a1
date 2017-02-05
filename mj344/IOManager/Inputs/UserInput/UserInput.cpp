/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-04T13:35:20+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T18:49:10+00:00
*/

#include "UserInput.hh"

UserInput::UserInput(Callback<void(const UserInput::Type)> fptr) {
	this->inputCallback = fptr;
}
