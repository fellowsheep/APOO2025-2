# --- Variáveis de Configuração ---
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET = main
SOURCES = main.cpp Animal.cpp Cachorro.cpp GerenciadorSom.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# --- Regras (Targets) ---

# Regra padrão: compila o executável
all: $(TARGET)

# Regra para "linkar" o executável final
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regra "padrão" para compilar .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# NOVO: Regra para executar
# O 'run' depende do 'all', então o 'make' vai primeiro
# garantir que tudo esteja compilado antes de executar.
run: all
	./$(TARGET)

# Alvo padrão para limpar apenas os arquivos objeto (.o)
clean:
	del /F /Q *.o

# Alvo para limpar TUDO (objetos e executável)
cleanall: clean
	del /F /Q $(TARGET).exe