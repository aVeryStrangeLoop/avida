
## Adherence checks
1. `m_adherence` to cOrganism.cc/h
2. `Inst_EnableAdherence` to cHardwareCPU.cc/h
3. `Inst_DisableAdherence` to cHardwareCPU.cc/h
4. `EnableAdherence` to cOrganism.cc/h
5. `DisableAdherence` to cOrganism.cc/h

## cCluster
1. Added cCluster.h/cc skeleton (Contains a `std::vector<cOrganism*>`)
2. Added `GetClusterID()`, `SetClusterID()`, and `GetCluster()` to cOrganism.cc/h
3. Added `GetClusterID()`, `SetClusterID()`, and `GetCluster()` to cOrgInterface.cc/h
4. Added `GetClusterID()`, `SetClusterID()` and `GetCluster()` to cPopulationInterface.cc/h
5. Added `GetClusterID()`, `SetClusterID()` and `GetCluster()` to cTestCPUInterface.cc/h
5. Added `GetCluster()`, `GetNumClusters()` and {`std::vector<cCluster> clusters`} to cPopulation.cc/h
6. Added `AddOrganism()`,`RemoveOrganism()` and `RemoveOrgAt()` to cCluster.cc/h !!! Possible SEGFAULTS !!!


## TODO
- At every instruction execution for an organism, do CheckClustering:
    - If not in cluster, check if adhering
        - If no, do nothing
        - If yes, check faced neighbor and see if they're adhering and facing self
            - If yes, add self to faced neighbor's cluster OR create a new cluster if faced neighbor not in cluster
            - If no, do nothing
    - If in cluster, do nothing
- "breakout" instantaneously removes org from cluster.
- Offsprings are part of parent cluster when created.
- Add cluster_id printing to output .spop files
- Add intra-cluster message broadcasting
- Add intra-cluster resource sharing
