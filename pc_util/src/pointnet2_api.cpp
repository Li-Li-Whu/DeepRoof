#include <torch/serialize/tensor.h>
#include <torch/extension.h>

#include "ball_query_gpu.h"
#include "group_points_gpu.h"
#include "sampling_gpu.h"
#include "interpolate_gpu.h"
#include "cluster_gpu.h"


PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
    m.def("ball_query_wrapper", &ball_query_wrapper_fast, "ball_query_wrapper_fast");
    m.def("ball_center_query_wrapper", &ball_center_query_wrapper_fast, "ball_center_query_wrapper_fast");
    m.def("knn_query_wrapper", &knn_query_wrapper_fast, "knn_query_wrapper_fast");

    m.def("group_points_wrapper", &group_points_wrapper_fast, "group_points_wrapper_fast");
    m.def("group_points_grad_wrapper", &group_points_grad_wrapper_fast, "group_points_grad_wrapper_fast");

    m.def("gather_points_wrapper", &gather_points_wrapper_fast, "gather_points_wrapper_fast");
    m.def("gather_points_grad_wrapper", &gather_points_grad_wrapper_fast, "gather_points_grad_wrapper_fast");

    m.def("furthest_point_sampling_wrapper", &furthest_point_sampling_wrapper, "furthest_point_sampling_wrapper");
    
    m.def("three_nn_wrapper", &three_nn_wrapper_fast, "three_nn_wrapper_fast");
    m.def("three_interpolate_wrapper", &three_interpolate_wrapper_fast, "three_interpolate_wrapper_fast");
    m.def("three_interpolate_grad_wrapper", &three_interpolate_grad_wrapper_fast, "three_interpolate_grad_wrapper_fast");

    m.def("dbscan_wrapper", &dbscan_wrapper_fast, "dbscan_wrapper_fast");
    m.def("cluster_pts_wrapper", &cluster_pts_wrapper_fast, "cluster_pts_wrapper_fast");


    m.def("ball_query_wrapper_stack", &ball_query_wrapper_stack, "ball_query_wrapper_stack");

    m.def("group_points_wrapper_stack", &group_points_wrapper_stack, "group_points_wrapper_stack");
    m.def("group_points_grad_wrapper_stack", &group_points_grad_wrapper_stack, "group_points_grad_wrapper_stack");

    m.def("three_nn_wrapper_stack", &three_nn_wrapper_stack, "three_nn_wrapper_stack");
    m.def("three_interpolate_wrapper_stack", &three_interpolate_wrapper_stack, "three_interpolate_wrapper_stack");
    m.def("three_interpolate_grad_wrapper_stack", &three_interpolate_grad_wrapper_stack, "three_interpolate_grad_wrapper_stack");

}