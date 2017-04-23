#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

namespace fs = boost::filesystem;

fs::path home_directory();


int main()
try
{
    const auto home = home_directory();
    const auto files = boost::make_iterator_range(
        fs::directory_iterator{home/".conan"/"data"}, {});
    std::cout << "Installed Conan libraries:" << std::endl;
    for (auto&& file : files)
        std::cout << "  " << file.path().string() << std::endl;
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}

fs::path home_directory()
{
    if (auto* const home = std::getenv("HOME"))
        return home;

    if (auto* const userprofile = std::getenv("USERPROFILE"))
        return userprofile;

    auto* const homedrive = std::getenv("HOMEDRIVE"); // C:
    auto* const homepath = std::getenv("HOMEPATH"); // \User\Name
    if (homedrive && homepath)
        return std::string(homedrive) + homepath;

    throw std::runtime_error("Could not find home directory");
}
