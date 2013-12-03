/*
 * =====================================================================================
 *
 *       Filename:  live.c
 *
 *    Description:  robot can eat drink so
 *
 *        Version:  1.0
 *        Created:  11/13/2013 07:46:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>

#include"robot.h"

int eat(char * food) {
    static int times = 0;
    times ++;
    if ( times > 2 ) {
        full("eat");
        times = 0;
    } else {
        printf("I can eat%s\n", food);
    }
    return 0;
}

int drink(char * water) {
    static int times = 0;
    times ++;
    if ( times > 3 ) {
        full("drink");
        times = 0;
    } else {
        printf("I can drink%s\n", water);
    }
    return 0;
}

