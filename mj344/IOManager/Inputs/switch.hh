/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:02:47+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T17:23:05+00:00
*/

#ifndef MJ344_SWITCH_HH_
#define MJ344_SWITCH_HH_

#import "AInput.hh"

class Switch: public AInput {

public:
  Switch();
  ~Switch() {};

  void triggered();

protected:

};

#endif /* !MJ344_SWITCH_HH_ */
