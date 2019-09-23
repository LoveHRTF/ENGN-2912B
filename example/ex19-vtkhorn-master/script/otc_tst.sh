#!/bin/bash
# test otc shapes
# run as:
# otc_tst.sh parameterfile.txt (without path)

# prefix:
PRE=${1%.txt}

# path to configuration (model parameter files):
CONFPATH=/usr/local/src/experiment/flapmodel/conf

# path to results:
RESPATH=/usr/local/tmpdata/flapmodel


# generate shape (vsp-file):
flapmodel $CONFPATH/$PRE\.txt

# move vsp-file to result directory:
mv $CONFPATH/$PRE\.vsp $RESPATH

# generate a surface mesh (vtk-file, scale in mm):
srfmsh -s1000,1000,1000 $RESPATH/$PRE\.vsp

# show shape:
showmodel.sh $RESPATH/$PRE\.vtk &
