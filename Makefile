# Nome do executável final
TARGET = testa_velha

# Compilador e flags de compilação
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Arquivos fonte e objeto
SOURCES = testa_velha.cpp velha.cpp
OBJECTS = velha.o

# Regra padrão - compilar e executar
all: $(TARGET)
	./$(TARGET)

# Regra para compilar o executável final
$(TARGET): $(OBJECTS) testa_velha.cpp
	$(CXX) $(CXXFLAGS) $(OBJECTS) testa_velha.cpp -o $(TARGET)

# Compilação do arquivo objeto
velha.o: velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c velha.cpp

# Teste do programa
test: $(TARGET)
	./$(TARGET)

# Análise de estilo com cpplint
cpplint:
	cpplint --exclude=catch.hpp $(SOURCES)

# Cobertura de código com gcov
gcov: $(SOURCES)
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c velha.cpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage velha.o testa_velha.cpp -o $(TARGET)
	./$(TARGET)
	gcov *.cpp

# Debug com gdb
debug: $(SOURCES)
	$(CXX) $(CXXFLAGS) -g -c velha.cpp
	$(CXX) $(CXXFLAGS) -g velha.o testa_velha.cpp -o $(TARGET)
	gdb ./$(TARGET)

# Verificação de memória com valgrind
valgrind: $(TARGET)
	valgrind --leak-check=yes --log-file=valgrind.rpt ./$(TARGET)

# Limpeza dos arquivos gerados
clean:
	rm -rf *.o *.exe *.gc* $(TARGET)
