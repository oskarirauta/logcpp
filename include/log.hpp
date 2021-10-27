#pragma once

#include <ostream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <map>

#ifndef EVENT_LOG_MAX_SIZE
# define EVENT_LOG_MAX_SIZE 100
#endif

namespace log {

	using endl_type = std::ostream& (std::ostream&);

	inline std::ostream *output_stream = &std::cout; // set to nullptr to quiet
	inline std::ostream *error_stream = &std::cerr;
	inline std::ostream *file_stream = nullptr;

	enum type: uint8_t {
		info = 0,
		error = 1,
		verbose,
		vverbose,
		debug = 254,
		ANY = 255
	};

	inline std::ostream& operator << (std::ostream &os, log::type type) {
		switch ( type ) {
			case log::type::info: return os << "info";
			case log::type::error: return os << "error";
			case log::type::verbose: return os << "verbose";
			case log::type::vverbose: return os << "vverbose";
			case log::type::debug: return os << "debug";
			case log::type::ANY: return os << "ANY";
			default: return os << "unknown";
		}
	}

	inline const std::string description(const log::type type) {
		switch ( type ) {
			case log::type::error: return "error";
			case log::type::debug: return "debug";
			default: return "info";
		}
	}

	inline std::map<log::type, bool> output_level {
		{ static_cast<log::type>(0), true },
		{ static_cast<log::type>(1), true },
	};

	struct entry {

		public:
			log::type type = static_cast<log::type>(0);
			std::chrono::seconds timestamp = std::chrono::duration_cast<std::chrono::seconds>
								(std::chrono::system_clock::now().time_since_epoch());
			std::chrono::seconds timestamp_last = timestamp;
			std::string msg;
			int count = 0;

			const bool equals(log::entry rhs);
	};

	namespace _private { // anonymous namespace / private member(s)

		inline std::list<log::entry> store;
		inline std::map<log::type, std::stringstream> _stream;
		inline std::string _last_msg;

		const std::list<log::entry> filtered(void);
		const int lastIndexOf(const log::type type, const std::string msg);
		const bool typeShouldEcho(const log::type type, const bool screenOnly = false);
		void process_entry(const log::type type, const std::string msg, const log::endl_type endl);
	}

	template<typename T>
	inline const log::type& operator << ( const log::type &f, const T input) {
		log::_private::_stream[f] << input;
		return f;
	};

	inline const log::type& operator << ( const log::type &f, const log::endl_type endl) {
		log::_private::process_entry(f, log::_private::_stream[f].str(), endl);
		log::_private::_stream[f].str(std::string());
		return f;
	};

	const std::vector<log::entry> last(int count, const log::type type = log::type::ANY);
};
