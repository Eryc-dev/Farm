# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I. # -I. tells the compiler to look for headers in the current directory

# Executables
MAIN_GAME = farm_game
TEST_ANIMAL_EXEC = test_animal
TEST_PLANT_EXEC = test_plant

# Source files for the main game
MAIN_GAME_SRC = main.cpp

# Source files for unit tests
TEST_ANIMAL_SRC = test_Animal.cpp
TEST_PLANT_SRC = test_Plant.cpp

MAIN_GAME_HEADERS = Stock.h Animal.h Plant.h Inventory.h Market.h SpecificAnimal.h Vegetable.h

TEST_ANIMAL_HEADERS = Stock.h Animal.h SpecificAnimal.h

TEST_PLANT_HEADERS = Stock.h Plant.h Vegetable.h

# Default target
all: $(MAIN_GAME)

# Rule to build the main game
$(MAIN_GAME): $(MAIN_GAME_SRC) $(MAIN_GAME_HEADERS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_GAME) $(MAIN_GAME_SRC)

$(TEST_ANIMAL_EXEC): $(TEST_ANIMAL_SRC) $(TEST_ANIMAL_HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST_ANIMAL_EXEC) $(TEST_ANIMAL_SRC)

$(TEST_PLANT_EXEC): $(TEST_PLANT_SRC) $(TEST_PLANT_HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST_PLANT_EXEC) $(TEST_PLANT_SRC)

test: $(TEST_ANIMAL_EXEC) $(TEST_PLANT_EXEC)
	@echo "--- Running Animal Test ---"
	./$(TEST_ANIMAL_EXEC)
	@echo "\n--- Running Plant Test ---"
	./$(TEST_PLANT_EXEC)
	@echo "\n--- All Tests Complete ---"

clean:
	rm -f $(MAIN_GAME) $(TEST_ANIMAL_EXEC) $(TEST_PLANT_EXEC) *.o

.PHONY: all test clean