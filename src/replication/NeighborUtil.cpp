/*
 * NeighborUtil.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "NeighborUtil.h"
#include "NeighborUtil-c.h"
#include <string>

using namespace iit::cs495::proj5::dfs::replication;

void c_setNeighborSeeds(const char *neighborCfg) {

	NeighborUtil::setNeighborSeeds(string(neighborCfg));
}

const char* c_get1stReplicaAddr(const char *address) {

	string hostport(address);
	/*assume the zht neighbor port is 50000*/
	hostport.append(":50000");

	/*only return host, not port*/
	return NeighborUtil::get1stReplicaAddr(hostport).host().c_str();
}

const char* c_get2ndReplicaAddr(const char *address) {

	string hostport(address);
	/*assume the zht neighbor port is 50000*/
	hostport.append(":50000");

	/*only return host, not port*/
	return NeighborUtil::get2ndReplicaAddr(hostport).host().c_str();

}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

NeighborUtil::MAP NeighborUtil::_NSS = MAP();

NeighborUtil::NeighborUtil() {
}

NeighborUtil::~NeighborUtil() {
}

Address NeighborUtil::get1stReplicaAddr(const Address& address) {

	Address result;

	MIT it = _NSS.find(address.toString());
	it++;

	if (it == _NSS.end()) { //next is the first one

		it = _NSS.begin();
		result = it->second;

	} else { //next is really next

		result = it->second;
	}

	return result;
}

Address NeighborUtil::get1stReplicaAddr(const string& hostport) {

	return get1stReplicaAddr(Address(hostport));
}

Address NeighborUtil::get1stReplicaAddr(const string& host,
		const string& port) {

	Address address(host, port);

	get1stReplicaAddr(address);
}

Address NeighborUtil::get2ndReplicaAddr(const Address& address) {

	return get1stReplicaAddr(get1stReplicaAddr(address));
}

Address NeighborUtil::get2ndReplicaAddr(const string& hostport) {

	return get2ndReplicaAddr(Address(hostport));
}

Address NeighborUtil::get2ndReplicaAddr(const string& host,
		const string& port) {

	Address address(host, port);

	get2ndReplicaAddr(address);
}

void NeighborUtil::setNeighborSeeds(const string& neighborCfg) {

	_NSS.clear();

	setParametersInternal(neighborCfg, _NSS);
}

template<class TYPE> string NeighborUtil::toString(const TYPE& ele) {

	stringstream ss;
	ss << ele;

	return ss.str();
}

void NeighborUtil::setParametersInternal(const string& configFile,
		MAP& configMap) {

	ifstream ifs(configFile.c_str(), ifstream::in);

	const char *delimiter = " ";

	string line;
	while (getline(ifs, line)) {

		string remains = toString(line);
		if (remains.empty())
			continue;

		size_t found = remains.find(delimiter);

		if (found != string::npos) {

			string one = toString(remains.substr(0, int(found)));
			string two = toString(remains.substr(int(found) + 1));

			if (one.empty() || two.empty())
				continue;

			if (one.substr(0, 1) == "#") //starts with #, means comment
				continue;

			string name = one;
			string value = two;

			if (!name.empty() && !value.empty()) {

				Address addr(name, value);
				configMap.insert(PAIR(addr.toString(), addr)); //todo: use hash code to reduce size of key/value pair.
			}
		}
	}

	ifs.close();
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
