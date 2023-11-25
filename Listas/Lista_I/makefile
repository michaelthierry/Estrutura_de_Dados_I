# @Compiler file
# Compilador
CC = gcc
# Parametros
C_FLAGS = \
	-c \
	-Wall \
	-g \
# Lista de objetos
OBJ = \
	main.o \
	lista.o \

# Regra para gerar executavel
Lista: $(OBJ)
	$(CC) $(OBJ) -o $@

# Regra para arquivos objetos
%.o: %.c 
	$(CC) $(C_FLAGS) $<

# Regra para executar o programa
run: Lista
	clear
	./Lista

# Regra para limpar os objetos
clean:
	rm -f $(OBJ)