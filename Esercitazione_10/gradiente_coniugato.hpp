#pragma once
#include <Eigen/Dense>

inline Eigen::VectorXd gradiente_coniugato(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, const Eigen::VectorXd& x0, double tol, unsigned int it_max, unsigned int& it_effettive) {
    Eigen::VectorXd x = x0;
    Eigen::VectorXd r = b - A * x;
    Eigen::VectorXd p = r;
    
    double res_norm_0 = r.norm();
    unsigned int k = 0;

    while (k < it_max && r.norm() > tol * res_norm_0) {
        Eigen::VectorXd Ap = A * p;
        double p_Ap = p.dot(Ap); 
        
        // Calcolo alpha_k
        double alpha = p.dot(r) / p_Ap;
        
        // Aggiornamento soluzione
        x = x + alpha * p;
        
        // Aggiornamento residuo
        Eigen::VectorXd r_new = b - A * x;
        
        // Calcolo beta_k
        double beta = p.dot(A * r_new) / p_Ap;
        
        // Calcolo nuova direzione p
        p = r_new - beta * p;
        
        r = r_new;
        k++;
    }
    
    it_effettive = k;
    return x;
}