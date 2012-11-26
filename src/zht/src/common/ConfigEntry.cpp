/*
 * ConfigEntry.cpp
 *
 *  Created on: Nov 24, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include <string.h>
#include <stdio.h>

#include "ConfigEntry.h"
#include "Const.h"

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

ConfigEntry::ConfigEntry() {

}

ConfigEntry::ConfigEntry(const string& sconfigEntry) {

	assign(sconfigEntry);
}

ConfigEntry::ConfigEntry(const string& name, const string& value) :
		_name(name), _value(value) {

}

ConfigEntry::~ConfigEntry() {

}

string ConfigEntry::name() const {

	return _name;
}

void ConfigEntry::name(const string& name) {

	_name = name;
}

string ConfigEntry::value() const {

	return _value;
}

void ConfigEntry::value(const string& value) {

	_value = value;
}

string ConfigEntry::operator()() const {

	return toString();
}

string ConfigEntry::toString() const {

	char buf[50];
	memset(buf, 0, sizeof(buf));
	int n = snprintf(buf, sizeof(buf), getFormat().c_str(), _name.c_str(),
			_value.c_str());

	string result(buf, 0, n);

	return result;
}

ConfigEntry& ConfigEntry::assign(string sconfigEntry) {

	const char* delimiter = ",";

	string remains = Const::trim(sconfigEntry);

	size_t found = remains.find(delimiter);

	if (found != string::npos) {

		name(Const::trim(remains.substr(0, int(found))));
		value(Const::trim(remains.substr(int(found) + 1)));
	}

	return *this;
}

string ConfigEntry::getFormat() {

	return "%s,%s";
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
