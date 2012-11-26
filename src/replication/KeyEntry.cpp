/*
 * KeyEntry.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "KeyEntry.h"
#include <string.h>
#include <stdio.h>

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

KeyEntry::KeyEntry() {
}

KeyEntry::KeyEntry(const string& skeyEntry) :
		Entry(skeyEntry) {

	assign(skeyEntry);
}

KeyEntry::~KeyEntry() {
}

string KeyEntry::first() const {

	return _first;
}

void KeyEntry::first(const string& first) {

	_first = first;
}

string KeyEntry::second() const {

	return _second;
}

void KeyEntry::second(const string& second) {

	_second = second;
}

string KeyEntry::toString() const {

	char buf[PATH_MAX + 20];
	memset(buf, 0, sizeof(buf));
	int n = snprintf(buf, sizeof(buf), getFormat().c_str(), _first.c_str(),
			_second.c_str());

	string result(buf, 0, n);

	return result;
}

void KeyEntry::assign(const string& sentry) {

	string remains = trim(sentry);

	size_t found = remains.find(getDelimit());

	if (found != string::npos) {

		first(trim(remains.substr(0, int(found))));
		second(trim(remains.substr(int(found) + 1)));
	}
}

string KeyEntry::getDelimit() const {

	return ":";
}

string KeyEntry::getFormat() const {

	return "%s:%s";
}

}
/* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
