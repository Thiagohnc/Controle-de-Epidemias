all: clean epidemic_analysis

epidemic_analysis: epidemic_analysis.o utils.o epidemic_modeling.o control_methods.o quarantine.o
	g++ epidemic_analysis.o utils.o epidemic_modeling.o control_methods.o quarantine.o -o epidemic_analysis -Wall

epidemic_analysis.o: epidemic_analysis.cpp utils.hpp epidemic_modeling.hpp
	g++ epidemic_analysis.cpp -c -o epidemic_analysis.o -Wall

quarantine.o: quarantine.hpp control_methods.hpp utils.hpp
	g++ quarantine.cpp -c -o quarantine.o -Wall

control_methods.o: control_methods.hpp epidemic_modeling.hpp utils.hpp
	g++ control_methods.cpp -c -o control_methods.o -Wall

epidemic_modeling.o: epidemic_modeling.cpp epidemic_modeling.hpp utils.hpp
	g++ epidemic_modeling.cpp -c -o epidemic_modeling.o -Wall

utils.o: utils.cpp utils.hpp
	g++ utils.cpp -c -o utils.o -Wall

clean:
	rm -rf *.o *~ epidemic_analysis