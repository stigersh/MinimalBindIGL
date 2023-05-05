#%%
import numpy as np
import scipy

import sys
import igl
import os
os.environ['KMP_DUPLICATE_LIB_OK'] = 'TRUE'
#%%
from build import py_vectorfields
sys.path.append('../../')

#%%

shape_name = "lock_input_tri_g3.obj"#'torus_mid_g1.off'
MESH_DIR ="./example_data/"
v,f = igl.read_triangle_mesh(os.path.join(MESH_DIR, shape_name))

#%%
A = py_vectorfields.doublearea(v,f)
#%%
N = py_vectorfields.per_face_normals(v,f)
print(N)

# %%
