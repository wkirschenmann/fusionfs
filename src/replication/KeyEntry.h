/*
 * KeyEntry.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef KEYENTRY_H_
#define KEYENTRY_H_

#include <string>
#include "Entry.h"
#include <limits.h>

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

/*
 *
 */
class KeyEntry: public Entry {
public:
	KeyEntry();
	explicit KeyEntry(const string& skeyEntry);
	virtual ~KeyEntry();

	string first() const;
	void first(const string& first);

	string second() const;
	void second(const string& second);

	string getDelimit() const;
	string toString() const;
	virtual void assign(const string& sentry);

	string getFormat() const;

private:
	string _first;
	string _second;

};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* KEYENTRY_H_ */
