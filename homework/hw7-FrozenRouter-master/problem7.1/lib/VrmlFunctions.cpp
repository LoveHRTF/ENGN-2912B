#include "VrmlFunctions.h"

void writeVrmlHeader(ofstream& ostr) {
	ostr << "#VRML V2.0 utf8\n" << endl;
}

void writeVrmlSphere (ofstream& ostr, sphere const& sp, float red, float green, float blue, float transparency) {
	ostr
	<< "Transform {" << endl
	<< "  translation " << endl
	<< sp.x0_ << ' ' << sp.y0_ << ' ' << sp.z0_ << endl
	<< "  scale " << endl
	<< sp.rad_ << ' ' << sp.rad_ << ' ' << sp.rad_ << endl
	<< "  children [" << endl
	<< "    Shape {" << endl
	<< "      appearance Appearance {" << endl
	<< "        material Material {" << endl
	<< "          diffuseColor " << red << ' ' << green << ' ' << blue << endl
	<< "          transparency " << transparency << endl
	<< "        }" << endl
	<< "      }" << endl
	<< "      geometry" << endl;

	writeVrmlIcosahedron(ostr,8);

	ostr
	<< "    }" << endl
	<< "  ]" << endl
	<< "}" << endl;
}

void writeVrmlIcosahedron(ofstream& ostr, unsigned nIndent) {
	// radius 1 icosahedron centered at the origin

	// static unsigned icoLength;
	// static char ico[][];
	// are defined in the included file

	//#include "ico12v.h"
	#include "ico162v.h"

	unsigned i,j;
	for(i=0;i<ICO_LENGTH;i++) {
		for(j=0;j<nIndent;j++) ostr << ' ';
		ostr << ico[i] << endl;
	}
}
