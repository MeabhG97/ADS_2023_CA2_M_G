add_library(src
    XMLValidator.hpp XMLValidator.cpp
    FileReader.hpp FileReader.cpp
)
set_target_properties(src PROPERTIES LINKER_LANGUAGE CXX)