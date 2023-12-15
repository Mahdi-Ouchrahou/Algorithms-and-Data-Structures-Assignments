output1: prob1.o
		g++ -o output1 prob1.o

prob1.o: prob1.cpp
		g++ -o prob1.o -c prob1.cpp

output4: prob4.o
		g++ -o output4 prob4.o
prob4.o: prob4.cpp
		g++ -o prob4.o -c prob4.cpp


output2: prob2h.o prob2.o
		g++ -o output2 prob2h.0 prob2.o
prob2h.o: prob2.h
		g++ -o prob2h.o -c prob2.h
prob2.o: prob2.cpp
		g++ -o prob2.o -c prob2.cpp

remove:
	rm *.o
