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

void cCluster::AddOrganism(cOrganism* org)
{
    org->SetClusterID(_id); // Change cluster ID for organism
    m_organisms.push_back(org); // Add organism
}

void cCluster::RemoveOrganism(cOrganism* org)
{
    for(int i=0;i<m_organisms.size();i++){
        if(m_organisms[i]==org){
            RemoveOrgAt(i);
        }
    }
}

void cCluster::RemoveOrgAt(int idx)
{
    m_organisms[idx]->SetClusterID(-1); // Reset cluster id
    m_organisms.erase(m_organisms.begin()+idx);
}


