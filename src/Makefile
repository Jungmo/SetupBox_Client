CC=gcc
OBJS=SetupBox.o
TARGET=SetupBox

.SUFFIXES:.c .o

all : $(TARGET)
	cp -f client $(TARGET) ../SetupBox/usr/local/bin
$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean : rm -f ../SetupBox/usr/local/bin/$(TARGET)
	rm -f $(OBJS) $(TARGET)
