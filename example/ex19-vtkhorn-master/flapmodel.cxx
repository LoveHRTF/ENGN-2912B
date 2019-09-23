/* create model for obliquely truncated horn with flap */
/* Rolf Mueller, Sept. 2007 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <cstring>
#include <unistd.h>
#include <math.h>
#include <float.h>
#include <ctype.h>

#include <vtkCone.h>
#include <vtkTransform.h>
#include <vtkPlane.h>
#include <vtkCylinder.h>
#include <vtkImplicitBoolean.h>
#include <vtkSampleFunction.h>
#include <vtkImageData.h>
#include <vtkImageThreshold.h>
#include <vtkImageToStructuredPoints.h>
#include <vtkStructuredPointsWriter.h>
#include <vtkMarchingCubes.h>
#include <vtkPolyData.h>
#include <vtkDecimatePro.h>
#include <vtkSmoothPolyDataFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkStripper.h>
#include <vtkImageData.h>
#include <vtkPolyDataWriter.h>
#include <vtkPLYWriter.h>
#include <vtkSTLWriter.h>


#include "parse.h"

#define NDIM 3

#define RAD2DEG 57.29577951308232
#define DEG2RAD  0.01745329251994

// color to mark the source voxel
#define SCLR 1

void usage(void) {
	printf("usage: flapmodel [options] filename\n"
				 "filename: name of model configuration file (text) \n"
				 "options:\n"
				 "k: output a polygon mesh in VTK format\n"
				 "p: output a polygon mesh in PLY format\n"
				 "s: output a polygon mesh in STL format\n"
				 "v: verbose output\n");
} /* usage */

