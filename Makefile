# Nome do executável final
TARGET = testa_velha

# Compilador e flags de compilação
CXX = g++
CXXFLAGS = -std=c++14 -Wall -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread

# Arquivos fonte e objeto
SOURCES = testa_velha.cpp velha.cpp
OBJECTS = velha.o

# Regra padrão - compilar e executar
all: $(TARGET)
	./$(TARGET)

# Regra para compilar o executável final
$(TARGET): $(OBJECTS) testa_velha.cpp
	$(CXX) $(CXXFLAGS) $(OBJECTS) testa_velha.cpp $(LDFLAGS) -o $(TARGET)

# Compilação do arquivo objeto
velha.o: velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c velha.cpp

# Teste com o Google Test
test: $(TARGET)
	./$(TARGET)

# Limpeza dos arquivos gerados
clean:
	rm -rf *.o *.exe *.gc* $(TARGET)
