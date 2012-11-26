/*
 * ValueEntry.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef VALUEENTRY_H_
#define VALUEENTRY_H_

#include "Entry.h"
#include <vector>

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

/*
 *
 */
class ValueEntry: public Entry {

public:
	typedef vector<string> VEC;
	typedef vector<string>* PVEC;

	typedef vector<string>::const_iterator VIT;

public:
	ValueEntry();
	explicit ValueEntry(const string& svalueEntry);
	virtual ~ValueEntry();

	const VEC& entries() const;

	string getDelimit() const;
	string toString() const;
	virtual void assign(const string& sentry);

private:
	vector<string> _vec;

};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* VALUEENTRY_H_ */
