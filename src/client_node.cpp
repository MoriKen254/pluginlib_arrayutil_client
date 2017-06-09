#include <pluginlib_arrayutil_client/pluginlib_arrayutil_client.h>

int main()
{
  try
  {
    pluginlib_arrayutil_client::PluginlibArrayutilClient client;
    client.run();
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR_STREAM("The plugin failed to load for some reason. Error: " << ex.what());
  }

  return 0;
}
