/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:50:02+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-07T22:10:17+00:00
*/

#ifndef MJ344_AOUTPUT_HH_
#define MJ344_AOUTPUT_HH_

#include <string>

#include "../../../mbed-os/mbed.h"

/**
 * Abstract class to be inherited by printable outputs.
 */
class AOutput {

public:
  AOutput(const std::string &);
  virtual ~AOutput() {};

	/**
	* Displays string to the specified output.
	* Pure method needed to me implemented by child classes.
	* @param string to display
	*/
	virtual void		print(const std::string &) = 0;

protected:
	const std::string	identifier;
};

#endif /* !MJ344_AOUTPUT_HH_ */
