cmake_minimum_required(VERSION 3.21)
project(lab9_10)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab9_10 main.cpp Entities/Product.cpp Entities/Product.h Tests/Tests.cpp Tests/Tests.h Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Repos/Repo.h Repos/Repo.h Repos/Repo_file_money.h Repos/Repo_file_product.h Entities/Money.cpp Entities/Money.h utils.h Exceptions/PositionExceptions.cpp Exceptions/PositionExceptions.h Exceptions/NoProductException.cpp Exceptions/NoProductException.h Exceptions/ValutaExceptions.cpp Exceptions/ValutaExceptions.h Exceptions/InvalidPriceException.h Exceptions/InvalidPriceException.cpp Exceptions/InvalidCodeException.cpp Exceptions/InvalidCodeException.h Validations/ProductValidator.cpp Validations/ProductValidator.h Validations/ValutaValidator.cpp Validations/ValutaValidator.h Exceptions/NoRangeException.cpp Exceptions/NoRangeException.h)
