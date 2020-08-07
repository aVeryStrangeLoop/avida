#include "cCluster.h"

/*! Constructor
 */

cCluster::cCluster()
    : _id(0)
{
}

cCluster::~cCluster()
{
}

void cCluster::Setup(int id,cWorld* world)
{
    _id = id;
    m_world = world;
}


