#!/bin/bash
# run simulation on flapmodels
# run as:
# runsim.sh parameterfile.txt

# path to configuration (model parameter files):
CONFPATH=/usr/local/src/experiment/flapmodel/conf

# path to results:
RESPATH=/usr/local/tmpdata/flapmodel

# parameters:
PRE=${1%.txt}
FVAL=`seq 80.00 10.00 120.00`
T=20

ANG=az-180_1_180_el-90_1_90.ang
MPIEXEC=/usr/src/petsc/linux-gnu/bin/mpiexec
MACHFILE=/etc/mpich-mpd/machines.LINUX
NP=8

# generate shape (vsp-file):
#flapmodel $CONFPATH/$PRE\.txt

# move vsp-file to result directory:
#mv $CONFPATH/$PRE\.vsp $RESPATH

# generate a surface mesh (vtk-file, scale in mm):
#srfmsh -s1000,1000,1000  $RESPATH/$PRE\.vsp

# show shape & exit:
#showmodel.sh $RESPATH/$PRE\.vtk &
#exit

# generate FEM-mesh
#femmesher $RESPATH/$PRE.vsp
#exit

# write angle file:
#angwrite -a-180,180,1 -e-90,90,1 $RESPATH/az-180_1_180_el-90_1_90.ang

for F in $FVAL ; do 

# assemble system-matrix
		femassembler -f$F -T$T $RESPATH/$PRE.msh ;

#		scp $RESPATH/$PRE\_f$F\kHzT$T\.00C.sys atlanta:$RESPATH ;

# solve linear problem
 
		time $MPIEXEC -n $NP \
				/usr/local/bin/femsolver \
				-mat_no_inode \
				-pc_type sor -pc_sor_omega 1.2 \
				-ksp_type bcgs \
				-ksp_atol 1e-6 \
				-ksp_max_it 2000 \
				$RESPATH/$PRE\_f$F\kHzT$T\.00C.sys ;

# remove sys-file(s)
#		rm $RESPATH/$PRE\_f$F\kHzT$T\.00C.sys
#		ssh -n atlanta rm $RESPATH/$PRE\_f$F\kHzT$T\.00C.sys

		femprojector -f$F -T$T $RESPATH/$PRE\.msh $RESPATH/$ANG ;

done






