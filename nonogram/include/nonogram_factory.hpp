/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_INCLUDE_NONOGRAM_FACTORY_HPP_
#define NONOGRAM_GAME_NONOGRAM_INCLUDE_NONOGRAM_FACTORY_HPP_

#include <memory>
#include <vector>

#include "i_nonogram.hpp"

/**
 * @brief The purpose of the function is to create the nonogram object.
 */

std::shared_ptr<INonogram>
MakeNonogram(const std::vector<std::vector<uint8_t>> &row_numbers,
             const std::vector<std::vector<uint8_t>> &column_numbers);

#endif // NONOGRAM_GAME_NONOGRAM_INCLUDE_NONOGRAM_FACTORY_HPP_
