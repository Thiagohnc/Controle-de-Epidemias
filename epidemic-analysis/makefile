all: clean epidemic_analysis

epidemic_analysis: epidemic_analysis.o utils.o epidemic_modeling.o control_methods.o quarantine.o vaccination.o random_vaccination.o degree_vaccination.o
	g++ epidemic_analysis.o utils.o epidemic_modeling.o control_methods.o quarantine.o vaccination.o random_vaccination.o degree_vaccination.o -o epidemic_analysis -Wall

epidemic_analysis.o: epidemic_analysis.cpp utils.hpp epidemic_modeling.hpp
	g++ epidemic_analysis.cpp -c -o epidemic_analysis.o -Wall
	
degree_vaccination.o: degree_vaccination.cpp degree_vaccination.hpp vaccination.hpp control_methods.hpp utils.hpp
	g++ degree_vaccination.cpp -c -o degree_vaccination.o -Wall

random_vaccination.o: random_vaccination.cpp random_vaccination.hpp vaccination.hpp control_methods.hpp utils.hpp
	g++ random_vaccination.cpp -c -o random_vaccination.o -Wall

vaccination.o: vaccination.cpp vaccination.hpp control_methods.hpp utils.hpp
	g++ vaccination.cpp -c -o vaccination.o -Wall

quarantine.o: quarantine.cpp quarantine.hpp control_methods.hpp utils.hpp
	g++ quarantine.cpp -c -o quarantine.o -Wall

control_methods.o: control_methods.cpp control_methods.hpp epidemic_modeling.hpp utils.hpp
	g++ control_methods.cpp -c -o control_methods.o -Wall

epidemic_modeling.o: epidemic_modeling.cpp epidemic_modeling.hpp utils.hpp
	g++ epidemic_modeling.cpp -c -o epidemic_modeling.o -Wall

utils.o: utils.cpp utils.hpp
	g++ utils.cpp -c -o utils.o -Wall

clean:
	rm -rf *.o *~ epidemic_analysis