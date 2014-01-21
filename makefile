TARGET := example
OBJS := main.o xdg_helper.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)
