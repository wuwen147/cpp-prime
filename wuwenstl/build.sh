#!/bin/bash
startTime=`date +"%Y-%m-%d %H:%M:%S"`

rm -rf bin
rm -rf build

mkdir build
cd build

cmake ..
make -j

mv bin/ ../
cd ..

endTime=`date +"%Y-%m-%d %H:%M:%S"`
st=`date -d "$startTime" +%s`
et=`date -d "$endTime" +%s`
sumTime=$(($et-$st))
echo "time cost: $sumTime second."
