/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:57:51+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T19:14:13+00:00
*/

#ifndef MJ344_SCREEN_HH_
#define MJ344_SCREEN_HH_


#include "AOutput.hh"
#include "C12832.h"

/**
 * LCD screen on mbed shield.
 * Inherits from AOutput and implement the print method.
 */
class Screen: public AOutput {

public:
	Screen();
	~Screen();

	void		print(const std::string &);

private:
	/**
	* LCD value for
	*/
	C12832		*shieldLCD = NULL;
};

#endif /* !MJ344_SCREEN_HH_ */
