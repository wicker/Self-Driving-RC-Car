Self-Driving-RC-Car
===================

Testing out Kalman filter and SLAM code on a vehicle which can't fall out of the sky.

Hardware
--------

IMX (Imex) Firefox 1/10 scale RC car contains one RC550 brushed hobby DC motor and one three-wire RadioShack hobby servo. 

v1 controller is an Arduino Uno with VNH5019 Dual Motor Driver Carrier Shield from Pololu. 

v2 controller is an STM32F4-Discovery board with VNH5019 Dual Motor Driver Carrier shield from Pololu.

v3 controller is a custom Foxcar Control Board v1.

v4 controller is a custom Foxcar Control Board v2.

Software
--------

**v1 - Arduino**

A simple Arduino sketch to drive the motor in forward and reverse while turning the servo to steer the vehicle. Libraries used:

- [Zambetti's ASCIITable](http://arduino.cc/en/Tutorial/ASCIITable)
- [SoftwareSerial](http://arduino.cc/en/Reference/SoftwareSerial)
- [mem's ServoTimer2](http://forum.arduino.cc/index.php/topic,21975.0.html)
- [Pololu's VNH5019 Motor Driver Shield](https://github.com/pololu/dual-vnh5019-motor-shield)

**v2 - STM32F4-Discovery**

Putting everything together. 

- [Pololu's VNH5019 Motor Driver Shield](https://github.com/pololu/dual-vnh5019-motor-shield)

License
-------

Released under the 3-clause BSD. http://opensource.org/licenses/BSD-3-Clause
