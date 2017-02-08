/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-06T15:25:22+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T16:05:38+00:00
*/

#ifndef MJ344_ACCELEROMETER_HH_
#define MJ344_ACCELEROMETER_HH_

#include "ASensorInput.hh"
#include "MMA7660.h"

// /**
//  * M_PI and fround are not found with the mbed math library.
//  */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
//
// #ifndef roundf
// #define roundf(var)    (float)(var+0.5f)
// #endif

/**
 * Accelerometer sensor inheriting from ASensorInput.
 */
class Accelerometer: public ASensorInput {

public:
	Accelerometer();
	~Accelerometer();

	std::map<std::string, float>	getData() const;
private:
	/**
	 * Shield sensor.
	 */
	MMA7660	*sensor;
};

#endif /* !MJ344_ACCELEROMETER_HH_ */
