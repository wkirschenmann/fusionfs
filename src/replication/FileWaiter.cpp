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

int c_rmFile(const char *proto, const char *master_ip, const char *current_ip,
		const char *server_port, const char *remote_filename,
		const char *local_filename) {

	return FileWaiter::rmFile(proto, master_ip, current_ip, server_port,
			remote_filename, local_filename);
}

#include <string.h>
#include "../ffsnet/ffsnet.h"
#include "NeighborUtil.h"
#include "NeighborUtil-c.h"
#include <pthread.h>

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

class ThreadArg {

public:
	ThreadArg(const char *proto, const char *replica_ip,
			const char *server_port, const char *remote_filename,
			const char *local_filename) {

		this->proto = proto;
		this->replica_ip = replica_ip;
		this->server_port = server_port;
		this->remote_filename = remote_filename;
		this->local_filename = local_filename;
	}

public:
	const char *proto;
	const char *replica_ip;
	const char *server_port;
	const char *remote_filename;
	const char *local_filename;
};

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

	/*	update master copy
	 int rs = ffs_sendfile(proto, master_ip, server_port, remote_filename,
	 local_filename);*/

	/*update the first replica*/
	const char *_1stIp = c_get1stReplicaAddr(master_ip);

#if ASYNC
	pthread_t wthread;
	ThreadArg ta(proto, _1stIp, server_port, remote_filename, local_filename);

	pthread_create(&wthread, NULL, updateReplica, (void*) &ta);
#else
	int rs = ffs_sendfile(proto, _1stIp, server_port, remote_filename,
			local_filename);
#endif

	/*update the second replica*/
	const char *_2ndIp = c_get2ndReplicaAddr(master_ip);

#if ASYNC
	ThreadArg ta(proto, _2ndIp, server_port, remote_filename, local_filename);

	pthread_create(&wthread, NULL, updateReplica, (void*) &ta);
#else
	rs = ffs_sendfile(proto, _2ndIp, server_port, remote_filename,
			local_filename);
#endif

#if ASYNC
	return 0;
#else
	return rs;
#endif
}

int FileWaiter::checkinFile(const char *proto, const char *master_ip,
		const char *current_ip, const char *server_port,
		const char *remote_filename, const char *local_filename) {

	/*update master copy*/
	int rs = ffs_sendfile(proto, master_ip, server_port, remote_filename,
			local_filename);

	/*update the first replica*/
	const char *_1stIp = c_get1stReplicaAddr(master_ip);

	if (strcmp(_1stIp, current_ip)) { //current node is for replica, so update replica

#if ASYNC
		pthread_t wthread;
		ThreadArg ta(proto, _1stIp, server_port, remote_filename, local_filename);

		pthread_create(&wthread, NULL, updateReplica, (void*) &ta);
#else
		rs = ffs_sendfile(proto, _1stIp, server_port, remote_filename,
				local_filename);
#endif
	}

	/*update the second replica*/
	const char *_2ndIp = c_get2ndReplicaAddr(master_ip);

	if (strcmp(_2ndIp, current_ip)) { //current node is for replica, so update replica

#if ASYNC
		pthread_t wthread;
		ThreadArg ta(proto, _2ndIp, server_port, remote_filename, local_filename);

		pthread_create(&wthread, NULL, updateReplica, (void*) &ta);
#else
		rs = ffs_sendfile(proto, _2ndIp, server_port, remote_filename,
				local_filename);
#endif
	}

	return rs;
}

void* FileWaiter::updateReplica(void* const arg) {

	ThreadArg* pta = (ThreadArg*) arg;

	int rs = ffs_sendfile(pta->proto, pta->replica_ip, pta->server_port,
			pta->remote_filename, pta->local_filename);
}

int FileWaiter::rmFile(const char *proto, const char *master_ip,
		const char *current_ip, const char *server_port,
		const char *remote_filename, const char *local_filename) {

	int rs = 0;

	const char *_1stIp = c_get1stReplicaAddr(master_ip);

	const char *_2ndIp = c_get2ndReplicaAddr(master_ip);

	if (strcmp(_1stIp, current_ip) && strcmp(_2ndIp, current_ip)) { //not 1st and 2nd replica address

		rs = ffs_rmfile("udt", current_ip, "9000", local_filename); //xbz
	}

	return rs;
}

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
