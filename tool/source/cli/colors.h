#pragma once

#ifndef NOCOLORS

#define CLI_RESET   "\033[0m"
#define CLI_BLACK   "\033[30m"
#define CLI_RED     "\033[31m"
#define CLI_GREEN   "\033[32m"
#define CLI_YELLOW  "\033[33m"
#define CLI_BLUE    "\033[34m"
#define CLI_MAGENTA "\033[35m"
#define CLI_CYAN    "\033[36m"
#define CLI_WHITE   "\033[37m"
#define CLI_BOLD    "\033[1m"

#else

#define CLI_RESET   ""
#define CLI_BLACK   ""
#define CLI_RED     ""
#define CLI_GREEN   ""
#define CLI_YELLOW  ""
#define CLI_BLUE    ""
#define CLI_MAGENTA ""
#define CLI_CYAN    ""
#define CLI_WHITE   ""
#define CLI_BOLD    ""

#endif