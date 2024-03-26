# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -std=c++11 -g

# Include directories
INCLUDES := -I.

# Source files
SOURCES := model/Position/Position.cpp model/Puck/Puck.cpp model/Velocity/Velocity.cpp model/Player/Player.cpp model/Paddle/Paddle.cpp model/Game/Game.cpp model/Collision/CollisionDetection.cpp view/GameRenderer.cpp tests.cpp

# Object files
OBJECTS := $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE := tests

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(OBJECTS)

# To obtain object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# To remove generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)
