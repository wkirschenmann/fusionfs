/*
 * Entry.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "Entry.h"

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

	return Const::trim(value);
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
