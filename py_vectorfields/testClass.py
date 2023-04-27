#%%
import numpy as np
import scipy
from build import py_vectorfields
import sys
import igl
import os
#%%
sys.path.append('../../')

#%%

shape_name = 'torus_mid_g1.off'
MESH_DIR ="./example_data/"
v,f = igl.read_triangle_mesh(os.path.join(MESH_DIR, shape_name))

#%%
A = py_vectorfields.doublearea(v,f)
#%%
N = py_vectorfields.per_face_normals(v,f)
print(N)

# %%
