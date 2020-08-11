import numpy as np
import matplotlib.pyplot as plt
from matplotlib import colors

def GetCellData(file_path,w_x,w_y):

    grid = np.full((w_x,w_y),-2) # -1 is for non-cluster organisms, -2 for no organism occupying the cell 

    with open(file_path) as popsave:
        popsave.readline() # Skip first line
        
        # Make sure format contains cluster_id
        save_format = popsave.readline() 
        try:
            format_list = save_format.strip("\n").split()
            n_columns = len(format_list) - 1
            cls_id_col_idx = format_list.index("cluster_id") - 1
            cell_id_col_idx = format_list.index("cells") - 1
        except ValueError:
            print("ValueError: cluster_id/cells field not found in %s" % file_path)
            exit(0)
        
        for line in popsave:
            words = line.strip("\n").split()
            if line[0]!="\n" and line[0]!="#" and len(words)==n_columns:
                cell_ids = [int(w) for w in words[cell_id_col_idx].split(",")]
                cls_ids  = [int(w) for w in words[cls_id_col_idx].split(",")]
                for idx in range(len(cell_ids)):
                    x = cell_ids[idx] % w_x
                    y = cell_ids[idx] // w_x
                    cls_id = cls_ids[idx]
                    try:
                        grid[x,y] = cls_id
                    except:
                        print("Grid size provided possibly smaller than grid size in file. exiting")
                        exit(0)

    return grid

def get_cmap(n): # Ensures the same cluster_id is assigned the same color each time
    cmap = []
    cmap.append('k') # -2 gets black always (no organisms)
    cmap.append('w') # -1 gets white always (clusterless organism)
    cycled = ["b","g","r","c","m","y"]
    for i in range(n-2):
        cmap.append(cycled[i%6])
    cmap = colors.ListedColormap(cmap)
    return cmap

def DrawPopulation(file_path,w_x,w_y,out_img,update_num):
    data = GetCellData(file_path,w_x,w_y)
    n_clusters = np.max(data) + 1 # No. of clusters
    cmap = get_cmap(n_clusters+2) # Add two for no org and clusterless condition
    plt.imshow(data,cmap=cmap,vmin=-2,origin="lower")
    plt.title("Update: "+str(update_num))
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.savefig(out_img.split(".")[0]+".png",dpi=400)

if __name__ == "__main__":
    import sys
    if len(sys.argv)<5:
        print("Usage : python draw_from_spop.py <detail-.spop> <world_x> <world_y> <output_image_name>")
        exit(0)
    file_path = sys.argv[1]
    w_x = int(sys.argv[2])
    w_y = int(sys.argv[3])
    out_img = sys.argv[4]
    DrawPopulation(file_path,w_x,w_y,out_img,int(file_path.split("/")[-1].split(".")[0].split("-")[-1]))
