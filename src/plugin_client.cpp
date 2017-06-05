#include <boost/shared_ptr.hpp>

#include <pluginlib/class_loader.h>
#include <pluginlib_arrayutil/arrayutil_base.h>

namespace pluginlib_arrayutil_client
{
  const double ARRAY[] = {1.7, 2.3, 3.2, 4.8};
  const int ARRAY_SIZE = 4;
  const std::string PLUGIN_NAME[] = {
    "pluginlib_arrayutil/Sum", "pluginlib_arrayutil/Ave",
    "pluginlib_arrayutil/Min", "pluginlib_arrayutil/Max"
  };
  const int PLUGIN_SIZE = 4;

  class PluginlibArrayutilClient
  {
    typedef boost::shared_ptr<arrayutil_base::ArrayUtil> LoaderPtr;

    public:

    PluginlibArrayutilClient() :
      arrayutil_loader_("pluginlib_arrayutil", "arrayutil_base::ArrayUtil"),
      vec_(ARRAY, ARRAY + ARRAY_SIZE)
    { }

    void run()
    {
        loadAllPlugins();
        operateAllPlugins();
    }

    private:

    void loadAllPlugins()
    {
      // create plugin instances
      for(int i = 0; i < PLUGIN_SIZE; ++i)
        pluginInstances_.push_back(arrayutil_loader_.createInstance(PLUGIN_NAME[i]));

      // set array values for each plugin
      for (std::vector<LoaderPtr>::iterator it = pluginInstances_.begin(); it != pluginInstances_.end(); ++it)
        (*it)->setArray(vec_);
    }

    void operateAllPlugins()
    {
      for (std::vector<LoaderPtr>::iterator it = pluginInstances_.begin(); it != pluginInstances_.end(); ++it)
      {
        // compute index just for grabbing the current loaded plugin name
        int index = std::distance(pluginInstances_.begin(), it);

        // execute the operation according to the current loaded plugin (Sum, Ave, Min, Max)
        double result = (*it)->operate();
        ROS_INFO_STREAM(PLUGIN_NAME[index] << ": " << std::fixed << std::setprecision(2) << std::setw(5) << result);
      }
    }

    std::vector<double> vec_;
    pluginlib::ClassLoader<arrayutil_base::ArrayUtil> arrayutil_loader_;
    std::vector<LoaderPtr> pluginInstances_;
  };
}

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
