from draw_from_spop import *
import sys
import os

if __name__ == "__main__":
    if len(sys.argv) < 7:
        print("Usage: python draw_series.py <data_folder_path> <start_update> <step> <end_update> <world_x> <world_y>")
    data_folder = sys.argv[1]
    start = int(sys.argv[2])
    step = int(sys.argv[3])
    end = int(sys.argv[4])
    w_x = int(sys.argv[5])
    w_y = int(sys.argv[6])

    if not os.path.exists('output_series'):
        os.makedirs('output_series')
    
    for upd in range(start,end+1,step):
        print("Drawing population for update %d out of %d (%d/%d)" % (upd,end,((upd-start)/step) + 1,((end-start)/step) + 1))
        filename = data_folder.rstrip("/")+"/detail-"+str(upd)+".spop"
        outfile = "output_series/frame_"+str(((upd-start)/step)+1)+".png"
        DrawPopulation(filename,w_x,w_y,outfile,upd)

