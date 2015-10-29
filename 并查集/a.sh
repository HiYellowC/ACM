g++ a.c
./a.out > t
g++ b.cpp
./a.out < t > t1
g++ bb.cpp
./a.out < t > t2
diff t1 t2
