/*
 * Entry.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "Entry.h"
#include <sstream>

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

Entry::Entry() {
}

Entry::Entry(const string& sentry) {

//	assign(sentry); //todo: fail to call subclass's impl
}

Entry::~Entry() {
}

void Entry::assign(const string& sentry) {
}

string Entry::trim(const string& value) {

	string str = value;
	stringstream trimmer;
	trimmer << str;
	trimmer >> str;

	return str;
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
