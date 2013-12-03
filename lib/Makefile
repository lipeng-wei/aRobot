CC=gcc
CPP=g++
CFLAGS=-Wall -W -g -pipe -fPIC

# -----  help  -----
#  # @ 不显示命令
# - 忽略错误
#   # .PHONY 和 all 伪目标
# gcc -MM *.c 生成依赖
# # $<  依赖集
# # $@  目标集
# # ------------------
#

LIBDYNASO=libdyna.so
LIBSTICA=libstic.a
LIBDYNAOBJ=walk.o run.o
LIBSTICOBJ=sit.o sleep.o

all: $(LIBSTICA) $(LIBDYNASO)


#dep
run.o: run.c
sit.o: sit.c
sleep.o: sleep.c
walk.o: walk.c

$(LIBSTICA): $(LIBSTICOBJ)
$(LIBDYNASO): $(LIBDYNAOBJ)

#cc
sit.o:
	$(CC) -c $(CFLAGS) $<
sleep.o:
	$(CC) -c $(CFLAGS) $<

$(LIBSTICA):
	ar crv $(LIBSTICA) $(LIBSTICOBJ)
$(LIBDYNASO):
	$(CC) -shared -o $(LIBDYNASO) $(LIBDYNAOBJ)



.PHONY: clean
clean:
	@rm -f *.o
	@rm -f *.a
	@rm -f *.so
	@echo "done!"
