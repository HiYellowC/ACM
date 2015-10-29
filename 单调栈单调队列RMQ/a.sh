g++ a.c
./a.out > t
g++ h3415.cpp
./a.out < t > t1
g++ aa.cpp
./a.out < t > t2
diff t1 t2
