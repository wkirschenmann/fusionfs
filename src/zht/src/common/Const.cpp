/*
 * Const.cpp
 *
 *  Created on: Nov 24, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "Const-impl.h"

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

const string Const::CFG_DELIMITERS = " ";

const string Const::NC_ZHT_CAPACITY = "ZHT_CAPACITY";
const string Const::NC_FILECLIENT_PATH = "FILECLIENT_PATH";
const string Const::NC_FILESERVER_PATH = "FILESERVER_PATH";
const string Const::NC_FILESERVER_PORT = "FILESERVER_PORT";

const string Const::ZC_MAX_ZHT = "MAX_ZHT";
const string Const::ZC_NUM_REPLICAS = "NUM_REPLICAS";
const string Const::ZC_REPLICATION_TYPE = "REPLICATION_TYPE";
const string Const::ZC_HTDATA_PATH = "HTDATA_PATH";
const string Const::ZC_MIGSLP_TIME = "MIGSLP_TIME";

Const::Const() {
}

Const::~Const() {
}

string Const::trim(const string& value) {

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
