add_library(src
    XMLValidator.hpp XMLValidator.cpp
    FileReader.hpp FileReader.cpp
    Node.hpp Node.cpp
    Dir.hpp Dir.cpp
    File.hpp File.cpp
    ConstructTree.hpp ConstructTree.cpp
    Functions.hpp Functions.cpp
    Menu.hpp Menu.cpp
)
set_target_properties(src PROPERTIES LINKER_LANGUAGE CXX)