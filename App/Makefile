build: 01_graphe.cpp 02_graphe.cpp 03_graphe.cpp 04_graphe.cpp 05_graphe.cpp 06_graphe.cpp 07_graphe.cpp 08_graphe.cpp 01_reduction.cpp 02_reduction.cpp 03_reduction.cpp
	g++ 01_graphe.cpp -o 01_graphe
	g++ 02_graphe.cpp -o 02_graphe
	g++ 03_graphe.cpp -o 03_graphe
	g++ 04_graphe.cpp -o 04_graphe
	g++ 05_graphe.cpp -o 05_graphe
	g++ 06_graphe.cpp -o 06_graphe
	g++ 07_graphe.cpp -o 07_graphe
	g++ 08_graphe.cpp -o 08_graphe
	g++ 01_reduction.cpp -o 01_reduction
	g++ 02_reduction.cpp -o 02_reduction
	g++ 03_reduction.cpp -o 03_reduction

graphe: 01_graphe 02_graphe 03_graphe 04_graphe 05_graphe 06_graphe 07_graphe 08_graphe
	./01_graphe
	./02_graphe
	./03_graphe
	./04_graphe
	./05_graphe
	./06_graphe
	./07_graphe
	./08_graphe

reduction: 01_reduction 02_reduction 03_reduction
	./01_reduction
	./02_reduction
	./03_reduction

full: graphe reduction

clean:
	test -f 01_graphe && rm 0?_graphe
	test -f 01_reduction && rm 0?_reduction
