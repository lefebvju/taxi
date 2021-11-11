CXX = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = prog
RM = rm -rf

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^

clean :
	$(RM) $(OBJ)

mrproper : clean
	$(RM) $(EXEC)
