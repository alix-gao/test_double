set -e

if [ ! -d build ] ; then
	mkdir build
fi

cmake -B build #-DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
cmake --build build -v 
./build/tests/tests
