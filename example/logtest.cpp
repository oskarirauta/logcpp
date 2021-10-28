#include <iostream>
#include "log.hpp"

int main() {

	log::output_level[log::verbose] = true;

	std::cout << "output to standard output: test" << std::endl;

	log::info << std::string("log entry #1 to info level: item1") << std::endl;

	log::error << "log entry #2 to error level:" << " item2" << " item3" << " item4";
	log::debug << "log entry #3 to debug level: item5" << " item6";

	log::error << std::endl;
	log::debug << " item7" << std::endl;

	log::info << "log entry #4 to info level: item8" << log::detail("Extended description for item8") << std::endl;
	log::info << "log entry #5 to info level: item9" << std::endl;
	log::info << "log entry #6 to info level: item10" << std::endl;
	// duplication test
	log::info << "info level: dup test" << std::endl;
	log::info << "info level: dup test" << log::detail("extension for dup test") << std::endl;
	log::info << "info level: dup test" << std::endl;
	/*
	// force clear detailed description on update
	log::info << "info level: dup test" << log::detail("") << std::endl;
	*/
	log::verbose << "log entry #7 to verbose level: item11" << std::endl;
	log::info << "info level: dup test" << std::endl;

	// termination log::endl (instead of '\n' or std::endl) adds entry
	// to journal without screen output
	log::info << "log entry #8 to info level";
	log::info << log::detail("entry only without screen output") << log::endl;
	log::ANY << "any level test.. should map to INFO level" << std::endl;

	// only message1 is accepted
	std::cout << "adding \"message1\\nmessage2\\nmessage3 << std::endl to verbose level, only message1 is accepted (a caveat)" << std::endl;
	log::verbose << "message1\nmessage2\nmessage3" << std::endl;

	// but this works..
	log::verbose << "message4\n" << "message5" << "\n" << "message6" << std::endl;

	log::type t = log::type::verbose;
	std::cout << "Log type for t is " << t << " (should be verbose)" << std::endl;

	std::cout << "\nhistory:" << std::endl;
	std::vector<log::entry> hist = log::last(10);
	for ( auto it = hist.begin(); it != hist.end(); ++it ) {
		std::cout << it -> type << ": " << it -> msg << ( it -> count > 1 ? ( " cnt: " + std::to_string(it -> count)) : "" ) << std::endl;
		if ( !it -> description.empty())
			std::cout << "\tdescription: " << it -> description << std::endl;
	}

	return 0;
}
