from conans import ConanFile, CMake

class ConsumerConan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "libhiq/0.1@hilborn/stable"
   generators = "cmake"
   default_options = "libhiq:shared=False"

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin") # From bin to bin
      self.copy("*.dylib*", dst="bin", src="lib") # From lib to bin
