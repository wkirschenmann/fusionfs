/*
 * NeighborUtil.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef NEIGHBORUTIL_H_
#define NEIGHBORUTIL_H_

#include <map>
#include <string>
#include "Address.h"

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

/*
 *
 */
class NeighborUtil {
public:
	typedef map<string, Address> MAP;
	typedef pair<string, Address> PAIR;
	typedef map<string, Address>::const_iterator MIT;
	typedef map<string, Address>::reverse_iterator MRIT;

public:
	NeighborUtil();
	virtual ~NeighborUtil();

public:
	static void setNeighborSeeds(const string& neighborCfg);

	/*get address of the first replica based on master address*/
	static Address get1stReplicaAddr(const Address& address);
	/*get address of the first replica based on master address*/
	static Address get1stReplicaAddr(const string& hostport);
	/*get address of the first replica based on master address*/
	static Address get1stReplicaAddr(const string& host, const string& port);
	/*get address of the second replica based on master address*/
	static Address get2ndReplicaAddr(const Address& address);
	/*get address of the second replica based on master address*/
	static Address get2ndReplicaAddr(const string& hostport);
	/*get address of the second replica based on master address*/
	static Address get2ndReplicaAddr(const string& host, const string& port);

	template<class TYPE> static string toString(const TYPE& ele);

private:
	static void setParametersInternal(const string& configFile, MAP& configMap);

private:
	/*NSS: NeighborSeeds,
	 * key: 192.168.1.100:5000
	 * value: Address("192.168.1.100:5000")
	 * 		host: 192.168.1.100
	 * 		port: 5000*/
	static MAP _NSS;
};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* NEIGHBORUTIL_H_ */
