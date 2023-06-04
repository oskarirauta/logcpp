#include <iostream>
#include "logger.hpp"

int main() {

	logger::print_appname = false;
	logger::output_level[logger::verbose] = true;

	std::cout << "output to standard output: test" << std::endl;

	logger::info << std::string("log entry #1 to info level: item1") << std::endl;

	logger::error << "log entry #2 to error level:" << " item2" << " item3" << " item4";
	logger::debug << "log entry #3 to debug level: item5" << " item6";

	logger::error << std::endl;
	logger::debug << " item7" << std::endl;

	logger::info << "log entry #4 to info level: item8" << logger::detail("Extended description for item8") << std::endl;
	logger::info << "log entry #5 to info level: item9" << std::endl;
	logger::info << "log entry #6 to info level: item10" << std::endl;
	// duplication test
	logger::info << "info level: dup test" << std::endl;
	logger::info << "info level: dup test" << logger::detail("extension for dup test") << std::endl;
	logger::info << "info level: dup test" << std::endl;
	/*
	// force clear detailed description on update
	logger::info << "info level: dup test" << logger::detail("") << std::endl;
	*/
	logger::verbose << "log entry #7 to verbose level: item11" << std::endl;
	logger::info << "info level: dup test" << std::endl;

	// termination logger::endl (instead of '\n' or std::endl) adds entry
	// to journal without screen output
	logger::info << "log entry #8 to info level";
	logger::info << logger::detail("entry only without screen output") << logger::endl;
	logger::ANY << "any level test.. should map to INFO level" << std::endl;

	// only message1 is accepted
	std::cout << "adding \"message1\\nmessage2\\nmessage3 << std::endl to verbose level, only message1 is accepted (a caveat)" << std::endl;
	logger::verbose << "message1\nmessage2\nmessage3" << std::endl;

	// but this works..
	logger::verbose << "message4\n" << "message5" << "\n" << "message6" << std::endl;

	logger::type t = logger::type::verbose;
	std::cout << "Log type for t is " << t << " (should be verbose)" << std::endl;

	logger::info << logger::tag("example") << "log entry with tag" << std::endl;

	std::cout << "\nhistory:" << std::endl;
	std::vector<logger::entry> hist = logger::last(10);
	for ( auto it = hist.begin(); it != hist.end(); ++it ) {
		std::cout << it -> type << ( it -> tag.empty() ? "" : ( " [" + it -> tag + "]" )) << ": " << it -> msg << ( it -> count > 1 ? ( " cnt: " + std::to_string(it -> count)) : "" ) << std::endl;
		if ( !it -> description.empty())
			std::cout << "\tdescription: " << it -> description << std::endl;
	}

	return 0;
}
