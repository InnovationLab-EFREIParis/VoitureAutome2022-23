#include <iostream>
#include <vector>

int main() {
    std::vector<float> raw_lidar{3.,4.,5.,3.,3.,9.,9.,0.,8.,3.,9.,3.,2.,3.,6.,4.,9.,0.,3.,1.};
    
    int size_array = raw_lidar.size();

    float angular_resolution_deg = (1. * size_array)/360;
    
    float half_angle = 120.;
    
    int aperture = half_angle*angular_resolution_deg;
    
    // Sub vector of right lidar
    std::vector<float>::const_iterator right_first = raw_lidar.begin() + 0;
    std::vector<float>::const_iterator right_last = raw_lidar.begin() + (aperture+1);
    std::vector<float> lidar_right(right_first, right_last);
    
    // Sub vector of right lidar
    std::vector<float>::const_iterator left_first = raw_lidar.begin() + (size_array-aperture);
    std::vector<float>::const_iterator left_last = raw_lidar.end();
    std::vector<float> lidar_left(left_first, left_last);

    
    
    // std::cout << angular_resolution_deg << "\n";
    // std::cout << size_array << "\n";
    // std::cout << sizeof(raw_lidar) << "\n";
    // std::cout << aperture << "\n";
    
    // std::cout << "\n";
    // for (float i: raw_lidar)
    //     std::cout << i << ' ';
    // std::cout << "\n";
        
    // for (float i: lidar_left)
    //     std::cout << i << ' ';
    // std::cout << "\n";
        
    // for (float i: lidar_right)
    //     std::cout << i << ' ';
    
    // merging both lidar sub vector
    lidar_left.insert( lidar_left.end(), lidar_right.begin(), lidar_right.end() );
    std::vector<float> front_lidar = lidar_left;
    
    // std::cout << "\n";
    // for (float i: front_lidar)
    //     std::cout << i << ' ';
    
    // sub sample the resulting lidar depending on a 'step' parameter.
    std::vector<float> front_lidar_sampled = {};
    int cpt = 0;
    int step = 2; 
    for(float i : front_lidar){
        cpt = cpt + 1;
        if(cpt >= step){
            cpt = 0;
            front_lidar_sampled.push_back(i);}}
    

    // std::cout << "\n";
    // std::cout << front_lidar_sampled.size() << "\n";
    // std::cout << "\n";
    // for (float i: front_lidar_sampled)
    //     std::cout << i << ' ';
}