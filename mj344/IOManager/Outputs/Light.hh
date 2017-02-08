/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T10:28:00+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T19:14:21+00:00
*/

#ifndef MJ344_LIGHT_HH_
#define MJ344_LIGHT_HH_

#include "mbed.h"

class Light {

public:
	/**
	 * Enum containing values corresponding to colors in RGB
	 * (e.g. Yellow = R(1)G(1)B(0) )
	 */
	enum Color {
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		LIGHT_BLUE = 3,
		RED = 4,
		PINK = 5,
		YELLOW = 6,
		WHITE = 7
	};

	/**
	 * Enum giving us the position of the asked LED.
	 * It lets us init the Light object easily without passing the PIN names.
	 */
	enum Position {
		FRDM, SHIELD
	};

public:
	Light(const Light::Position);
	~Light();

public:
	/**
	 * Update led color based on the enum Color
	 * @param Light::Color color wanted
	 */
	 void updateState(const Light::Color);

private:
	/**
	 * Red light
	 */
	DigitalOut *red = NULL;

	/**
	 * Green light
	 */
	DigitalOut *green = NULL;

	/**
	 * Blue light
	 */
	DigitalOut *blue = NULL;
};

#endif /* !MJ344_LIGHT_HH_ */
