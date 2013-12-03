/*
 * =====================================================================================
 *
 *       Filename:  robot.c
 *
 *    Description:  robot main
 *
 *        Version:  1.0
 *        Created:  11/13/2013 09:06:42 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dlfcn.h>

#include"stat.h"
#include"robot.h"
#include"live.h"
#include"lib/sit.h"
#include"lib/sleep.h"
#include"lib/walk.h"
#include"lib/run.h"

char * actionType = "init";
void *dlhandler;

void wrong() {
    printf("!!! I don`t konw what you want . \n");
}

void full(char* str) {
    printf("wa !!! I am full ,i can`t %s any more \n", str);
}

int init() {
    dyf = (dyType*)calloc(1, sizeof(dyType));
    if (dyf == NULL) {
        printf("oom when calloc\n");
        return -1;
    }
    dlhandler = dlopen("deps/genius.so", RTLD_NOW);
    if (dlhandler == NULL) {
        printf("dlopen failed for %s\n", dlerror());
        return -1;
    }
    dyf->hear = dlsym(dlhandler, "hear");
    char *err;
    if ((err = dlerror())) {
        printf("fali to find function hear for %s\n", err);
        return -1;
    }

    dyf->say = dlsym(dlhandler, "say");
    if ((err = dlerror())) {
        printf("fali to find function say for %s\n", err);
        return -1;

    }
    sayf = dyf->say;
    hearf = dyf->hear;

    return 0;
}

int main() {
    if ( init() == 0 ) {
        printf("aRobot init success !\n");
    } else {
        printf("aRobot init failed , and exit\n");
        return 0;
    }
    char raw[25];
    int lebal = 0;

    fgets(raw, 20, stdin);
    raw[strlen(raw)-1]='\0';

    while ( raw[0] == '\0' || strstr(AROBOT_EXIT, raw) == NULL) {
        lebal = 0;
        if (strcmp(raw, AROBOT_ACTION) == 0 ) {
            lebal = 1;
            action();
        }
        if (strcmp(raw, STAT_ACTION_SIT) == 0 ) {
            lebal = 1;
            actionType = STAT_ACTION_SIT;
            sit();

        }
        if (strcmp(raw, STAT_ACTION_SLEEP) == 0 ) {
            lebal = 1;
            actionType = STAT_ACTION_SLEEP;
            sleep();

        }
        if (strcmp(raw, STAT_ACTION_WALK) == 0 ) {
            lebal = 1;
            actionType = STAT_ACTION_WALK;
            walk();

        }
        if (strcmp(raw, STAT_ACTION_RUN) == 0 ) {
            lebal = 1;
            actionType = STAT_ACTION_RUN;
            run();

        }
        if (strncmp(raw, STAT_ACTION_EAT, strlen(STAT_ACTION_EAT)) == 0 ) {
            lebal = 1;
            actionType = STAT_ACTION_EAT;
            eat(raw+strlen(STAT_ACTION_EAT));
        }
        if (strcmp(raw, STAT_ACTION_HEAR_AND_SAY) == 0 ) {
            lebal = 1;
            actionType = STAT_ACTION_HEAR_AND_SAY;
            char word[255];
            dyf->hear(word, 255);
            dyf->say(word);
            //hearf(word, 255);
            //sayf(word);
        }
        if (strncmp(raw, STAT_ACTION_DRINK, strlen(STAT_ACTION_DRINK)) == 0 ) {
            lebal = 1;
            actionType = STAT_ACTION_DRINK;
            drink(raw + strlen(STAT_ACTION_DRINK) );

        }
        if ( ! lebal ) {
            wrong();
        }
        fgets(raw, 20, stdin);
        raw[strlen(raw)-1]='\0';

    }
    printf("Bye bye !\n");
    if (dlhandler) dlclose(dlhandler);
    return 0;

}
