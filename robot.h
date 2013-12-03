#ifndef __ROBOT_H_
#define __ROBOT_H_

#define AROBOT_EXIT " quit bye exit "
#define AROBOT_ACTION "action"


extern char * actionType;

typedef void (hearFuncT)(char*, int);
typedef void (sayFuncT)(char*);

typedef struct dynamic_type {
    hearFuncT *hear;
    sayFuncT *say;
} dyType;

dyType *dyf;
void (*sayf)(char*);
void (*hearf)(char*, int);


void wrong();
void full(char* str);

#endif //__ROBOT_H_
