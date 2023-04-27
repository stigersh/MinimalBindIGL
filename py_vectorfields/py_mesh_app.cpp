#include <Eigen/Cholesky>
#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/Sparse>

#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

// Don't forget this
// #include <pybind11/stl_bind.h>

#include <iostream>
#include <string>

#include <igl/doublearea.h>
#include <igl/per_face_normals.h>
#include <igl/per_vertex_normals.h>
// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(py_vectorfields, m) {
  m.doc() = "mesh vf solver and hierarchy generator";

  m.def(
      "per_face_normals",
      [](const Eigen::MatrixXd &V, const Eigen::MatrixXi &F) {
        Eigen::MatrixXd fN; 
        // Eigen::MatrixXd V(4, 3);
        // V << 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1;

        // Eigen::MatrixXi F(4, 3);
        // F << 0, 1, 2, 0, 1, 3, 0, 2, 3, 1, 2, 3;
        igl::per_face_normals(V, F, fN);
        return std::move(fN);
      },
      "per face normals");
  m.def(
      "doublearea",
      [](const Eigen::MatrixXd &V, const Eigen::MatrixXi &F) {
        Eigen::VectorXd dblA;
        igl::doublearea(V, F, dblA);
        return std::move(dblA);
      },
      "Compute double areas of mesh faces");
}
