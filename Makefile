CXXFLAGS =	-g -Wall -Wno-unused-result -fmessage-length=0 -D__eXYZ__




OBJS =		uva_11343.o

TARGET =	normal

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
