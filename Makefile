CC=gcc
CPP=g++
CFLAGS=-Wall -W -g -pipe -fPIC

# -----  help  -----
# @ 不显示命令
# - 忽略错误
# .PHONY 和 all 伪目标
# gcc -MM *.c 生成依赖
# $<  依赖集
# $@  目标集
# ------------------

all: Robot
	@rm -rf output
	@mkdir -p output && cd output && mkdir arobot && cd arobot && mkdir -p lib && mkdir -p deps
	@cp Robot output/arobot/
	@cp lib/*.so output/arobot/lib/
	@cp deps/*.so output/arobot/deps/
	@echo "done!"

ROBOTO=robot.o stat.o live.o

#dep
Robot: dependencies $(ROBOTO)
live.o: live.c robot.h live.h
stat.o: stat.c stat.h robot.h
robot.o: robot.c stat.h robot.h live.h lib/run.h lib/sit.h lib/sleep.h \
 lib/walk.h

.PHONY: dependencies
dependencies: 
	@cd lib && make
	@cd deps && make


#cc
robot.o:
	$(CC) -c $(CFLAGS) $<
stat.o:
	$(CC) -c $(CFLAGS) $<
live.o:
	$(CC) -c $(CFLAGS) $<

Robot:
	$(CC) -o Robot $(ROBOTO) -Llib -lstic lib/libdyna.so -ldl


.PHONY: install
install:
	@echo "Enter output and run application !"


.PHONY: clean
clean:
	@rm -rf *.o 
	@rm -f Robot
	@rm -rf output
	@cd lib && make clean
	@cd deps && make clean
