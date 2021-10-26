#include <iostream>
#include "log.hpp"

int main() {

	std::cout << "output to standard output: test" << std::endl;

	log::info << std::string("log entry #1 to info level: item1") << std::endl;

	log::error << "log entry #2 to error level:" << " item2" << " item3" << " item4";
	log::debug << "log entry #3 to debug level: item5" << " item6";

	log::error << std::endl;
	log::debug << " item7" << std::endl;

	log::info << "log entry #4 to info level: item8" << std::endl;
	log::info << "log entry #5 to info level: item9" << std::endl;
	log::info << "log entry #6 to info level: item10" << std::endl;
	// duplication test
	log::info << "info level: dup test" << std::endl;
	log::info << "info level: dup test" << std::endl;
	log::info << "info level: dup test" << std::endl;
	log::verbose << "log entry #7 to verbose level: item11" << std::endl;
	log::info << "info level: dup test" << std::endl;
	log::ANY << "any level test.." << std::endl;

	log::type t = log::type::verbose;
	std::cout << "Log type for t is " << t << " (should be verbose)" << std::endl;

	std::cout << "\nhistory:" << std::endl;
	std::vector<log::entry> hist = log::last(10);
	for ( auto it = hist.begin(); it != hist.end(); ++it )
		std::cout << it -> type << ": " << it -> msg << ( it -> count > 1 ? ( " cnt: " + std::to_string(it -> count)) : "" ) << std::endl;

	return 0;
}
