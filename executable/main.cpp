//
// Created by rstol on 30/04/2022.
//

#include <iostream>
#include "simple_dl/simple_dl.h"
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor-io/ximage.hpp>


int main() {
    std::cout << "Hello World!" << std::endl;

    Test testObject = Test();
    testObject.test_function();

    std::cout << "Testing xtensor" << std::endl;
    xt::xarray<int> arr {1, 2, 3, 4, 5};
    xt::xarray<int> arr2 {1, 2, 3, 4, 5};
    std::cout << arr;

    std::cout << "Testing xtensor" << std::endl;
    auto arr3 = xt::load_image("../data/test.png");
    std::cout << arr2;

    return 0;
}