
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;


#include <pcl/recognition/hv/greedy_verification.h>



template<typename ModelT, typename SceneT>
void defineRecognitionGreedyVerification(py::module &m, std::string const & suffix) {
    using Class = pcl::GreedyVerification<ModelT, SceneT>;
    py::class_<Class, pcl::HypothesisVerification<pcl::ModelT, pcl::SceneT>, boost::shared_ptr<Class>> cls(m, suffix.c_str());
    cls.def(py::init<float>(), "reg"_a=1.5f);
    cls.def("verify", &Class::verify);
        
}

void defineRecognitionGreedyVerificationFunctions(py::module &m) {
}

void defineRecognitionGreedyVerificationClasses(py::module &sub_module) {
}