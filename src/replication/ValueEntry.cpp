/*
 * ValueEntry.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "ValueEntry.h"
#include <string.h>

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

ValueEntry::ValueEntry() {
}

ValueEntry::ValueEntry(const string& svalueEntry) :
		Entry(svalueEntry) {

	assign(svalueEntry);
}

ValueEntry::~ValueEntry() {
}

const ValueEntry::VEC& ValueEntry::entries() const {

	return _vec;
}

string ValueEntry::toString() const {

	string result;

	int i = 0;
	for (VIT it = _vec.begin(); it != _vec.end(); it++) {

		i++;
		result.append((*it));

		if (i != _vec.size())
			result.append(getDelimit());
	}

	return result;
}

void ValueEntry::assign(const string& sentry) {

	_vec.clear();

	string remains = trim(sentry);

	string store;
	char * pch, *sp;
	pch = strtok_r((char*) remains.c_str(), getDelimit().c_str(), &sp);

	while (pch != NULL) {

		_vec.push_back(string(pch));

		pch = strtok_r(NULL, getDelimit().c_str(), &sp);
	}

}

string ValueEntry::getDelimit() const {

	return ";";
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
