----------------

## Sonar Sensor:
* As there is only one VCC pin in Arduino Uno, the effect of VCC pin for the sensor is gained by using a digital pin contained in the variable "vcc".
* The "trig" variable stores the pin number, in which the trig pin of the sensor is connected, wheras The "echo" variable stores the pin number, in which the echo pin of the sensor is connected.

----------------
----------------

## L298N Motor Controller :
* The "in1","in2","in3" and "in4" variables stores the pin number connected to the motor driver.
* Calibration needs to be done for storing the proper pin numbers in these variables,
> or, the code needs to be modified as per necessity.

----------------
----------------

## Servo Motor:
* Store your pin number, in which the servo signal pin is connected, in the variable "servoPin".

----------------
----------------

## Others:
* the "rvel" variable store the angular velocity of the robot i.e angular distance travelled by the robot in 1 second. This velocity is largly dependant on the DC motors and thus needs to be calculated for any individual robot.
