#include "d_star_lite_planner.h"
#include "safety_utils.h"
#include <iostream>
int main() {
    PlanningProblem prob;
    prob.initialState = 0; prob.goalState = 3;
    prob.badStates = {4};
    prob.states = {
        State(0, {0.0, 0.0}), State(1, {2.0, 0.0}),
        State(2, {1.0, -5.0}), State(3, {4.0, 0.0}),
        State(4, {2.0, 0.2}), State(5, {3.0, -5.0}),
    };
    prob.transitions = {
        Transition(0, 0, 1, 1.0, 1.0, 0.50, true),
        Transition(1, 1, 3, 1.0, 1.0, 0.50, true),
        Transition(2, 0, 2, 2.0, 1.0, 0.99, true),
        Transition(3, 2, 5, 1.0, 1.0, 0.99, true),
        Transition(4, 5, 3, 1.0, 1.0, 0.99, true),
    };
    DStarLitePlanner planner;
    planner.setWeights(0.5, 0.0, 3.0);
    PlanningResult r = planner.plan(prob);
    std::cout << "Success: " << r.success << std::endl;
    std::cout << "Path: ";
    for (auto id : r.statePath) std::cout << id << " ";
    std::cout << std::endl;
    std::cout << "Cost: " << r.totalCost << std::endl;
    return 0;
}
