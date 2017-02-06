/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-06T15:25:22+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-06T16:41:36+00:00
*/

#ifndef MJ344_ACCELEROMETER_HH_
#define MJ344_ACCELEROMETER_HH_

#include "ASensorInput.hh"
#include "../../../../MMA7660/MMA7660.h"

class Accelerometer: public ASensorInput {

public:
	Accelerometer();
	~Accelerometer();

	std::map<std::string, float>	getData() const;
private:
	MMA7660	*sensor;
};

#endif /* !MJ344_ACCELEROMETER_HH_ */
