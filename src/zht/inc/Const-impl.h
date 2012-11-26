/*
 * Const-impl.h
 *
 *  Created on: Nov 24, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef CONST_IMPL_H_
#define CONST_IMPL_H_

#include "Const.h"
#include <sstream>

using namespace std;

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

template<class TYPE> string Const::toString(const TYPE& ele) {

	stringstream ss;
	ss << ele;

	return ss.str();
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* CONST_IMPL_H_ */
