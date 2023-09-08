TARGET = telnet
OBJS = connection.cpp.o main.cpp.o

CPPFLAGS += -O3

LDFLAGS += -lPocoNet -lPocoFoundation

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.cpp.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)