/*
 * Entry.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include "../zht/inc/Const.h"
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
class Entry {
public:
	Entry();
	explicit Entry(const string& sentry);
	virtual ~Entry();

	virtual string getDelimit() const = 0;
	virtual string toString() const = 0;
	virtual void assign(const string& sentry);
	string trim(const string& value);
};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* ENTRY_H_ */
