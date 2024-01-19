# repository archived
logcpp has been renamed to [logger_cpp](https://github.com/oskarirauta/logger_cpp) and
logcpp will no longer be maintained. It was kept as it's own repository, because some
projects are still using it. Please move to [logger_cpp](https://github.com/oskarirauta/logger_cpp) for updated version.

# logcpp
C++ application internal logging system

logcpp has matured to version 2; some features were removed, some features were renamed
but for most parts it is a drop-in replacement of version 1, without requirement to any
changes in your project's code.

A system that can be used to log similarly as ```std::cout <<``` would be used but with log levels.
Designed for background service applications mainly.

 - possibility to select logging level or make it completely silent
 - possibility to output log to file
 - logging history
 - supressed duplicate messages
	- journal contains count of repetions
	- on screen displays _(duplicate message atleast once)_
 - tag log entries
 - add detail description for entry (no screen output, only on a journal entry)

### Log Entry

```log::info << "log this line to info level" << std::endl;```

### Tag entries

You can either use

```log::info << log::tag("my_tag") << "tagged message" << std::endl;```

or, you can use a subscript operator[]

```log::info["my_tag"] << "tagged message" << std::endl;```

### Entry's detail description

Add detail description to log entry:

```log::info << "message title" << log::detail("message detail description") << std::endl;```

### Custom log levels

Adding custom log levels is supported, just create them like this:

```logger::LOG_LEVEL my_level("my", 10, logger::std_out);```

Where last argument is optional, and can be aswell be std_err;
First argument is name, and second is level id. Default provided ids are:
error = 0, warning = 1, info = 2, verbose = 3, vverbose = 4, debug = 255

You can always change ids, for example like this:

```log::info.change_logging_level(10);```

### Trimming

log entries are trimmed, line feeds and tabs ( \n and \t ) are converted to spaces,
and \r \v will be erased from tags, details and messages.

### Depencies

Project uses some functions from my _common.hpp_ which contains some of my generally used code.

### Importing
import commoncpp as a submodule to directory common
import logcpp as a submodule to logger
include commoncpp's Makefile.inc and logcpp's Makefile.inc in your Makefile
and check example from project's samples Makefile (link with COMMON_OBJS and LOGGER_OBJS).

Don't forget to #include "logger.hpp" in your project's code where you plan to use logger.

### Example

Sample code is provided.

### Other

MIT-license.
