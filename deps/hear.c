/*
 * =====================================================================================
 *
 *       Filename:  hear.c
 *
 *    Description:  robot can hear so
 *
 *        Version:  1.0
 *        Created:  11/13/2013 07:41:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>

void hear(char* re, int l) {
    char buffer[255];
    printf("please say something \n");
    scanf("%s\n", buffer);
    snprintf(re, l, "%s", buffer);
}
