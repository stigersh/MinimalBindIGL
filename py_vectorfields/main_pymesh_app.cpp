#include <Eigen/Cholesky>
#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/Sparse>

#include <iostream>
#include <string>
#include <igl/readOFF.h>
#include <igl/per_face_normals.h>

#define MESH_DIR "../example_data/"

int main(){
    std::string filenameinmeshdir = "torus_mid_g1.off";
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    igl::readOFF(std::string(MESH_DIR) + "/" + filenameinmeshdir, V, F);
    Eigen::MatrixXd fN;
    igl::per_face_normals(V, F, fN);
    std::cout << fN << std::endl;
    // MeshVFAppGenerator mappGen(V,F);

    // mappGen.preprocessMesh(true);
    // mappGen.grad_debug();
    // Eigen::SparseMatrix<double> G; Eigen::SparseMatrix<double>  coG;
    // Eigen::SparseMatrix<double> Cv; Eigen::SparseMatrix<double> Ce;
    // Eigen::SparseMatrix<double> Dv; Eigen::SparseMatrix<double> De;
    // Eigen::SparseMatrix<double> J; Eigen::SparseMatrix<double>  Mv;
    // Eigen::VectorXd Me; Eigen::VectorXd Mx;
    // calculate_basic_operators(V, F, G, coG, Cv,
    //                         Ce, Dv, De, J, Mv,
    //                         Me, Mx);

    return 0;
}