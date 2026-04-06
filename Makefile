# The directories containing your Data Structures
COMPONENTS = STACK QUEUE DEQUE

all:
	@for dir in $(COMPONENTS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(COMPONENTS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all clean
