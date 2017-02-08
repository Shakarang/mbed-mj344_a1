/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T21:45:04+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T19:14:27+00:00
*/

#ifndef MJ344_HOST_HH_
#define MJ344_HOST_HH_

#include "AOutput.hh"

/**
 * Serial connexion to the computer.
 * Inherits from AOutput and implement the print method.
 */
class Host: public AOutput {

public:
	Host();
	~Host();

	void		print(const std::string &);

private:
	/**
	 * Serial connextion to the computer.
	 */
	Serial	*host = NULL;
};

#endif /* !MJ344_HOST_HH_ */
