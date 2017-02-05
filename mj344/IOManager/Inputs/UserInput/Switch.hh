/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:02:47+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T18:49:13+00:00
*/

#ifndef MJ344_SWITCH_HH_
#define MJ344_SWITCH_HH_

#include "UserInput.hh"

class Switch: public UserInput {

public:
	Switch(const PinName &, Callback<void(const UserInput::Type)>);
	~Switch();

	void 		triggered();

private:
	InterruptIn	*button;
};

#endif /* !MJ344_SWITCH_HH_ */
