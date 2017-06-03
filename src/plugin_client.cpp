#include <boost/shared_ptr.hpp>

#include <pluginlib/class_loader.h>
#include "pluginlib_arrayutil/arrayutil_base.h"

int main()
{
  const double array[] = {1.7, 2.3, 3.2, 4.8};
  const int ARRAY_SIZE = 4;
  const std::vector<double> vec(array, array + ARRAY_SIZE);

  pluginlib::ClassLoader<arrayutil_base::ArrayUtil> arrayutil_loader("pluginlib_arrayutil", "arrayutil_base::ArrayUtil");

  try
  {
    boost::shared_ptr<arrayutil_base::ArrayUtil> sum = arrayutil_loader.createInstance("pluginlib_arrayutil/Sum");
    //add->get_numbers(10.0,10.0);
    sum->setArray(vec);
    double result = sum->operate();

    ROS_INFO("Sum: %.2f", result);
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  try
  {
    boost::shared_ptr<arrayutil_base::ArrayUtil> ave = arrayutil_loader.createInstance("pluginlib_arrayutil/Ave");
    //add->get_numbers(10.0,10.0);
    //ave->setArray(vec);
    ave->setArray(array, 4);
    double result = ave->operate();

    ROS_INFO("Ave: %.2f", result);
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  try
  {
    boost::shared_ptr<arrayutil_base::ArrayUtil> min = arrayutil_loader.createInstance("pluginlib_arrayutil/Min");
    //add->get_numbers(10.0,10.0);
    min->setArray(array, 4);
    double result = min->operate();

    ROS_INFO("Min: %.2f", result);
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  try
  {
    boost::shared_ptr<arrayutil_base::ArrayUtil> max = arrayutil_loader.createInstance("pluginlib_arrayutil/Max");
    //add->get_numbers(10.0,10.0);
    max->setArray(array, 4);
    double result = max->operate();

    ROS_INFO("Max: %.2f", result);
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  return 0;
}
