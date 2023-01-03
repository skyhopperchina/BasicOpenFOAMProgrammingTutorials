#!/bin/bash
. /usr/lib/openfoam/openfoam2206/etc/bashrc WM_NCOMPROCS=2; export WM_COMPILE_OPTION=Debug
/usr/bin/gdb "$@"