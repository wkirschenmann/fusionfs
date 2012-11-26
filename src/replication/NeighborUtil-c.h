/*
 * NeighborUtil-c.h
 *
 *  Created on: Nov 25, 2012
 *      Author: Cheng Shou, Xiaobing Zhou
 */

#ifndef NEIGHBORUTIL_C_H_
#define NEIGHBORUTIL_C_H_

#ifdef __cplusplus
# define FFS_CPP(x) x
#else
# define FFS_CPP(x)
#endif

FFS_CPP(extern "C" {)

	/*set neighbor seeds*/
	void c_setNeighborSeeds(const char *neighborCfg);
	/*get address of the first replica based on master address,
	 * address: 192.168.1.100*/
	const char* c_get1stReplicaAddr(const char *address);
	/*get address of the second replica based on master address,
	 * address: 192.168.1.100*/
	const char* c_get2ndReplicaAddr(const char *address);

	FFS_CPP (})

#endif /* NEIGHBORUTIL_C_H_ */
