// Remove old files, unless disabled
const bool removeOldFiles = !args.found("noClean");

// Default merge (topology), unless otherwise specified
blockMesh::mergeStrategy strategy(blockMesh::DEFAULT_MERGE);

if (args.found("merge-points"))
{
    strategy = blockMesh::MERGE_POINTS;
}

word regionName(polyMesh::defaultRegion);
word regionPath;

// Check if the region is specified otherwise mesh the default region
if (args.readIfPresent("region", regionName))
{
    Info<< nl << "Generating mesh for region " << regionName << endl;
    regionPath = regionName;
}


// Instance for resulting mesh
bool useTime = false;
word meshInstance(runTime.constant());

if
(
    args.readIfPresent("time", meshInstance)
 && runTime.constant() != meshInstance
)
{
    // Verify that the value is actually good
    scalar timeValue;

    useTime = readScalar(meshInstance, timeValue);
    if (!useTime)
    {
        FatalErrorInFunction
            << "Bad input value: " << meshInstance
            << "Should be a scalar or 'constant'"
            << nl << endl
            << exit(FatalError);
    }
}


// Locate appropriate blockMeshDict
#include "findBlockMeshDict.H"

blockMesh blocks(meshDict, regionName, strategy);

if (!blocks.valid())
{
    // Could/should be Fatal?

    WarningIn(args.executable())
        << "Did not generate any blocks. Stopping." << nl << endl;

    return 1;
}


bool quickExit = false;
