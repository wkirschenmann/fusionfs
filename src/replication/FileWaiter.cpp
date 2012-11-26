/*
 * FileWaiter.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#include "FileWaiter-c.h"
#include "FileWaiter.h"

using namespace iit::cs495::proj5::dfs::replication;

int c_checkoutFile(const char *proto, const char *master_ip,
		const char *server_port, const char *remote_filename,
		const char *local_filename) {

	return FileWaiter::checkoutFile(proto, master_ip, server_port,
			remote_filename, local_filename);
}

int c_checkinFile(const char *proto, const char *master_ip,
		const char *server_port, const char *remote_filename,
		const char *local_filename) {

	return FileWaiter::checkinFile(proto, master_ip, server_port,
			remote_filename, local_filename);
}

int c_checkinFile2(const char *proto, const char *master_ip,
		const char *current_ip, const char *server_port,
		const char *remote_filename, const char *local_filename) {

	return FileWaiter::checkinFile(proto, master_ip, current_ip, server_port,
			remote_filename, local_filename);
}

#include <string.h>
#include "../ffsnet/ffsnet.h"
#include "NeighborUtil.h"
#include "NeighborUtil-c.h"

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

FileWaiter::FileWaiter() {
}

FileWaiter::~FileWaiter() {
}

int FileWaiter::checkoutFile(const char *proto, const char *master_ip,
		const char *server_port, const char *remote_filename,
		const char *local_filename) {

	int rs = ffs_recvfile(proto, master_ip, server_port, remote_filename,
			local_filename);

	if (rs == 0) //succeed in pulling master copy
		return rs;

	/*otherwise, try 1st replica*/
	rs = ffs_recvfile(proto, c_get1stReplicaAddr(master_ip), server_port,
			remote_filename, local_filename);
	if (rs == 0) //succeed in pulling 1st replica
		return rs;

	/*otherwise, try 2nd replica*/
	rs = ffs_recvfile(proto, c_get2ndReplicaAddr(master_ip), server_port,
			remote_filename, local_filename);

	return rs;
}

int FileWaiter::checkinFile(const char *proto, const char *master_ip,
		const char *server_port, const char *remote_filename,
		const char *local_filename) {

	/*update master copy*/
	int rs = ffs_sendfile(proto, master_ip, server_port, remote_filename,
			local_filename);

	/*update the first replica*/
	rs = ffs_sendfile(proto, c_get1stReplicaAddr(master_ip), server_port,
			remote_filename, local_filename);

	/*update the second replica*/
	rs = ffs_sendfile(proto, c_get2ndReplicaAddr(master_ip), server_port,
			remote_filename, local_filename);

	return rs;
}

int FileWaiter::checkinFile(const char *proto, const char *master_ip,
		const char *current_ip, const char *server_port,
		const char *remote_filename, const char *local_filename) {

	/*update master copy*/
	int rs = ffs_sendfile(proto, master_ip, server_port, remote_filename,
			local_filename);

	/*update the first replica*/
	const char *_1stIp = c_get1stReplicaAddr(master_ip);

	if (strcmp(_1stIp, current_ip)) { //not the current node, so update the replica on it

		rs = ffs_sendfile(proto, _1stIp, server_port, remote_filename,
				local_filename);
	}

	/*update the second replica*/
	const char *_2ndIp = c_get2ndReplicaAddr(master_ip);

	if (strcmp(_2ndIp, current_ip)) { //not the current node, so update the replica on it

		rs = ffs_sendfile(proto, _2ndIp, server_port, remote_filename,
				local_filename);
	}

	return rs;
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
