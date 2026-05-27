#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "gradiente_coniugato.hpp"



double condA(const Eigen::MatrixXd& A) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
    Eigen::VectorXd singularValuesA = svd.singularValues();
    return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main() {
    const double tol_det = 1.0e-15;
    unsigned int n = 50; 

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

    if (std::abs(B.determinant()) < tol_det) {
        std::cerr << "Matrice B singolare." << std::endl;
        return -1;
    }

    // A = B^T * B garantisce che A sia simmetrica definita positiva
    Eigen::MatrixXd A = B.transpose() * B;
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_ex;

    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);
    
    const unsigned int it_max = 10000;
    const double res_tol = 1.0e-12;
    unsigned int it = 0;

    std::cout.precision(2);
    std::cout << std::scientific << "Condizionamento Matrice A: " << condA(A) << "\n\n";

    
    Eigen::VectorXd x = gradiente_coniugato(A, b, x0, res_tol, it_max, it);

   
    Eigen::VectorXd res_finale = b - A * x;
    double res_norm_0 = (b - A * x0).norm();
    
    const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() : (x - x_ex).norm() / x_ex.norm();

    std::cout.precision(4);
    std::cout << "--- Risultati Gradiente Coniugato ---\n";
    std::cout << std::scientific << "Iterazioni usate : " << it << " / " << it_max << std::endl;
    std::cout << std::scientific << "Residuo relativo : " << res_finale.norm() / res_norm_0 << " (Tolleranza: " << res_tol << ")" << std::endl;
    std::cout << std::scientific << "Errore relativo  : " << err_rel << std::endl;

    return 0;
}