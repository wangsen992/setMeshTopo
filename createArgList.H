argList::addNote
(
    "Block mesh generator (but with a surface file as bottom\n"
);

argList::noParallel();
argList::noFunctionObjects();

argList::addBoolOption
(
    "write-obj",
    "Write block edges and centres as obj files and exit"
);
argList::addOptionCompat("write-obj", {"blockTopology", 1912});

argList::addBoolOption
(
    "write-vtk",
    "Write topology as VTK file and exit"
);

argList::addBoolOption
(
    "merge-points",
    "Geometric (point) merging instead of topological merging "
    "(slower, fails with high-aspect cells. default for 1912 and earlier)",
    true  // mark as an advanced option
);
argList::addBoolOption
(
    "noClean",
    "Do not remove any existing polyMesh/ directory or files"
);
argList::addOption("dict", "file", "Alternative blockMeshDict");
argList::addBoolOption
(
    "sets",
    "Write cellZones as cellSets too (for processing purposes)"
);
argList::addOption
(
    "time",
    "time",
    "Specify a time to write mesh to (default: constant)"
);
argList::addOption
(
    "surface",
    "*.stl",
    "Specify the surface file to be used for bottom boundary"
);

#include "addRegionOption.H"
