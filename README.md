# logcpp
C++ application internal logging system

A system that can be used to log similarly as ```std::cout <<``` would be used but with log levels.
Designed for background service applications mainly.

 - possibility to suppress selected levels or make it completely silent
 - possibility to output log to file
 - log journal
 - supressed duplicate messages
	- journal contains count of repetions
	- on screen displays _(duplicate message atleast once)_

Project uses some functions from my _common.hpp_ which contains some of my generally used code.

A usage sample is included.
