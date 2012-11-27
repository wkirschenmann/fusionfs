/*
 * FileWaiter.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef FILEWAITER_H_
#define FILEWAITER_H_

namespace iit {
namespace cs495 {
namespace proj5 {
namespace dfs {
namespace replication {

/*
 *
 */
class FileWaiter {
public:
	FileWaiter();
	virtual ~FileWaiter();

	static int checkoutFile(const char *proto, const char *remote_ip,
			const char *server_port, const char *remote_filename,
			const char *local_filename);

	static int checkinFile(const char *proto, const char *remote_ip,
			const char *server_port, const char *remote_filename,
			const char *local_filename);

	static int checkinFile(const char *proto, const char *master_ip,
			const char *current_ip, const char *server_port,
			const char *remote_filename, const char *local_filename);

	static int rmFile(const char *proto, const char *master_ip,
			const char *current_ip, const char *server_port,
			const char *remote_filename, const char *local_filename);

private:
	static void* updateReplica(void* const arg);

};

} /* namespace replication */
} /* namespace dfs */
} /* namespace proj5 */
} /* namespace cs495 */
} /* namespace iit */
#endif /* FILEWAITER_H_ */
