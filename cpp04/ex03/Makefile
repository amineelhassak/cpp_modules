SRCS = $(wildcard *.cpp)
HPP = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXEC =	AMateria

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp $(HPP)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all