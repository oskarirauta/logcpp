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
 - add entries to journal without screen output
 - add detail description for entry (no screen output, only on a journal entry)

### Todo
 - update readme

### Entry to journal only

custom message termination with log::endl which causes entry to record only on journal without screen output.
It's a simple output only manipulator with "\x1B\n" where 0x1b is ascii for ESC and \0x1B + \n is handled as termination of message + no screen output. ESC is stripped from final message.

```log::info << "this to journal only" << log::endl;```
or manually:

```log::info << "journal only entry\x1B\n";```

### Entry's detail description

Add detail description to log entry:

```log::info << "message title" << log::detail("message detail description") << std::endl;```

if duplicate entries occur, last detail description is kept, until new duplicate's detail description is cleared with:

```log::info << "this is duplicated title from previous entry" << log::detail("") << std::endl;```

Only on detail description is kept, it is always the last one used unless cleared which results in detail description being empty until next duplicated entry has a detail description again.

### Custom log levels

Adding custom log levels is easy, just add them to _type_ enum in _log.hpp_ but keep in mind that _info_ and _error_ should always come first hardcoded values to 0 and 1, and _ANY_ should be last with hardcoded value of 255, _debug_ level is not mandatory to be 254, but I've set it so for possible futures needs.
You can even remove verbose and vverbose if you want to, or even debug can be removed if wanted to.

### Can I add levels during runtime?

Sorry, no you can't due to design of logcpp.

### Issues

A minor known caveat; logging entry with

```log::info << "message1\nmessage2\nmessage3" << std::endl;```

adds only one entry with ```message1``` and rest of message is discarded and not accepted to next entries.
but on the other hand, this works:

```log::info << "message4\n" << "message5" << "\n" << "message6" << std::endl;```

which results in 3 log entries with titles _message4_, _message5_ and _message6_.

### Depencies

Project uses some functions from my _common.hpp_ which contains some of my generally used code.
To use logcpp in your project, you need to include 4 files from this repository:
 - include/common.hpp
 - include/log.hpp
 - shared/common.cpp
 - src/log.cpp

Or you can create your own _common.[hpp,cpp]_ with using only necessary parts from there as _common_ has rather large footprint when it comes to needs of logcpp.

### Example

Sample code is provided.

### Other

MIT-license.
