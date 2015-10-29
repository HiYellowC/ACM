g++ a.c
./a.out > t
g++ r.cpp
./a.out < t > t1
g++ rr.cpp
./a.out < t > t2
diff t1 t2
