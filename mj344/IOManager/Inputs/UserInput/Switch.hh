/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:02:47+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T19:14:47+00:00
*/

#ifndef MJ344_SWITCH_HH_
#define MJ344_SWITCH_HH_

#include "UserInput.hh"

/**
 * Switch button inheriting from UserInput.
 */
class Switch: public UserInput {

public:
	Switch(const PinName &, Callback<void(const UserInput::Type)>);
	~Switch();

	void 		triggered();

private:
	/**
	 * Switch used with InterruptIn to catch events.
	 */
	InterruptIn	*button = NULL;
};

#endif /* !MJ344_SWITCH_HH_ */
