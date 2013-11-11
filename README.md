Self-Driving-RC-Car
===================

Testing out Kalman filter and SLAM code on a vehicle which can't fall out of the sky.

**Hardware**

IMX (Imex) Firefox 1/10 scale RC car contains one RC550 brushed hobby DC motor and one three-wire RadioShack hobby servo. The controller is an Arduino Uno with VNH5019 Dual Motor Driver Carrier Shield from Pololu. 

**Software**

Simple Arduino sketch to drive the motor in forward and reverse while turning the servo to steer the vehicle. 

Libraries used:

- "mem's ServoTimer2":http://forum.arduino.cc/index.php/topic,21975.0.html
- "Pololu's VNH5019 Motor Driver Shield":https://github.com/pololu/dual-vnh5019-motor-shield

**License**

Released under the 3-clause BSD. http://opensource.org/licenses/BSD-3-Clause
