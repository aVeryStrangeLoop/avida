#ifndef cCluster_h
#define cCluster_h

#include <vector>

class cWorld;
class cOrganism;

class cCluster
{
private:
    cWorld* m_world;
    int _id;
    std::vector<cOrganism*> m_organisms;

public:
    cCluster();
    ~cCluster();

    void Setup(int id,cWorld* world=NULL);
    int GetID() const { return _id; }
    int GetSize() const { return m_organisms.size();}
    
};

#endif
