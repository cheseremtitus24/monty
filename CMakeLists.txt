cmake_minimum_required(VERSION 3.16)
project(monty C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(monty
        monty.h
        monty.c
        monty_funcs.c
        get_op_func.c
        _atoi.c
        _trim.c
        _string_toupper.c
        _trim_inbtwn_spaces.c
        _monty_lexer.c
        _realloc.c
        main.c
        )
