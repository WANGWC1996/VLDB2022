#ifndef HYPERPLANE_SET_H
#define HYPERPLANE_SET_H

#include "point_t.h"
#include "point_set.h"
#include "hyperplane.h"


class hyperplane_set
{
public:
    point_t* expDim; //the ordered dimension of the expected point
    std::vector<hyperplane*> hyperplanes;
    std::vector<point_t*> ext_pts;

    hyperplane_set();
    hyperplane_set(point_set* p_set);
    hyperplane_set(point_set* p_set, int t);
    hyperplane_set(point_set* p_set, double &volume);
    hyperplane_set(point_set* p_set, double *max, double *min);//constructor: initial some hyperplanes so that u[i]>=0
    hyperplane_set(point_set* pset, int index, int index1);
    hyperplane_set(point_set* p_set, point_t* exp, double RandRate);//constructor: initial some hyperplanes so that u[i]>=0
    ~hyperplane_set();

    //Prepare the file for computing the convex hull (the utility range R) via halfspace interaction
    void write(point_t* feasible_pt, char* filename);
    void write(point_set* pset, char* filename);
    void print();//print the information of the hyperplane set
    bool find_boundary(point_set *pset, int index, std::queue<int> &candPoint, std::vector<hyperplane*> &candHyper, std::vector<hyperplane_set*> &partitionSet);
    bool find_boundary(point_set *pset, int index);
    bool set_ext_pts();
    point_t* find_feasible();
    bool R_dominate(point_t *p1, point_t *p2);
    void nearestSkyline(point_set *pset);
    void nearestSkyband(point_set *pset, int k);
    int check_relation(hyperplane *h);//check the relation between the hyperplane and the hyperplane set
    point_t* average_point();
    point_t* findNearest(point_set *p_set);
    point_set* findPossibleNearestK(point_set *pset, int k);
    bool is_prune(point_set *pset, int index, std::vector<hyperplane_set*> &partitionSet);
    void findExpforVec(point_set *pset, int &index1, int &index2);
    void findMinMax(int indexDimenion, double &min, double &max);
    double findL1Dis(int dim);
    void findendPts(point_t* lowerPts, point_t *upperPts, int dimInex);
    point_t* findExePt(point_set *CPoint, int index);
    bool findRegion(point_set *origSet, point_set *pset, point_set *cPoint, std::vector<hyperplane_set*> &PartitionSet);
    void update_expDim();

    point_t* maxpt(point_t *p1, point_t *p2);
    point_t* minpt(point_t *p1, point_t *p2);
};


#endif //U_2_HYPERPLANE_SET_H
