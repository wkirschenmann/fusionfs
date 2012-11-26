#FUSEINC=-D_FILE_OFFSET_BITS=64 -I/home/dzhao/bin/libfuse/include/fuse
FUSEINC=-D_FILE_OFFSET_BITS=64 -I/usr/local/include/fuse
#FUSELIB=-pthread -L/home/dzhao/bin/libfuse/lib64 -lfuse -lrt -ldl
FUSELIB=-pthread -L/usr/local/lib -lfuse -lrt -ldl
#GBUFLIB=-L/home/dzhao/bin/gbuffer/lib64
GBUFLIB=-L/usr/local/lib

RPLC=replication
RPLC_OBJS=$(RPLC)/Entry.o $(RPLC)/KeyEntry.o $(RPLC)/ValueEntry.o $(RPLC)/Address.o $(RPLC)/FileWaiter.o $(RPLC)/NeighborUtil.o


fusionfs : librplc.a fusionfs.o util.o log.o 
	gcc -g -Wall -o fusionfs fusionfs.o util.o log.o -Lzht/lib -lzht -L$(RPLC) -lrplc -ludt -lstdc++ $(GBUFLIB) -lprotobuf -lpthread -Lffsnet -lffsnet -lffsnet_bridger ${FUSELIB}

fusionfs.o : fusionfs.c log.h params.h util.h
	gcc -g -Wall ${FUSEINC} -c fusionfs.c -L./ffsnet -L$(RPLC) -lffsnet_bridger -lrplc
	
util.o : util.c log.h params.h
	gcc -g -Wall ${FUSEINC} -c util.c -L./zht/lib -lzht -lstdc++ -lprotobuf -lpthread	

log.o : log.c log.h params.h
	gcc -g -Wall ${FUSEINC} -c log.c



librplc.a : $(RPLC_OBJS)
	ar rus $(RPLC)/librplc.a $(RPLC_OBJS)


$(RPLC)/*.o:
	gcc -g -c $(RPLC)/*.cpp -L/zht/lib -lzht -Lffsnet -lffsnet -lstdc++ -ludt -lpthread	


clean:
	rm -f fusionfs *.o
	rm -f $(RPLC)/*.o

dist:
	rm -rf fuse-tutorial/
	mkdir fuse-tutorial/
	cp ../*.html fuse-tutorial/
	mkdir fuse-tutorial/example/
	mkdir fuse-tutorial/example/mountdir/
	mkdir fuse-tutorial/example/rootdir/
	echo "a bogus file" > fuse-tutorial/example/rootdir/bogus.txt
	mkdir fuse-tutorial/src
	cp Makefile *.c *.h fuse-tutorial/src/
	tar cvzf ../../fuse-tutorial.tgz fuse-tutorial/
	rm -rf fuse-tutorial/
