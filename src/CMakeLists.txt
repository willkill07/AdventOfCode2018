add_executable(Advent
  Advent.cpp)

target_compile_options(Advent PUBLIC ${CXX_TARGET_FLAGS})

target_link_libraries(Advent Threads::Threads range-v3)
