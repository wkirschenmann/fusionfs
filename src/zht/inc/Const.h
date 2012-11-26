/*
 * Const.h
 *
 *  Created on: Nov 24, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef CONST_H_
#define CONST_H_

#include <string>

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

/*
 *
 */
class Const {
public:
	Const();
	virtual ~Const();

public:
	static string trim(const string& value);
	template<class TYPE> static string toString(const TYPE& ele);

public:
	static const string CFG_DELIMITERS; //delimiters used in config file

	/*
	 * NC_: node config
	 */
	static const string NC_ZHT_CAPACITY;
	static const string NC_FILECLIENT_PATH;
	static const string NC_FILESERVER_PATH;
	static const string NC_FILESERVER_PORT;

	/*
	 * ZC_: ZHT config
	 */
	static const string ZC_MAX_ZHT;
	static const string ZC_NUM_REPLICAS;
	static const string ZC_REPLICATION_TYPE;
	static const string ZC_HTDATA_PATH;
	static const string ZC_MIGSLP_TIME;
};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* CONST_H_ */
