cmake_minimum_required(VERSION 3.10)
project(dk2maptool C)

# Опционально: явно укажем стандарт C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Перечисляем все ваши .c-файлы
set(SOURCES
    dk2mtool.c
    dk2mfile.c
    lbfileio.c
)

# Компиляция exe из этих файлов
add_executable(dk2maptool ${SOURCES} "lbfileio.h" "dk2mfile.h")
