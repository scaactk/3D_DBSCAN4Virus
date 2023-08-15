//
// Created by scaactk on 8/14/2023.
//

#ifndef PCL_TEST_GIVE_COLOR_HPP
#define PCL_TEST_GIVE_COLOR_HPP

#include "PCL_TEST_HEADER.h"
#include <random>
#endif //PCL_TEST_GIVE_COLOR_HPP

bool single_color(MyPointCloud &cloud, const size_t queryID){
    std::random_device rd;
    std::mt19937 gen(rd()); // random engine
    std::uniform_int_distribution<int> dis(0,256); //define an uniform distribution
    uint8_t R = dis(gen);
    uint8_t G = dis(gen);
    uint8_t B = dis(gen);
    bool flag = false;
    for (size_t i=0; i < cloud.size(); i++){
        if (cloud.points[i].clusterID == queryID){
            flag = true;
//            cloud.points[i].r = R;
//            cloud.points[i].g = G;
//            cloud.points[i].b = B;
            cloud.points[i].r = 255;
            cloud.points[i].g = 255;
            cloud.points[i].b = 255;
        }
    }
    if (flag==false){
        return false;
    }
    return true;
}

void set_gray(MyPointCloud &cloud){
    for (size_t i=0; i<cloud.size(); i++){
        if(cloud.points[i].clusterID==-1){
            cloud.points[i].r = 50;
            cloud.points[i].g = 50;
            cloud.points[i].b = 50;
        }
    }
}

size_t give_color(MyPointCloud &cloud, int clusterNumber){
    size_t count = 0;
    for (size_t i=0; i<cloud.size(); i++){
        if(single_color(cloud, i+1)){
            count++;
        }
    }
    set_gray(cloud);
    return count;
}