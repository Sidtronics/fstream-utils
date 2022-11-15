
set(TESTS 
    readBlk 
    writeBlk)

foreach(TEST ${TESTS})
    add_executable(${TEST} ${TEST}.cpp)
    target_link_libraries(${TEST} txtblocks)
endforeach()


