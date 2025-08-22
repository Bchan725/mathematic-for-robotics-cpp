#include <iostream>
#include <pcl/visualization/pcl_visualizer.h>
#include <Eigen/Dense>

pcl::PointXYZ create_vector(Eigen::Vector3f v)
{
  return pcl::PointXYZ(v.x(), v.y(), v.z());
}

int main(int argc, char* argv[])
{
  pcl::visualization::PCLVisualizer viewer("visualization");
  viewer.setBackgroundColor(255.0, 255.0, 255.0);
  viewer.setCameraPosition(0.0, 5.0, 10.0,  // camera x,y,z
                           0.0, 0.0, 0.0,   // focal point x,y,z
                           0.0, 1.0, 0.0    // up vector
  );
  viewer.addCoordinateSystem(1.0);

  pcl::PointXYZ origin_p(0.0, 0.0, 0.0);

  Eigen::Vector3f v1(1.0, 2.0, 3.0);
  Eigen::Vector3f v2(3.0, 2.0, 1.0);

  pcl::PointXYZ v1_end_p = create_vector(v1);
  pcl::PointXYZ v2_end_p = create_vector(v2);

  Eigen::Vector3f v3 = v1 + v2;
  pcl::PointXYZ v3_end_p = create_vector(v3);

  viewer.addArrow(v1_end_p, origin_p, 255.0, 0.0, 0.0, false, "v1");
  viewer.addArrow(v2_end_p, origin_p, 0.0, 255.0, 0.0, false, "v2");
  viewer.addArrow(v3_end_p, origin_p, 0.0, 0.0, 255.0, false, "v3");

  while (!viewer.wasStopped())
  {
    viewer.spinOnce();
  }
}