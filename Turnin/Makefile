CXX = g++
CXXFLAGS = -Wall -std=c++11

# List all executables you want to build
PROGRAMS = Get_Matrix Add_Matrix Mult_Matrix Dia_Sum_Matrix Row_Swap_Matrix Col_Swap_Matrix Update_Matrix

# Default target: build all programs
all: $(PROGRAMS)

# Rule to build each program (%.cpp -> executable)
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up compiled files
clean:
	ifeq ($(OS),Windows_NT)
	del /Q $(PROGRAMS:%=%.exe)
	else
		rm -f $(PROGRAMS)
	endif
