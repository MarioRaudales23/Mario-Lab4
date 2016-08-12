Point:	inicio.o TrianguloPascal.o
	g++ inicio.o TrianguloPascal.o -o Point
inicio.o:	main.cpp TrianguloPascal.h
	g++ -c main.cpp -o inicio.o
triangulo.o:	TrianguloPascal.cpp TrianguloPascal.h
	g++ -c TrianguloPascal.cpp -o triangulo.o
