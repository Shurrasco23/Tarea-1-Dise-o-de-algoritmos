CC = gcc
CFLAGS = -Wall -I./includes
BUILD_DIR = build

SOURCES = main.c src/commons.c src/csv.c src/menu.c src/sorting.c src/search.c src/shuffler.c src/experimentos.c
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)
EXECUTABLE = tarea1

run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
	
.PHONY: run plot

plot: 
	gnuplot ./plots/plot.gp
