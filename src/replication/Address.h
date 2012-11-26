/*
 * Address.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include "KeyEntry.h"

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

/*
 *
 */
class Address {
public:
	Address();
	Address(const string& saddress);
	Address(const string& _host, const string& _port);
	virtual ~Address();

	string host() const;
	void host(const string& host);

	string port() const;
	void port(const string& port);

	string toString() const;
	virtual void assign(const string& saddress);

private:
	KeyEntry _KeyEntry;
};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* ADDRESS_H_ */
