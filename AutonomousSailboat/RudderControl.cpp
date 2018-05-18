#include "RudderControl.h"
#include <Sailboat.h>

RudderControl::RudderControl(){
  
}

void RudderControl::init() {
  
}

void RudderControl::Control(const geometry_msgs::Twist& cmd) {
  double rudder = cmd.angular.x * RAD_TO_DEG;
  double rudder2 = cmd.angular.z * RAD_TO_DEG;
  
  Sailboat::Instance()->getRudder()->applyCommand(rudder);
#ifdef ACTUATOR_RUDDER2
  Sailboat::Instance()->getRudder2()->applyCommand(rudder2);
#endif
  double sail = 0;
  WindSensor* wind = Sailboat::Instance()->getWindSensor();

  sail = HALF_PI * RAD_TO_DEG * (cos(wind->getMeasure()) + 1) / 2;
  Sailboat::Instance()->getSail()->applyCommand(sail);
}