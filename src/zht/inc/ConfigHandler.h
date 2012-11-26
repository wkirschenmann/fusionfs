/*
 * ConfigHandler.h
 *
 *  Created on: Nov 24, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef CONFIGHANDLER_H_
#define CONFIGHANDLER_H_

#include "ConfigEntry.h"

#include <map>
#include <string>
#include <sys/types.h>

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

/*
 * todo: monitor node.cfg
 */
class ConfigHandler {
public:
	typedef map<string, ConfigEntry> MAP;
	typedef pair<string, ConfigEntry> PAIR;
	typedef map<string, ConfigEntry>::iterator IT;
	typedef map<string, ConfigEntry>::reverse_iterator RIT;

public:
	ConfigHandler();
	virtual ~ConfigHandler();

	static void setNeighborSeeds(const string& neighborCfg);
	static void setZHTParameters(const string& zhtConfig);
	static void setNodeParameters(const string& nodeConfig);

private:
	static void pickNodeParameters();
	static void pickZHTParameters();

	static void setParametersInternal(string configFile, MAP& configMap);

public:
	static MAP NeighborSeeds;
	static MAP ZHTParameters;
	static MAP NodeParameters;

public:
	static string CFG_ZHT;
	static string CFG_NODE;
	static string CFG_NEIGHBOR;

public:
	static string NC_FILECLIENT_PATH;
	static string NC_FILESERVER_PATH;
	static uint NC_FILESERVER_PORT;

	static uint ZC_MAX_ZHT;
	static uint ZC_NUM_REPLICAS;
	static uint ZC_REPLICATION_TYPE;
	static uint NC_ZHT_CAPACITY;
	static string ZC_HTDATA_PATH;
	static uint ZC_MIGSLP_TIME;
};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* CONFIGHANDLER_H_ */
