
## Adherence switch (tells if an organism is labile to clustering)
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
7. Added `cluster_id` printing to cPopulation.cc. Only printed when `CLUSTERING` is set to 1.
8. Added CLUSTERING option to avida.cfg. Read as `CLUSTERING` in cAvidaConfig.cc/h. 
9. Added python script to draw population saves (draw_from_spop.py and draw_series.py in source/utils/draw_clusters)
10. Added series_to_movie.ssh (requires ffmpeg) to convert series images to .mp4 movie
11. Added clustering condition to `SendMessage()` in cPopulationInterface.cc/h. Messages are now only sent within clusters!

## TODO
- COME UP WITH CLUSTERING ALGORITHM!
- Later : Add resource sharing(??)

