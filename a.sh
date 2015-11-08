g++ a.c
./a.out > t
g++ c.cpp
./a.out < t > t1
g++ cc.cpp
./a.out < t > t2
diff t1 t2

