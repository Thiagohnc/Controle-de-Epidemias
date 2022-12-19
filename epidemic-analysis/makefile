all: clean epidemic_analysis

epidemic_analysis: epidemic_analysis.o utils.o epidemic_modeling.o
	g++ epidemic_analysis.o utils.o epidemic_modeling.o -o epidemic_analysis -Wall

epidemic_analysis.o: epidemic_analysis.cpp utils.hpp epidemic_modeling.hpp
	g++ epidemic_analysis.cpp -c -o epidemic_analysis.o -Wall

epidemic_modeling.o: epidemic_modeling.cpp epidemic_modeling.hpp utils.hpp
	g++ epidemic_modeling.cpp -c -o epidemic_modeling.o -Wall

utils.o: utils.cpp utils.hpp
	g++ utils.cpp -c -o utils.o -Wall

clean:
	rm -rf *.o *~ epidemic_analysis