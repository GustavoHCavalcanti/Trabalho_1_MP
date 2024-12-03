# Nome do executável final
TARGET = testa_velha

# Compilador e flags de compilação
CXX = g++
CXXFLAGS = -std=c++14 -Wall -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread

# Arquivos fonte e objeto
SOURCES = testa_velha.cpp velha.cpp
OBJECTS = velha.o

# Diretório para arquivos de cobertura
COVERAGE_DIR = coverage

# Regra padrão - compilar e executar
all: $(TARGET) move_coverage_files
	./$(TARGET)

# Regra para compilar o executável final
$(TARGET): $(OBJECTS) testa_velha.cpp
	$(CXX) $(CXXFLAGS) -ftest-coverage -fprofile-arcs $(OBJECTS) testa_velha.cpp $(LDFLAGS) -o $(TARGET)

# Compilação do arquivo objeto
velha.o: velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c velha.cpp

# Teste com o Google Test
test: $(TARGET)
	./$(TARGET)

# Mover arquivos de cobertura para o diretório 'coverage'
move_coverage_files:
	mkdir -p $(COVERAGE_DIR)
	mv *.gcda *.gcno *.gcov $(COVERAGE_DIR)/ 2>/dev/null || true

# Limpeza dos arquivos de cobertura
clean_coverage:
	rm -rf $(COVERAGE_DIR)

# Limpeza geral
clean: clean_coverage
	rm -f *.o *.exe $(TARGET)

