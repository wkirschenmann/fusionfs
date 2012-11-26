#include <stdio.h>
#include <iostream>
using namespace std;

#include "KeyEntry.h"
#include "ValueEntry.h"
#include "Address.h"

using namespace iit::cs495::proj5::dfs::replication;

void testEntry() {

	KeyEntry ke(
			"/home/xiaobingo/IIT-study/course/cs495/proj5/fusionfs/src/zht:prime");

	cout << ke.toString() << endl;
	cout << ke.first() << endl;
	cout << ke.second() << endl;

	ke.first(
			"/home/xiaobingo/IIT-study/course/cs495/proj5/fusionfs/src/replication/test");
	ke.second("prime");

	cout << ke.toString() << endl;
	cout << ke.first() << endl;
	cout << ke.second() << endl;

	ValueEntry ve(
			"192.168.1.100:5000;192.168.1.101:5000;192.168.1.102:5000;192.168.1.103:5000;192.168.1.104:5000");

	cout << ve.toString() << endl;
}

void testAddress() {

	Address add("192.168.1.100:5000");

	cout << add.toString() << endl;
	cout << add.host() << endl;
	cout << add.port() << endl;

	add.assign("192.168.1.101:5000");

	cout << add.toString() << endl;
	cout << add.host() << endl;
	cout << add.port() << endl;
}

int main(int argc, char** argv) {

//	fprintf(stderr, "\n", "hello, main");

	testAddress();

	return 0;
}

