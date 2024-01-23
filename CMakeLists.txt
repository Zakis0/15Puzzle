cmake_minimum_required(VERSION 3.27)
project(15Puzzle)

set(CMAKE_CXX_STANDARD 23)

add_executable(15Puzzle main.cpp
        libs/Color/Color.cpp
        libs/Error/error.cpp
        libs/PixelDigits/PixelDigits.cpp
        libs/Matrix/matrix.cpp
        GameController/Params/Constants.h
        GameController/Graphics/Graphics.cpp
        GameController/Graphics/Graphics.h
        GameController/GameField/GameField.cpp
        GameController/GameField/GameField.h
        libs/Coordinates/Coordinates.cpp
        libs/Coordinates/Coordinates.h
        GameController/GameController/GameController.cpp
        GameController/GameController/GameController.h
        libs/MyRandom/myRandom.cpp
        Options.h
        libs/MathHandler/MathHandler.cpp
        libs/MathHandler/MathHandler.h
        GameController/Params/ERRORS.h
        GameController/Menu/Menu.cpp
        GameController/Menu/Menu.h
        GameController/Shop/Shop.cpp
        GameController/Shop/Shop.h
        GameController/Player/Player.cpp
        GameController/Player/Player.h
)
