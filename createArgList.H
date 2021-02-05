argList::addNote
(
    "Block mesh generator (but with a surface file as bottom\n"
    "  The ordering of vertex and face labels within a block as shown "
    "below.\n"
    "  For the local vertex numbering in the sequence 0 to 7:\n"
    "    Faces 0, 1 (x-direction) are left, right.\n"
    "    Faces 2, 3 (y-direction) are front, back.\n"
    "    Faces 4, 5 (z-direction) are bottom, top.\n"
    "\n"
    "                        7 ---- 6\n"
    "                 f5     |\\     |\\     f3\n"
    "                 |      | 4 ---- 5     \\\n"
    "                 |      3 |--- 2 |      \\\n"
    "                 |       \\|     \\|      f2\n"
    "                 f4       0 ---- 1\n"
    "    Y  Z\n"
    "     \\ |                f0 ------ f1\n"
    "      \\|\n"
    "       O--- X\n"
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
