CC=gcc
CPP=g++
CFLAGS=-Wall -W -g -pipe -fPIC

# -----  help  -----
#  #  # @ 不显示命令
# - 忽略错误
#   #   # .PHONY 和 all 伪目标
# gcc -MM *.c 生成依赖
# # # $<  依赖集
# # # $@  目标集
# # # ------------------
# #
#


LIBGENIUSSO=genius.so
LIBGENIUSOBJ=hear.o say.o

all: $(LIBGENIUSSO)


#dep
hear.o: hear.c
say.o: say.c

$(LIBGENIUSSO): $(LIBGENIUSOBJ)



#cc
hear.o:
	$(CC) -c $(CFLAGS) $<
say.o:
	$(CC) -c $(CFLAGS) $<

$(LIBGENIUSSO):
	$(CC) -shared -o $(LIBGENIUSSO) $(LIBGENIUSOBJ)


.PHONY: clean
clean:
	@rm -f *.o
	@rm -f *.so
	@echo "done!"
