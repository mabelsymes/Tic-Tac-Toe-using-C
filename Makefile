# Define the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g

# Define the target executable and the object files
TARGET = tic_tac_toe
OBJS = tic_tac_toe.o running_game.o non_game_funcs.o game_states.o computer.o basic_funcs_data.o

# The first rule is the default rule that will be executed when running 'make'
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# COMPILATION RULES ------------------------------------------------------------------------------------------

# Rule for compiling tic_tac_toe.c to tic_tac_toe.o
tic_tac_toe.o: tic_tac_toe.c running_game.h non_game_funcs.h
	$(CC) $(CFLAGS) -c tic_tac_toe.c

# Rule for compiling running_game.c to running_game.o
running_game.o: running_game.c running_game.h game_states.h computer.h basic_funcs_data.h non_game_funcs.h
	$(CC) $(CFLAGS) -c running_game.c

# Rule for compiling non_game_funcs.c to non_game_funcs.o
non_game_funcs.o: non_game_funcs.c non_game_funcs.h
	$(CC) $(CFLAGS) -c non_game_funcs.c

# Rule for compiling game_states.c to game_states.o
game_states.o: game_states.c game_states.h basic_funcs_data.h
	$(CC) $(CFLAGS) -c game_states.c

# Rule for compiling computer.c to computer.o
computer.o: computer.c computer.h basic_funcs_data.h game_states.h
	$(CC) $(CFLAGS) -c computer.c

# Rule for compiling basic_funcs_data.c to basic_funcs_data.o
basic_funcs_data.o: basic_funcs_data.c basic_funcs_data.h
	$(CC) $(CFLAGS) -c basic_funcs_data.c

# -----------------------------------------------------------------------------------------------------------

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET) $(OBJS)
