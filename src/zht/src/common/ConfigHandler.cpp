/*
 * ConfigHandler.cpp
 *
 *  Created on: Nov 24, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "ConfigHandler.h"

#include "Const-impl.h"

#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>

#include <fstream>
#include <iostream>
using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

ConfigHandler::MAP ConfigHandler::NeighborSeeds = MAP();
ConfigHandler::MAP ConfigHandler::ZHTParameters = MAP();
ConfigHandler::MAP ConfigHandler::NodeParameters = MAP();

string ConfigHandler::CFG_ZHT = "zht.cfg";
string ConfigHandler::CFG_NODE = "node.cfg";
string ConfigHandler::CFG_NEIGHBOR = "neighbor";

uint ConfigHandler::ZC_MAX_ZHT = 0;
uint ConfigHandler::ZC_NUM_REPLICAS = 0;
uint ConfigHandler::ZC_REPLICATION_TYPE = 0;

uint ConfigHandler::NC_ZHT_CAPACITY = 0;
string ConfigHandler::NC_FILECLIENT_PATH = "./fileclient";
string ConfigHandler::NC_FILESERVER_PATH = "./fileserver";
uint ConfigHandler::NC_FILESERVER_PORT = 9000;

string ConfigHandler::ZC_HTDATA_PATH = ""; //todo: empty string not allowed.

uint ConfigHandler::ZC_MIGSLP_TIME = 1000000; //micro second

ConfigHandler::ConfigHandler() {

}

ConfigHandler::~ConfigHandler() {

}

void ConfigHandler::setNeighborSeeds(const string& neighborCfg) {

	setParametersInternal(neighborCfg, NeighborSeeds);
}

void ConfigHandler::setZHTParameters(const string& zhtConfig) {

	setParametersInternal(zhtConfig, ZHTParameters);

	pickZHTParameters();
}

void ConfigHandler::setNodeParameters(const string& nodeConfig) {

	setParametersInternal(nodeConfig, NodeParameters);

//	pickNodeParameters();
}

void ConfigHandler::setParametersInternal(string configFile, MAP& configMap) {

	ifstream ifs(configFile.c_str(), ifstream::in);

	const char *delimiter = Const::CFG_DELIMITERS.c_str();

	string line;
	while (getline(ifs, line)) {

		string remains = Const::toString(line);
		if (remains.empty())
			continue;

		size_t found = remains.find(delimiter);

		if (found != string::npos) {

			string one = Const::toString(remains.substr(0, int(found)));
			string two = Const::toString(remains.substr(int(found) + 1));

			if (one.empty() || two.empty())
				continue;

			if (one.substr(0, 1) == "#") //starts with #, means comment
				continue;

			string name = one;
			string value = two;

			if (!name.empty() && !value.empty()) {

				ConfigEntry ce(name, value);
				configMap.insert(PAIR(ce.toString(), ce)); //todo: use hash code to reduce size of key/value pair.
			}
		}
	}

	ifs.close();
}

void ConfigHandler::pickNodeParameters() {

	ConfigHandler::IT kvi;
	ConfigHandler::MAP* map = &ConfigHandler::NodeParameters;

	for (kvi = map->begin(); kvi != map->end(); kvi++) {

		ConfigEntry kv = kvi->second;

		if (kv.name() == Const::NC_ZHT_CAPACITY) {

			NC_ZHT_CAPACITY = atoi(kv.value().c_str());
		} else if (kv.name() == Const::NC_FILECLIENT_PATH) {

			NC_FILECLIENT_PATH = kv.value();
		} else if (kv.name() == Const::NC_FILESERVER_PATH) {

			NC_FILESERVER_PATH = kv.value();
		} else if (kv.name() == Const::NC_FILESERVER_PORT) {

			NC_FILESERVER_PORT = atoi(kv.value().c_str());
		} else {
		}
	}
}

void ConfigHandler::pickZHTParameters() {

	ConfigHandler::IT kvi;
	ConfigHandler::MAP* map = &ConfigHandler::ZHTParameters;

	for (kvi = map->begin(); kvi != map->end(); kvi++) {

		ConfigEntry kv = kvi->second;

		if (kv.name() == Const::ZC_MAX_ZHT) {

			ZC_MAX_ZHT = atoi(kv.value().c_str());
		} else if (kv.name() == Const::ZC_NUM_REPLICAS) {

			ZC_NUM_REPLICAS = atoi(kv.value().c_str());
		} else if (kv.name() == Const::ZC_REPLICATION_TYPE) {

			ZC_REPLICATION_TYPE = atoi(kv.value().c_str());
		} else if (kv.name() == Const::NC_ZHT_CAPACITY) {

			NC_ZHT_CAPACITY = atoi(kv.value().c_str());
		} else if (kv.name() == Const::NC_FILECLIENT_PATH) {

			NC_FILECLIENT_PATH = kv.value();
		} else if (kv.name() == Const::NC_FILESERVER_PATH) {

			NC_FILESERVER_PATH = kv.value();
		} else if (kv.name() == Const::NC_FILESERVER_PORT) {

			NC_FILESERVER_PORT = atoi(kv.value().c_str());
		} else if (kv.name() == Const::ZC_HTDATA_PATH) {

			ZC_HTDATA_PATH = kv.value();
		} else if (kv.name() == Const::ZC_MIGSLP_TIME) {

			ZC_MIGSLP_TIME = atoi(kv.value().c_str());
		} else {

		}
	}
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
