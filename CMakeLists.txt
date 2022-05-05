cmake_minimum_required(VERSION 3.21)
project(lab8_bun)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab8_bun main.cpp Domain/Expense.cpp Domain/Expense.h Repo/Repo.cpp Repo/Repo.h Tests/Tests.cpp Tests/Tests.h UI/UI.cpp UI/UI.h Service/Service.cpp Service/Service.h Menu/Menu.cpp Menu/Menu.h)
