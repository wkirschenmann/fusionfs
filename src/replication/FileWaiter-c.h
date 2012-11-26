/*
 * FileWaiter-c.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef FILEWAITER_C_H_
#define FILEWAITER_C_H_


#ifdef __cplusplus
# define FFS_CPP(x) x
#else
# define FFS_CPP(x)
#endif

FFS_CPP(extern "C" {)

	int c_checkoutFile(const char *proto, const char *master_ip,
			const char *server_port, const char *remote_filename,
			const char *local_filename);

	int c_checkinFile(const char *proto, const char *master_ip,
			const char *server_port, const char *remote_filename,
			const char *local_filename);

	int c_checkinFile2(const char *proto, const char *master_ip,
			const char *current_ip, const char *server_port,
			const char *remote_filename, const char *local_filename);

	FFS_CPP (})

#endif /* FILEWAITER_C_H_ */
