CXXFLAGS =	-O2 -g -Wall -Werror -fmessage-length=0

OBJS =		CppNotes.o

LIBS =

TARGET =	CppNotes

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
