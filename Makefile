

#@author Lefebvre Julien

CXX = g++ -Wall
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HDR = $(wildcard *.hpp)
EXEC = prog
RM = rm -rf
LDFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

#lance la création de l'executable
all : $(EXEC) clean

#chaque fichier .o nécessaire à la création du projet est obtenu à partir du fichier .cpp et .hpp
%.o : %.cpp
	$(CXX) -o $@ -c $< $(LDFLAGS)

#fichier $(EXEC) est obtenue grâce à la liste des .o
$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

#supprime les .o
clean :
	$(RM) $(OBJ)

#supprime les .o plus l'executable
mrproper : clean
	$(RM) $(EXEC)
