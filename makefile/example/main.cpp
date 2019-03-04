#include <iostream>
#include <array>
#include <ilcplex/ilocplex.h>

using namespace std;

int main(int argc, char** argv) {

    // Data
    constexpr unsigned int n_items = 5;
    const array<int, n_items> weight = { 3, 6, 2, 6, 7 };
    const array<int, n_items> profit = { 10, 3, 7, 12, 1 };
    const unsigned int knapsack_capacity = 25;

    // Cplex model
    IloEnv env;
    IloModel model(env);
    IloExpr objective = IloExpr(env);
    IloExpr constraint = IloExpr(env);
    IloBoolVarArray x = IloBoolVarArray(env);
    for (unsigned int i = 0 ; i < 5 ; i+= 1) {
        x.add(IloBoolVar(env));
        objective += x[i] * profit[i];
        constraint += x[i] * weight[i];
    }
    model.add(IloMaximize(env, objective));
    model.add(constraint <= IloInt(knapsack_capacity));

    // Solve
    IloCplex cplex(model);
    cplex.solve();

    cout << "Status = " << cplex.getStatus() << endl;
    if (cplex.getStatus() == IloAlgorithm::Optimal)
        cout << "Objective value = " << cplex.getObjValue() << endl;

    env.end();
    
    return 0;
}
