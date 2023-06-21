mkdir debug
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

cd ..

mkdir release
cd release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .