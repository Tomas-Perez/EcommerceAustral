/*
 * InputTool.h
 *
 *  Created on: 30 may. 2017
 *      Author: Ignacio Gilardoni

 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef SRC_INPUTTOOL_H_
#define SRC_INPUTTOOL_H_

typedef struct inputTool InputTool;
int getLine(char *prmpt, char *buff, size_t sz);
int getOption(char *prmpt);
void pauseProgram(char *prmpt);
#endif /* SRC_INPUTTOOL_H_ */
