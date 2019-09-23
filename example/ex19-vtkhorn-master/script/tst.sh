#!/bin/bash

# path to results:
RESPATH=/usr/local/tmpdata/flapmodel

# parameters:
PRE=otc_13mm_flap_30deg_left
F=30.00
T=20


while read line; do 
    scp $RESPATH/$PRE\_f$F\kHzT$T\.00C.sys ${line}:$RESPATH/$PRE\_f$F\kHzT$T\.00C.sys; 
done < <(cat machines.txt)