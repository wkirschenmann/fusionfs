/*
 * Address.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "Address.h"

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

Address::Address() {
}

Address::Address(const string& saddress) :
		_KeyEntry(saddress) {
}

Address::Address(const string& _host, const string& _port) {

	host(_host);
	port(_port);
}

Address::~Address() {
}

string Address::host() const {

	return _KeyEntry.first();
}

void Address::host(const string& host) {

	_KeyEntry.first(host);
}

string Address::port() const {

	return _KeyEntry.second();
}

void Address::port(const string& port) {

	_KeyEntry.second(port);
}

string Address::toString() const {

	return _KeyEntry.toString();
}

void Address::assign(const string& saddress) {

	_KeyEntry.assign(saddress);
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
