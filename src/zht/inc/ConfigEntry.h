/*
 * ConfigEntry.h
 *
 *  Created on: Nov 24, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef CONFIGENTRY_H_
#define CONFIGENTRY_H_

#include "ConfigEntry.h"

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
class ConfigEntry {
public:
	ConfigEntry();
	ConfigEntry(const string& sConfigEntry);
	ConfigEntry(const string& name, const string& value);
	virtual ~ConfigEntry();

	string name() const;
	void name(const string& name);

	string value() const;
	void value(const string& value);

	string operator()() const;
	string toString() const;
	ConfigEntry& assign(string sconfigEntry);

	static string getFormat();

private:
	string _name;
	string _value;
};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* CONFIGENTRY_H_ */