int main(int argc, char **argv) {
	// cone parameters:
	double coa, cwt, cpch, cpna;
	// flap parameters:
	double fpch, fpnx, fpny, fpnz, ft, fh, fd, fca;
	// canal parameters:
	double cnlh, cnla, cnld, cnll;
	// computational volume & sampling:
	int ns[NDIM];
	double scl, bnd[6];
	// derived parameters:
	double wdz, fhdz, v1[NDIM], v2[NDIM], cp12[NDIM], cp12nrm2, ffd;
	double cnlix, cnliy, cnlhr, carotang, cavx, cavy, cavz, cavn;
	int optval, sx, sy, sz;
	// parameters for polygon mesh creation
	double feature_angle=60;
	// file names & execution flags
	char fpar[PATH_MAX], fout[PATH_MAX], verboseflg=0, vtkflg=0, stlflg=0, plyflg=0, *valstr, *dp;

	/* parse command line options: */
	while ((optval = getopt(argc, argv, "hvkps")) != -1)
		switch (optval) {
		case 'h': /* print help */
			usage();
			exit(EXIT_SUCCESS);
			break;
		case 'v': /* verbose */
			verboseflg=1;
			break;
		case 'k': /* output mesh in VTK-format */
			vtkflg=1;
			break;
		case 's': /* output mesh in STL-format */
			stlflg=1;
			break;
		case 'p': /* output mesh in PLY-format */
			plyflg=1;
			break;
		case '?':
			if (isprint(optopt)) {
				fprintf(stderr, "error: unknown option `-%c'.\n", optopt);
				usage();
			} else {
				fprintf(stderr, "error: unknown option character `\\x%x'.\n",
								optopt);
				usage();
			}
			return(EXIT_FAILURE);
    }

	// name of parameter file (input):
	if ((argc-optind)<1) {
		fprintf(stderr, "error: no parameter filename given\n");
			return(EXIT_FAILURE);
	} else {
		strncpy(fpar, argv[optind], PATH_MAX);
		strncpy(fout, argv[optind], PATH_MAX);
	}

	// name of vsp-file (output):
	if ((dp=strrchr(fout, '.'))==NULL) {
	    fprintf(stderr, "error: parameter filename must contain a dot\n");
	    usage();
	    exit(EXIT_FAILURE);
	}
	snprintf(dp, PATH_MAX, ".vsp");

	// read parameters from file:
	valstr = read_par(fpar, "coa");
	sscanf(valstr, "%lf", &coa);

	valstr = read_par(fpar, "cwt");
	sscanf(valstr, "%lf", &cwt);

	valstr = read_par(fpar, "cpch");
	sscanf(valstr, "%lf", &cpch);

	valstr = read_par(fpar, "cpna");
	sscanf(valstr, "%lf", &cpna);

	valstr = read_par(fpar, "cnlh");
	sscanf(valstr, "%lf", &cnlh);

	valstr = read_par(fpar, "cnla");
	sscanf(valstr, "%lf", &cnla);

	valstr = read_par(fpar, "cnll");
	sscanf(valstr, "%lf", &cnll);

	valstr = read_par(fpar, "cnld");
	sscanf(valstr, "%lf", &cnld);

	valstr = read_par(fpar, "fpch");
	sscanf(valstr, "%lf", &fpch);

	valstr = read_par(fpar, "fpn");
	sscanf(valstr, "%lf,%lf,%lf", &fpnx, &fpny, &fpnz);

	valstr = read_par(fpar, "fh");
	sscanf(valstr, "%lf", &fh);

	valstr = read_par(fpar, "ft");
	sscanf(valstr, "%lf", &ft);

	valstr = read_par(fpar, "fd");
	sscanf(valstr, "%lf", &fd);

	valstr = read_par(fpar, "fca");
	sscanf(valstr, "%lf", &fca);

	valstr = read_par(fpar, "bnd");
	sscanf(valstr, "%lf,%lf,%lf,%lf,%lf,%lf",
				 &(bnd[0]), &(bnd[1]), &(bnd[2]),
				 &(bnd[3]), &(bnd[4]), &(bnd[5]));
	valstr = read_par(fpar, "scl");
	sscanf(valstr, "%lf", &scl);

	// check parameters: ------------------------------------
	// normal vector should have non-zero length:

	if ((fpnx*fpnx+fpny*fpny+fpnz*fpnz)<10*DBL_EPSILON) {
		fprintf(stderr, "warning: flap normal vector has length (%g) close to 0\n",
						(fpnx*fpnx+fpny*fpny+fpnz*fpnz));
	}

	// number of samples:
	ns[0] = (int)rint((bnd[1]-bnd[0])/scl);
	ns[1] = (int)rint((bnd[3]-bnd[2])/scl);
	ns[2] = (int)rint((bnd[5]-bnd[4])/scl);

	if (verboseflg) {
		fprintf(stderr, "read parameters from: %s\n", fpar);

		fprintf(stderr, "specified bounding box: "
						"%.4f-%.4f, %.4f-%.4f, %.4f-%.4f\n"
						"sampling dimension: %dx%dx%d = %d voxels\n",
						bnd[0], bnd[1], bnd[2], bnd[3], bnd[4], bnd[5],
						ns[0], ns[1], ns[2], ns[0]*ns[1]*ns[2]);

	}

	// cone wall positions: ----------------------------------

	// shift in z-dir. corresponding to cone wall thickness:
	wdz = cwt/sin(coa*DEG2RAD);

	// shift in z-dir. corresponding to flap height:
	fhdz = fh/sin(coa*DEG2RAD);

	// outer wall cone position:
	vtkTransform *owcpos = vtkTransform::New();
	owcpos->RotateY(90);
	owcpos->Translate(0, 0, wdz);

	// inner wall cone position:
	vtkTransform *iwcpos = vtkTransform::New();
	iwcpos->RotateY(90);

	// cone walls & cutting planes: -----------------------

	// outer wall cone:
	vtkCone *owc = vtkCone::New();
	owc->SetAngle(coa);
	owc->SetTransform(owcpos);

	// inner wall cone:
	vtkCone *iwc = vtkCone::New();
	iwc->SetAngle(coa);
	iwc->SetTransform(iwcpos);

	// cone cutting plane:
	vtkPlane *pcut = vtkPlane::New();
	pcut->SetOrigin(0, 0, cpch);
	pcut->SetNormal(-sin(cpna*DEG2RAD),0,-cos(cpna*DEG2RAD));

	// put the pieces of the cone together: ------------------

	vtkImplicitBoolean *ibc = vtkImplicitBoolean::New();
	ibc->SetOperationTypeToDifference();
	ibc->AddFunction(owc);
	ibc->AddFunction(iwc);
	ibc->AddFunction(pcut);

	// canal: ------------------------------------------------

	// canal position:
	cnlhr = cnlh*tan(coa*DEG2RAD);
	cnlix = cnlhr*cos(cnla*DEG2RAD);
	cnliy = cnlhr*sin(cnla*DEG2RAD);

	// target canal axis vector:
	cavx = cos(cnla*DEG2RAD);
	cavy = sin(cnla*DEG2RAD);
	cavz = sin(coa*DEG2RAD);
	cavn = sqrt(cavx*cavx+cavy*cavy+cavz*cavz);
	// normalize:
	cavx /= cavn;
	cavy /= cavn;
	cavz /= cavn;

	// angle to rotate canal axis by:
	// (= angle between initial position 0,1,0 & target axis vec.)
	carotang = acos(cavy)*RAD2DEG;

	// rotation axis vector (normal to both cav & original cylinder axis)
	// for rotating cylinder axis vector into target canal axis vector
	// (original cylinder axis is 0,1,0)
	vtkTransform *cnlpos = vtkTransform::New();
	cnlpos->RotateWXYZ(carotang, -cavz, 0, cavx);
	cnlpos->Translate(cnlix, cnliy, -cnlh);

	vtkCylinder *icnl = vtkCylinder::New(); // inner canal wall
	icnl->SetCenter(0,0,0);
	icnl->SetRadius(0.5*cnld);
	icnl->SetTransform(cnlpos);

	vtkCylinder *ocnl = vtkCylinder::New(); // outer canal wall
	ocnl->SetCenter(0,0,0);
	ocnl->SetRadius(0.5*cnld+cwt);
	ocnl->SetTransform(cnlpos);

	// back terminating plane of canal volume:
	vtkPlane *pcbt = vtkPlane::New();
	pcbt->SetOrigin(-cnlix-cavx*cnll, -cnliy-cavy*cnll, cnlh-cavz*cnll);
	pcbt->SetNormal(cavx,cavy,cavz);

	// front terminating plane of canal volume:
	vtkPlane *pcft = vtkPlane::New();
	pcft->SetOrigin(-cnlix+cavx*10*scl, -cnliy+cavy*10*scl, cnlh+cavz*10*scl);
	pcft->SetNormal(-cavx,-cavy,-cavz);


	// inner canal wall & its limits
	vtkImplicitBoolean *ibicnl = vtkImplicitBoolean::New();
	ibicnl->SetOperationTypeToDifference();
	ibicnl->AddFunction(icnl);
	ibicnl->AddFunction(pcbt);
	ibicnl->AddFunction(pcft);
	ibicnl->AddFunction(iwc);
	ibicnl->AddFunction(pcut);

	// outer canal wall & its limits
	vtkImplicitBoolean *ibocnl = vtkImplicitBoolean::New();
	ibocnl->SetOperationTypeToDifference();
 	ibocnl->AddFunction(ocnl);
 	ibocnl->AddFunction(iwc);
	ibocnl->AddFunction(pcft);
	ibocnl->AddFunction(pcut);

	// flap: -------------------------------------------------

	// flap rim cone position:
	vtkTransform *frcpos = vtkTransform::New();
	frcpos->RotateY(90);
	frcpos->Translate(0, 0, -fhdz);

	// flap rim cone:
	vtkCone *frc = vtkCone::New();
	frc->SetAngle(coa);
	frc->SetTransform(frcpos);

	// lower flap cutting plane
	vtkPlane *lfcp = vtkPlane::New();
	lfcp->SetOrigin(0, 0, fpch-0.5*ft);
	lfcp->SetNormal(fpnx, fpny, fpnz);

	// upper flap cutting plane
	vtkPlane *ufcp = vtkPlane::New();
	ufcp->SetOrigin(0, 0, fpch+0.5*ft);
	ufcp->SetNormal(-fpnx, -fpny, -fpnz);

	// find the line from the origin of the "mean" flap cutting plane
	// (halfway between upper & lower cutting plane) to the center of
	// the flap (will be normal of frontal flap cutting plane):

	// 1st intersecting line:
	// (goes through origin of flap cutting plane & flap center)
	// (this is also the frontal cutting plane surface normal)
	v1[0] = fpnz*cos(fca*DEG2RAD);
	v1[1] = fpnz*sin(fca*DEG2RAD);
	v1[2] = -fpnx*cos(fca*DEG2RAD)+fpny*sin(fca*DEG2RAD);

	// 2nd intersecting line:
	// (runs on cone surface, goes through origin & flap center)
	v2[0] = cos(fca*DEG2RAD);
	v2[1] = sin(fca*DEG2RAD);
	v2[2] = 1/tan(coa*DEG2RAD);

	// cross product of direction vectors & its norm:
	cp12[0] = v1[1]*v2[2]-v1[2]*v2[1];
	cp12[1] = v1[2]*v2[0]-v1[0]*v2[2];
	cp12[2] = v1[0]*v2[1]-v1[1]*v2[0];

	cp12nrm2 = cp12[0]*cp12[0]+cp12[1]*cp12[1]+cp12[2]*cp12[2];

	// distance from origin of flap cutting plane to flap center
	ffd = (fpch*(v2[1]*cp12[0]-v2[0]*cp12[1])/cp12nrm2)-fd; // fd: flap depth

	// frontal flap cutting plane (depth):
	vtkPlane *ffcp = vtkPlane::New();
	ffcp->SetOrigin(ffd*v1[0],
									ffd*v1[1],
									fpch+ffd*v1[2]);
	ffcp->SetNormal(v1[0], v1[1], v1[2]);

	vtkImplicitBoolean *ibf = vtkImplicitBoolean::New();
	ibf->SetOperationTypeToDifference(); // Intersection
	ibf->AddFunction(iwc);
	ibf->AddFunction(frc);
	ibf->AddFunction(ffcp);
	ibf->AddFunction(lfcp);
	ibf->AddFunction(ufcp);

	// put all parts (cone, flap, canal) together: ---------

	vtkImplicitBoolean *iball = vtkImplicitBoolean::New();
	iball->SetOperationTypeToUnion();
	iball->AddFunction(ibc);
	iball->AddFunction(ibf);
	iball->AddFunction(ibocnl);

	// inner canal goes through all parts in the way:
	vtkImplicitBoolean *iballcnl = vtkImplicitBoolean::New();
	iballcnl->SetOperationTypeToDifference();
	iballcnl->AddFunction(iball);
	iballcnl->AddFunction(ibicnl);

	// sample shape  ------------

	vtkSampleFunction *smpl = vtkSampleFunction::New();
	smpl->SetImplicitFunction(iballcnl);
	smpl->SetSampleDimensions(ns[0], ns[1], ns[2]);
	smpl->SetModelBounds(bnd);
	smpl->ComputeNormalsOff();
	smpl->SetOutputScalarTypeToDouble();
	smpl->Update();

	vtkImageThreshold *thld = vtkImageThreshold::New();
	thld->SetInputConnection(smpl->GetOutputPort());
	thld->ThresholdByUpper(0);
	thld->SetInValue(255);
	thld->SetOutValue(0);
	thld->ReplaceInOn();
	thld->ReplaceOutOn();
	thld->SetOutputScalarTypeToUnsignedChar();
	thld->Update();

	// add source: ----------------------------------------

	sx = (int)rint((-cnlix-cavx*(cnll-2*scl)-bnd[0])/scl);
	sy = (int)rint((-cnliy-cavy*(cnll-2*scl)-bnd[2])/scl);
	sz = (int)rint((cnlh-cavz*(cnll-2*scl)-bnd[4])/scl);

	if ((sx<0)||(sx>=ns[0])||(sy<0)||(sy>=ns[1])||(sz<0)||(sz>=ns[2])) {
		fprintf(stderr, "source position (%d,%d,%d) out of bounds\n",
						sx, sy, sz);
		return(EXIT_FAILURE);
	}

	thld->GetOutput()->SetScalarComponentFromDouble(sx, sy, sz, 0, SCLR);

	if (verboseflg) {
		fprintf(stderr, "source position idx: %d, %d, %d\n", sx, sy, sz);
	}


	vtkImageToStructuredPoints *imtsp = vtkImageToStructuredPoints::New();
	imtsp->SetInputConnection(thld->GetOutputPort());

	imtsp->Update();

	// recenter bounding box:
	bnd[0] = -0.5*(bnd[1]-bnd[0]);
	bnd[1] = -bnd[0];

	bnd[2] = -0.5*(bnd[3]-bnd[2]);
	bnd[3] = -bnd[2];

	bnd[4] = -0.5*(bnd[5]-bnd[4]);
	bnd[5] = -bnd[4];

	imtsp->GetOutput()->SetOrigin(bnd[0], bnd[2], bnd[4]);

	imtsp->GetOutput()->GetBounds(bnd);

	if (verboseflg) {
		fprintf(stderr, "recentered bounding box: "
						"%.4f-%.4f, %.4f-%.4f, %.4f-%.4f\n",
						bnd[0], bnd[1], bnd[2], bnd[3], bnd[4], bnd[5]);
	}


	// write result to vsp-file: ------------

	vtkStructuredPointsWriter *vspwrt = vtkStructuredPointsWriter::New();
	vspwrt->SetInputConnection(imtsp->GetOutputPort());
	vspwrt->GetInput()->SetSpacing(scl, scl, scl);
	vspwrt->SetFileTypeToBinary();
	vspwrt->SetFileName(fout);
	vspwrt->Update();

	if (verboseflg) {
		fprintf(stderr, "writing to: %s\n", fout);
	}

	vspwrt->Write();

	if (plyflg|stlflg|vtkflg) { /* generate surface meshes */

		vtkMarchingCubes *mcube = vtkMarchingCubes::New();
		mcube->SetInputConnection(imtsp->GetOutputPort());
		mcube->ComputeScalarsOff();
		mcube->ComputeGradientsOff();
		mcube->ComputeNormalsOff();
		mcube->SetValue(0, 127);
		mcube->Update();

		vtkSmoothPolyDataFilter *smth = vtkSmoothPolyDataFilter::New();
		smth->SetInputConnection(mcube->GetOutputPort());
		smth->SetNumberOfIterations(100);
		smth->SetRelaxationFactor(0.04);
		smth->SetFeatureAngle(feature_angle);
		smth->FeatureEdgeSmoothingOff();
		smth->BoundarySmoothingOn();
		smth->SetConvergence(0);
		smth->Update();

		vtkDecimatePro *dcm = vtkDecimatePro::New();
		dcm->SetInputConnection(smth->GetOutputPort());
		dcm->PreserveTopologyOn();
		dcm->SplittingOff();
		dcm->BoundaryVertexDeletionOff();
		dcm->SetFeatureAngle(feature_angle);
		dcm->SetMaximumError(0.0002);
		dcm->SetTargetReduction(0.1);
		dcm->Update();

		vtkPolyDataNormals *nrml = vtkPolyDataNormals::New();
		nrml->SetInputConnection(dcm->GetOutputPort());
		nrml->SetFeatureAngle(feature_angle);
		nrml->Update();

		vtkStripper *strp = vtkStripper::New();
		strp->SetInputConnection(nrml->GetOutputPort());
		strp->Update();

		if (vtkflg) { /* write VTK file */

			// name of VTK-file (output):
			snprintf(dp, PATH_MAX, ".vtk");

			vtkPolyDataWriter *vtkwrt = vtkPolyDataWriter::New();
			vtkwrt->SetInputConnection(strp->GetOutputPort());
			vtkwrt->SetFileTypeToBinary();
			vtkwrt->SetFileName(fout);

			if (verboseflg) {
				fprintf(stderr, "writing polygon mesh to VTK-file: %s\n", fout);
			}

			vtkwrt->Write();

		} /* write VTK file */

		if (plyflg) { /* write PLY file */

			// name of PLY-file (output):
			snprintf(dp, PATH_MAX, ".ply");

			vtkPLYWriter *plywrt = vtkPLYWriter::New();
			plywrt->SetInputConnection(nrml->GetOutputPort());
			plywrt->SetFileTypeToBinary();
			plywrt->SetFileName(fout);

			if (verboseflg) {
				fprintf(stderr, "writing polygon mesh to PLY-file: %s\n", fout);
			}

			plywrt->Write();

		} /* write PLY file */

		if (stlflg) { /* write STL file */

			// name of STL-file (output):
			snprintf(dp, PATH_MAX, ".stl");

			vtkSTLWriter *stlwrt = vtkSTLWriter::New();
			stlwrt->SetInputConnection(nrml->GetOutputPort());
			stlwrt->SetFileTypeToBinary();
			stlwrt->SetFileName(fout);

			if (verboseflg) {
				fprintf(stderr, "writing polygon mesh to STL-file: %s\n", fout);
			}

			stlwrt->Write();

		} /* write STL file */

	} /* generate surface meshes */

	return(EXIT_SUCCESS);
} /* main */
