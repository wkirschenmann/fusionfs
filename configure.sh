#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/mnt/common/dzhao/fusionFS/src/ffsnet:/mnt/common/dzhao/fusionFS/src/udt/src:/mnt/common/dzhao/gbuf/lib
FFS_HOME=/home/xiaobingo/IIT-study/course/cs495/proj5/fusionfs
echo $FFS_HOME

FFS_SRC_HOME=$FFS_HOME/src
echo $FFS_SRC_HOME

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$FFS_SRC_HOME/ffsnet:$FFS_SRC_HOME/udt/src:/usr/local/lib
echo $LD_LIBRARY_PATH


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/xiaobingo/IIT-study/course/cs495/proj5/fusionfs/src/ffsnet:/home/xiaobingo/IIT-study/course/cs495/proj5/fusionfs/src/udt/src:/usr/local/lib

